class Solution {
  public:
    int divide(int dividend, int divisor) {
      int flag = (dividend < 0) ^ (divisor < 0);
      long long p = abs((long long)dividend);
      long long q = abs((long long)divisor);
      int res = 0;
      long long x = q, y = 1;
      while (x) {
        if ((x << 1) <= p) {
          x <<= 1;
          y <<= 1;
        } else if (x > p) {
          x >>= 1;
          y >>= 1;
        } else {
          p -= x;
          res += y;
        }
      }
      return res * (!flag ? 1 : -1);
    }
};
