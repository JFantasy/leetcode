class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> res(1 << n, 0);
      for (int len = 4, mask = 1; len <= (1 << (n + 1)); len <<= 1, mask <<= 1) {
        for (int i = 0; i < (1 << n); i += len) {
          for (int j = len / 4; j < len / 4 * 3 && i + j < (1 << n); ++ j) {
            res[i + j] += mask;
          }
        }
      }
      return res;
    }
};
