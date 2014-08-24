class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      int l, r;
      for (l = 0, r = 0; r < n; ++ r) {
        if (r == 0 || A[r] != A[r - 1]) A[l ++] = A[r];
      }
      return l;
    }
};
