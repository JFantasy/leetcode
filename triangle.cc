class Solution {
  public:
    int minimumTotal(vector<vector<int> > &triangle) {
      if (triangle.size() == 0) return 0;
      if (triangle.size() == 1) return triangle[0][0];
      int res;
      for (int i = 1; i < triangle.size(); ++ i) {
        for (int j = 0; j <= i; ++ j) {
          if (j == 0) triangle[i][j] += triangle[i - 1][j];
          else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
          else triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
          if (i == triangle.size() - 1) {
            res = !j ? triangle[i][j] : min(res, triangle[i][j]);
          }
        }
      }
      return res;
    }
};
