class Solution {
  public:
    int jump(int A[], int n) {
      if (n <= 1) return 0;
      if (A[0] >= n - 1) return 1;
      for (int i = 1, current = 1, cur_range = A[0], next_range = A[0]; i < n; ++ i) {
        if (i > cur_range) {
          cur_range = next_range;
          ++ current;
        }
        next_range = max(next_range, i + A[i]);
        if (next_range >= n - 1) return current + 1;
      }
      return 0;
    }
};
