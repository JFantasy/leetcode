class Solution {
  public:
    int firstMissingPositive(int A[], int n) {
      for (int i = 0; i < n; ++ i) {
        if (A[i] <= 0 || A[i] > n || A[i] == i + 1) continue;
        while (A[A[i] - 1] != A[i]) {
          swap(A[i], A[A[i] - 1]);
          if (A[i] <= 0 || A[i] > n) break;
        }
      }
      for (int i = 0; i < n; ++ i) {
        if (A[i] != i + 1) return i + 1;
      }
      return n + 1;
    }
};
