class Solution {
  public:
    void dfs(vector<string> &res, string current, int dep, int length, int total) {
      if (total < 0) return;
      if (dep == length) {
        if (total == 0) res.push_back(current);
        return;
      } else {
        dfs(res, current + '(', dep + 1, length, total + 1);
        dfs(res, current + ')', dep + 1, length, total - 1);
      }
    }
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      dfs(res, "", 0, n * 2, 0);
      return res;
    }
};
