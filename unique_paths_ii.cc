class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      int n = obstacleGrid.size(), m = obstacleGrid[0].size();
      vector<vector<int> > dp(n, vector<int>(m, 0));
      dp[0][0] = (obstacleGrid[0][0] == 0);
      for (int i = 1; i < n; ++ i) dp[i][0] = dp[i - 1][0] * (obstacleGrid[i][0] == 0);
      for (int i = 1; i < m; ++ i) dp[0][i] = dp[0][i - 1] * (obstacleGrid[0][i] == 0);
      for (int i = 1; i < n; ++ i) {
        for (int j = 1; j < m; ++ j) {
          dp[i][j] = (obstacleGrid[i][j] == 0) * (dp[i - 1][j] + dp[i][j - 1]);
        }
      }
      return dp[n - 1][m - 1];
    }
};
