class Solution {
  public:
    bool legal(int x, int y, const vector<vector<int> > &vis) {
      return (x >= 0 && x < vis.size() && y >= 0 && y < vis[x].size() && !vis[x][y]);
    }
    void getNext(int &x, int &y, int &z, const vector<vector<int> > &vis) {
      const int dx[4] = {0, 1, 0, -1};
      const int dy[4] = {1, 0, -1, 0};
      int tx = x + dx[z], ty = y + dy[z];
      if (!legal(tx, ty, vis)) {
        z = (z + 1) % 4;
        x += dx[z];
        y += dy[z];
      } else {
        x = tx;
        y = ty;
      }
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> res;
      if (matrix.size() == 0) return res;
      vector<vector<int> > vis(matrix.size(), vector<int>(matrix[0].size(), 0));
      int x = 0, y = 0, z = 0;
      for (int i = 0; i < matrix.size() * matrix[0].size(); ++ i) {
        res.push_back(matrix[x][y]);
        vis[x][y] = 1;
        getNext(x, y, z, vis);
      }
      return res;
    }
};
