class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
      int l, r;
      for (l = 0, r = n - 1; l <= r; ++ l) {
        while (A[r] == elem && l <= r) -- r;
        if (l >= r) break;
        if (A[l] == elem) swap(A[l], A[r]);
      }
      return r + 1;
    }
};
