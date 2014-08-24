class Solution {
  public:
    void setZeroes(vector<vector<int> > &matrix) {
      for (int i = 0, last_flag = 0, current_flag = 0; i < matrix.size(); ++ i) {
        for (int j = 0; j < matrix[i].size(); ++ j) {
          current_flag |= (!matrix[i][j]);
          if (i > 0 && !matrix[i - 1][j]) matrix[i][j] = 0;
          if (i > 0 && !matrix[i][j] && matrix[i - 1][j]) {
            for (int h = 0; h < i; ++ h) {
              matrix[h][j] = 0;
            }
          }
        }
        if (i > 0 && last_flag) {
          for (int j = 0; j < matrix[i - 1].size(); ++ j) {
            matrix[i - 1][j] = 0;
          }
        }
        if (i < matrix.size() - 1) {
          last_flag = current_flag;
          current_flag = 0;
        } else if (current_flag) {
          for (int j = 0; j < matrix[i].size(); ++ j) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};
