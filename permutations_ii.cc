class Solution {
  public:
    void dfs(int dep, int length, map<int, int> &tot, vector<int> &current, vector<vector<int> > &res) {
      if (dep == length) {
        res.push_back(current);
        return;
      }
      for (auto iter = tot.begin(); iter != tot.end(); ++ iter) {
        if (iter->second == 0) continue;
        -- tot[iter->first];
        current.push_back(iter->first);
        dfs(dep + 1, length, tot, current, res);
        current.pop_back();
        ++ tot[iter->first];
      }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
      map<int, int> tot;
      for (int i = 0; i < num.size(); ++ i) ++ tot[num[i]];
      vector<vector<int> > res;
      vector<int> current;
      dfs(0, num.size(), tot, current, res);
      return res;
    }
};
