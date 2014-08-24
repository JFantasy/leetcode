class Solution {
  public:
    int find(int A[], int target, int lower, int upper) {
      int res = -1;
      while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        if (A[mid] == target) return mid;
        if (A[mid] < target) lower = mid + 1;
        else upper = mid - 1;
      }
      return res;
    }
    int findStart(int A[], int n) {
      int res = 0, lower = 0, upper = n - 1;
      while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        if (A[mid] <= A[n - 1]) {
          res = mid;
          upper = mid - 1;
        } else lower = mid + 1;
      }
      return res;
    }
    int search(int A[], int n, int target) {
      int start = findStart(A, n);
      if (start == 0) return find(A, target, 0, n - 1);
      else {
        int res = find(A, target, 0, start - 1);
        return res == -1 ? find(A, target, start, n - 1) : res;
      }
    }
};
