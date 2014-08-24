class Solution {
  public:
    void rotate(vector<vector<int> > &matrix) {
      for (int i = 0; i < matrix.size(); ++ i) {
        for (int j = i; j < matrix[i].size() - i - 1; ++ j) {
          int x = i, y = j;
          for (int h = 0, val = matrix[i][j]; h < 4; ++ h) {
            int tx = y, ty = matrix.size() - x - 1, new_val = matrix[tx][ty];
            matrix[tx][ty] = val;
            val = new_val;
            x = tx;
            y = ty;
          }
        }
      }
    }
};
