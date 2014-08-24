class Solution {
  public:
    void merge(int A[], int m, int B[], int n) {
      for (int ap = m - 1, bp = n - 1, index = m + n - 1; index >= 0; -- index) {
        if (ap < 0) A[index] = B[bp --];
        else if (bp < 0) A[index] = A[ap --];
        else if (A[ap] > B[bp]) A[index] = A[ap --];
        else A[index] = B[bp --];
      }
    }
};
