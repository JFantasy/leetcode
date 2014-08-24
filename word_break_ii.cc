class Solution {
  public:
    vector<string> dfs(int start, string &str, map<int, vector<string> > &ans, unordered_set<string> &dict) {
      if (ans.find(start) != ans.end()) return ans[start];
      vector<string> res;
      string current = "";
      for (int i = start; i < str.length(); ++ i) {
        current += str[i];
        if (dict.find(current) == dict.end()) continue;
        if (i < str.length() - 1) {
          vector<string> suffix = dfs(i + 1, str, ans, dict);
          for (int j = 0; j < suffix.size(); ++ j) {
            res.push_back(current + " " + suffix[j]);
          }
        } else res.push_back(current);
      }
      ans[start] = res;
      return res;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      map<int, vector<string> > res;
      return dfs(0, s, res, dict);
    }
};
