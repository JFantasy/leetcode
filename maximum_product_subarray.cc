class Solution {
  public:
    int maxProduct(int A[], int n) {
      int res = A[0];
      for (int i = 1; i < n; ++i) res = max(res, A[i]);
      for (int i = 0, negative = 0, op = 0, current = 1; i < n; ++i) {
        if (A[i] == 0) {
          negative = op = 0;
          current = 1;
        } else {
          op ^= (A[i] < 0);
          current *= abs(A[i]);
          if (op & 1) {
            if (negative == 0) negative = abs(current);
            else res = max(res, current / negative);
          } else res = max(res, current);
        }
      }
      return res;
    }
};
