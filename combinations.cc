class Solution {
  public:
    void dfs(vector<vector<int> > &res, vector<int> &current, int dep, int start, int n, int k) {
      if (dep == k) res.push_back(current);
      else {
        for (int i = start; i < n; ++ i) {
          current.push_back(i + 1);
          dfs(res, current, dep + 1, i + 1, n, k);
          current.pop_back();
        }
      }
    }
    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > res;
      vector<int> current;
      dfs(res, current, 0, 0, n, k);
      return res;
    }
};
