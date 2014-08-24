class Solution {
  public:
    vector<vector<int> > generateMatrix(int n) {
      const int dx[4] = {0, 1, 0, -1};
      const int dy[4] = {1, 0, -1, 0};
      vector<vector<int> > res(n, vector<int>(n, 0));
      int x = 0, y = 0, z = 0;
      for (int i = 0; i < n * n; ++ i) {
        res[x][y] = i + 1;
        int tx = x + dx[z], ty = y + dy[z];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && !res[tx][ty]) {
          x = tx;
          y = ty;
        } else {
          (z += 1) %= 4;
          x += dx[z];
          y += dy[z];
        }
      }
      return res;
    }
};
