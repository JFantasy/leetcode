class Solution {
  public:
    int numTrees(int n) {
      if (n == 0) return 0;
      vector<int> arr(n);
      for (int i = 0; i < n; ++ i) arr[i] = n + i + 1;
      for (int i = 2; i <= n + 1; ++ i) {
        int x = i;
        for (int j = 0; j < n && x > 1; ++ j) {
          int d = __gcd(x, arr[j]);
          x /= d;
          arr[j] /= d;
        }
      }
      int res = 1;
      for (int i = 0; i < n; ++ i) res *= arr[i];
      return res;
    }
};
