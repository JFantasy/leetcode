class Solution {
  public:
    void dfs(int dep, int size, vector<string> &current, vector<vector<string> > &res, vector<int> &row, vector<int> &dig, vector<int> &back) {
      if (dep == size) res.push_back(current);
      else {
        for (int i = 0; i < size; ++ i) {
          if (row[i] || dig[dep + i] || back[dep - i + size - 1]) continue;
          string str(size, '.');
          str[i] = 'Q';
          current.push_back(str);
          row[i] = dig[dep + i] = back[dep - i + size - 1] = 1;
          dfs(dep + 1, size, current, res, row, dig, back);
          row[i] = dig[dep + i] = back[dep - i + size - 1] = 0;
          current.pop_back();
        }
      }
    }
    vector<vector<string> > solveNQueens(int n) {
      vector<vector<string> > res;
      vector<string> current;
      vector<int> row(n), dig(n + n - 1), back(n + n - 1);
      dfs(0, n, current, res, row, dig, back);
      return res;
    }
};
