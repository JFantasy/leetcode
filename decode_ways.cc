class Solution {
  public:
    int numDecodings(string s) {
      if (s.length() < 1) return 0;
      vector<int> f(s.length() + 1);
      f[0] = 1;
      f[1] = (s[0] > '0');
      for (int i = 2; i <= s.length(); ++ i) {
        int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        f[i] = f[i - 1] * (s[i - 1] > '0') + f[i - 2] * (val >= 10 && val <= 26);
      }
      return f[s.length()];
    }
};
