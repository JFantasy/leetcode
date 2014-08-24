class Solution {
  public:
    int maxSubArray(int A[], int n) {
      int res = A[0];
      for (int last = A[0], i = 1; i < n; ++ i) {
        last = max(last, 0) + A[i];
        res = max(last, res);
      }
      return res;
    }
};
