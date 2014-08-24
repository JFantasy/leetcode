class Solution {
  public:
    int trap(int A[], int n) {
      vector<int> ls(n, 0), rs(n, 0);
      for (int i = 0; i < n; ++ i) {
        ls[i] = !i ? 0 : max(ls[i - 1], A[i - 1]);
      }
      for (int i = n - 1; i >= 0; -- i) {
        rs[i] = i == n - 1 ? 0 : max(rs[i + 1], A[i + 1]);
      }
      int res = 0;
      for (int i = 0; i < n; ++ i) res += max(0, min(ls[i], rs[i]) - A[i]);
      return res;
    }
};
