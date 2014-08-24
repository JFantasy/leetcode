class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
      int low = 0, upp = n - 1, res = 0;
      while (low <= upp) {
        int mid = (low + upp) >> 1;
        if (target >= A[mid]) {
          res = mid;
          low = mid + 1;
        } else upp = mid - 1;
      }
      return res + (target > A[res]);
    }
};
