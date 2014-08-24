class Solution {
  public:
    void dfs(vector<vector<int> > &res, vector<int> &current, vector<int> &candidates, int start, int target) {
      if (target == 0) res.push_back(current);
      else {
        for (int i = start; i < candidates.size(); ++ i) {
          if (candidates[i] > target) continue;
          current.push_back(candidates[i]);
          dfs(res, current, candidates, i, target - candidates[i]);
          current.pop_back();
        }
      }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int> > res;
      vector<int> current;
      dfs(res, current, candidates, 0, target);
      return res;
    }
};
