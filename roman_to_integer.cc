class Solution {
  public:
    int findpos(const char *str, char ch) {
      for (int i = 0; i < strlen(str); ++ i) {
        if (ch == str[i]) return i;
      }
      return -1;
    }
    int romanToInt(string s) {
      const char *letters = "IVXLCDM";
      const int num[] = {1, 5, 10, 50, 100, 500, 1000};
      int res = 0;
      for (int i = 0; i < s.length(); ++ i) {
        bool find = 0;
        int val = num[findpos(letters, s[i])];
        for (int j = i + 1; j < s.length() && !find; ++ j) {
          find |= val < num[findpos(letters, s[j])];
        }
        if (find) res -= val;
        else res += val;
      }
      return res;
    }
};
