class Solution {
  public:
    int reverse(int x) {
      int flag = x < 0, res = 0;
      for (x = abs(x); x; x /= 10) res = res * 10 + x % 10;
      return flag ? -res : res;
    }
};
