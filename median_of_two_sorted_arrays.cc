class Solution {
  public:
    int find(int A[], int n, int B[], int m, int kth) {
      if (n > m) return find(B, m, A, n, kth);
      if (n == 0) return B[kth - 1];
      if (kth == 1) return min(A[0], B[0]);
      int mid_a = min(n, kth / 2), mid_b = kth - mid_a;
      if (A[mid_a - 1] < B[mid_b - 1]) return find(A + mid_a, n - mid_a, B, m, kth - mid_a);
      else if (A[mid_a - 1] > B[mid_b - 1]) return find(A, n, B + mid_b, m - mid_b, kth - mid_b);
      else return A[mid_a - 1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      if ((n + m) & 1) return find(A, m, B, n, (n + m) / 2 + 1);
      else return (find(A, m, B, n, (n + m) / 2) + find(A, m, B, n, (n + m) / 2 + 1)) * 0.5;
    }
};
