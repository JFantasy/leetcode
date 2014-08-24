class Solution {
  public:
    bool search(int A[], int n, int target) {
      int low = 0, upp = n - 1;
      while (low <= upp) {
        int mid = (low + upp) >> 1;
        if (A[mid] == target) return true;
        if (A[low] < A[mid]) {
          if (A[low] <= target && target < A[mid]) upp = mid - 1;
          else low = mid + 1;
        } else if (A[mid] < A[upp]) {
          if (A[mid] < target && target <= A[upp]) low = mid + 1;
          else upp = mid - 1;
        } else {
          if (A[low] == A[mid]) ++ low;
          if (A[upp] == A[mid]) -- upp;
        }
      }
      return false;
    }
};
