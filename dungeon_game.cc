class Solution {
  public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
      const int n = dungeon.size(), m = dungeon[0].size();
      vector<vector<int> > cost(n, vector<int>(m)), dp(n, vector<int>(m));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i == 0 && j == 0) cost[i][j] = dungeon[i][j];
          else if (i == 0) cost[i][j] = cost[i][j - 1] + dungeon[i][j];
          else if (j == 0) cost[i][j] = cost[i - 1][j] + dungeon[i][j];
          else cost[i][j] = max(cost[i - 1][j], cost[i][j - 1]) + dungeon[i][j];
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i == 0 && j == 0) dp[i][j] = cost[i][j];
          else if (i == 0) dp[i][j] = min(dp[i][j - 1], cost[i][j]);
          else if (j == 0) dp[i][j] = min(dp[i - 1][j], cost[i][j]);
          else dp[i][j] = max(min(dp[i - 1][j], cost[i - 1][j] + dungeon[i][j]), min(dp[i][j - 1], cost[i][j - 1] + dungeon[i][j]));
        }
      }
      return max(0, -dp[n - 1][m - 1]) + 1;
    }
};
