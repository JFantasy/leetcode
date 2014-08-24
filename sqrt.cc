class Solution {
  public:
    int sqrt(int x) {
      if (x == 0) return 0;
      int res = 0, lower = 1, upper = x;
      while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        if (x / mid >= mid) {
          lower = mid + 1;
          res = mid;
        } else upper = mid - 1;
      }
      return res;
    }
};
