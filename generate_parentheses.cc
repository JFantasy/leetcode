class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      if (n == 0) return vector<string>({""});
      vector<string> res;
      for (int i = 0; i < n; ++i) {
        for (const auto &left : generateParenthesis(i)) {
          for (const auto &right : generateParenthesis(n - i - 1)) {
            res.push_back("(" + left + ")" + right);
          }
        }
      }
      return res;
    }
};

//---------

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
