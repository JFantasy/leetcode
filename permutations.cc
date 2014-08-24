class Solution {
  public:
    void dfs(vector<vector<int> > &res, vector<int> &current, int dep, vector<int> &num, vector<int> &use) {
      if (dep == num.size()) res.push_back(current);
      else {
        for (int i = 0; i < num.size(); ++ i) {
          if (use[i]) continue;
          use[i] = 1;
          current.push_back(num[i]);
          dfs(res, current, dep + 1, num, use);
          current.pop_back();
          use[i] = 0;
        }
      }
    }
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > res;
      vector<int> current;
      vector<int> use(num.size(), 0);
      dfs(res, current, 0, num, use);
      return res;
    }
};
