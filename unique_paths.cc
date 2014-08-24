class Solution {
  public:
    void process(vector<int> &res, int x) {
      for (int i = 2; i <= x; ++ i) {
        int current = i;
        for (int j = 0; j < res.size() && current > 1; ++ j) {
          int d = __gcd(current, res[j]);
          res[j] /= d;
          current /= d;
        }
      }
    }
    int uniquePaths(int m, int n) {
      if (m == 0 || n == 0) return 0;
      if (m == 1 || n == 1) return 1;
      vector<int> res(m + n - 2, 0);
      for (int i = 0; i < m + n - 2; ++ i) res[i] = i + 1;
      process(res, n - 1);
      process(res, m - 1);
      int ans = 1;
      for (int i = 0; i < m + n - 2; ++ i) ans *= res[i];
      return ans;
    }
};
