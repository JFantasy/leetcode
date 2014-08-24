class Solution {
  public:
    double pow(double x, int n) {
      if (n == 0) return 1.0;
      double t = pow(x, n / 2);
      return n & 1 ? t * t * (n > 0 ? x : 1.0 / x) : t * t;
    }
};
