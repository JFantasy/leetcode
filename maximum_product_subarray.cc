class Solution {
  public:
    int maxProduct(int A[], int n) {
      int res = A[0];
      for (int i = 1; i < n; ++i) res = max(res, A[i]);
      for (int i = 0, negative = 0, current = 1; i < n; ++i) {
        if (A[i] == 0) {
          negative = 0;
          current = 1;
        } else {
          current *= A[i];
          if (current < 0) {
            if (negative == 0) negative = current;
            else res = max(res, current / negative);
          } else res = max(res, current);
        }
      }
      return res;
    }
};
