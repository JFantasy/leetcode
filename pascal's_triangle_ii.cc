class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      ++ rowIndex;
      vector<vector<int> > res(2);
      int col = 0;
      for (int i = 0; i < rowIndex; ++ i) {
        res[col ^ 1] = vector<int>(i + 1, 1);
        for (int j = 1; j < i; ++ j) res[col ^ 1][j] = res[col][j - 1] + res[col][j];
        col ^= 1;
      }
      return res[col];
    }
};
