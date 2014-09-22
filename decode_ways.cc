class Solution {
  public:
    int numDecodings(string s) const {
      if (s.empty()) return 0;
      vector<int> f(s.length() + 1);
      f[0] = 1;
      f[1] = (s[0] > '0');
      for (int i = 2; i < f.length(); ++ i) {  // i < f.length()
        int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        f[i] = f[i - 1] * (s[i - 1] > '0') + f[i - 2] * (val >= 10 && val <= 26);
      }
      return f[f.length() - 1];
    }
};
