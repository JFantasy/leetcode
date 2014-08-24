class Solution {
  public:
    bool match(char l, char r) {
      if (r == '.') return true;
      else return l == r;
    }
    bool isMatch(const char *s, const char *p) {
      int n = strlen(s), m = strlen(p);
      vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
      dp[0][0] = 1;
      for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= m; ++ j) {
          if (!dp[i][j]) continue;
          if (j < m - 1 && p[j + 1] == '*') {
            dp[i][j + 2] = 1;
            for (int h = 0; i + h + 1 <= n; ++ h) {
              if (match(s[i + h], p[j])) dp[i + h + 1][j + 2] = 1;
              else break;
            }
          } else if (i < n && j < m) dp[i + 1][j + 1] |= match(s[i], p[j]);
        }
      }
      return dp[n][m];
    }
};
