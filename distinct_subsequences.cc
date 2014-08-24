class Solution {
  public:
    int numDistinct(string S, string T) {
      if (!S.length() || !T.length()) return 0;
      vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1, 0));
      dp[0][0] = 1;
      for (int i = 0; i < S.length(); ++ i) {
        for (int j = 0; j < T.length(); ++ j) {
          if (!dp[i][j]) continue; 
          dp[i + 1][j] += dp[i][j];
          if (S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j];
        }
      }
      int res = 0;
      for (int i = 0; i <= S.length(); ++ i) res += dp[i][T.length()];
      return res;
    }
};
