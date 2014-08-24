class Solution {
  public:
    void dfs(vector<vector<int> > &res, vector<int> &current, vector<int> &candidates, int start, int target) {
      if (target == 0) res.push_back(current);
      else {
        for (int i = start; i < candidates.size(); ++ i) {
          if (candidates[i] > target) continue;
          if (start < i && candidates[i] == candidates[i - 1]) continue;
          current.push_back(candidates[i]);
          dfs(res, current, candidates, i + 1, target - candidates[i]);
          current.pop_back();
        }
      }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      vector<int> current;
      dfs(res, current, num, 0, target);
      return res;
    }
};
