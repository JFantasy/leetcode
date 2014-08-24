class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      int l, r, k;
      for (l = 0, r = 0, k = 0; r < n; ++ r) {
        if (l > 0 && A[l - 1] == A[r] && k == 2) continue;
        if (l == 0 || A[l - 1] != A[r]) k = 1;
        else ++ k;
        A[l ++] = A[r];
      }
      return l;
    }
};
