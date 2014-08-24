class Solution {
  public:
    void getRange(const char *str, int &l, int &r) {
      int len = strlen(str);
      while (l < len && str[l] == ' ') ++ l;
      if (l < len) {
        r = l;
        while (r + 1 < len && str[r + 1] >= '0' && str[r + 1] <= '9') ++ r;
      } else l = r = -1;
    }
    int process(const char *str, int l, int r) {
      if (l < 0) return 0;
      if (str[l] != '+' && str[l] != '-' && (str[l] < '0' || str[l] > '9')) return 0;
      const int kIntMax = 2147483647;
      const int kIntMin = -2147483648;
      long long res = 0;
      for (int i = l; i <= r; ++ i) {
        if (str[i] == '+' || str[i] == '-') continue;
        res = res * 10 + str[i] - '0';
        if (str[l] == '-' && -res < kIntMin) return kIntMin;
        if (str[l] != '-' && res > kIntMax) return kIntMax;
      }
      return str[l] == '-' ? -res : res;
    }
    int atoi(const char *str) {
      int l = 0, r = 0;
      getRange(str, l, r);
      return process(str, l, r);
    }
};
