class Solution {
  public:
    int dfs(int dep, int size, vector<int> &row, vector<int> &dig, vector<int> &back) {
      if (dep == size) return 1;
      int res = 0;
      for (int i = 0; i < size; ++ i) {
        if (row[i]) continue;
        if (dig[dep + i]) continue;
        if (back[dep - i + size - 1]) continue;
        row[i] = dig[dep + i] = back[dep - i + size - 1] = 1;
        res += dfs(dep + 1, size, row, dig, back);
        row[i] = dig[dep + i] = back[dep - i + size - 1] = 0;
      }
      return res;
    }
    int totalNQueens(int n) {
      if (n == 0) return 0;
      vector<int> row(n), dig(n + n - 1), back(n + n - 1);
      return dfs(0, n, row, dig, back);
    }
};
