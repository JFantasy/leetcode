class Solution {
  public:
    int climbStairs(int n) {
      if (n < 3) return n;
      int a, b, i;
      for (a = 1, b = 2, i = 3; i <= n; ++ i) {
        int c = a + b;
        a = b;
        b = c;
      }
      return b;
    }
};
