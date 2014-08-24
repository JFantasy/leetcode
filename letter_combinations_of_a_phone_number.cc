class Solution {
  public:
    void dfs(int dep, string &digits, vector<string> &res, string current) {
      const char* letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      if (dep == digits.length()) res.push_back(current);
      else {
        int val = digits[dep] - '0';
        for (int i = 0; i < strlen(letter[val]); ++ i) {
          string next = current + letter[val][i];
          dfs(dep + 1, digits, res, next);
        }
      }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      dfs(0, digits, res, "");
      return res;
    }
};
