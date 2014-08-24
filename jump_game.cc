class Solution {
  public:
    bool canJump(int A[], int n) {
      int res = 0;
      for (int i = 0; i <= res; ++ i) res = min(n - 1, max(res, A[i] + i));
      return res == n - 1;
    }
};
