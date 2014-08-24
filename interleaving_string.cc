class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      if (s1.length() + s2.length() != s3.length()) return false;
      if (s1 == "") return s2 == s3;
      if (s2 == "") return s1 == s3;
      vector<vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
      dp[0][0] = 1;
      for (int i = 0; i <= s1.length(); ++ i) {
        for (int j = 0; j <= s2.length(); ++ j) {
          if (!dp[i][j]) continue;
          if (i < s1.length() && s1[i] == s3[i + j]) dp[i + 1][j] = true;
          if (j < s2.length() && s2[j] == s3[i + j]) dp[i][j + 1] = true;
        }
      }
      return dp[s1.length()][s2.length()];
    }
};
