class Solution {
  public:
    vector<string> getStringVector(const char *p) {
      int len = strlen(p);
      vector<string> res;
      for (int i = 0; i < len; ++ i) {
        if (p[i] == '*') {
          if (i > 0 && p[i - 1] == '*') continue;
          else res.push_back("*");
        } else {
          int j;
          string item;
          for (j = i; j < len && p[j] != '*'; ++ j) {
            item += p[j];
          }
          i = j - 1;
          res.push_back(item);
        }
      }
      return res;
    }
    bool process(string &s_str, vector<string> &p_str, int x, int y, int z, vector<vector<int> > &ans) {
      if (x == s_str.length() && y == p_str.size()) return true;
      if (x > s_str.length() || y == p_str.size()) return false;
      if (s_str.length() - x < z) return false;
      if (ans[x][y] >= 0) return ans[x][y];
      int &res = ans[x][y];
      if (p_str[y] == "*") {
        res = false;
        for (int i = 0; x + i <= s_str.length() && !res; ++ i) {
          res |= process(s_str, p_str, x + i, y + 1, z, ans);
        }
      } else {
        res = true;
        for (int i = 0; i < p_str[y].length() && res; ++ i) {
          if (x + i >= s_str.length()) res = false;
          else if (p_str[y][i] != '?' && s_str[x + i] != p_str[y][i]) res = false;
        }
        if (res) res &= process(s_str, p_str, x + p_str[y].length(), y + 1, z - p_str[y].length(), ans);
      }
      return res;
    }
    bool isMatch(const char *s, const char *p) {
      vector<string> p_str = getStringVector(p);
      string s_str(s);
      vector<vector<int> > ans = vector<vector<int> >(s_str.length() + 1, vector<int>(p_str.size() + 1, -1));
      int sum = 0;
      for (int i = 0; i < p_str.size(); ++ i) {
        if (p_str[i] == "*") continue;
        sum += p_str[i].length();
      }
      return process(s_str, p_str, 0, 0, sum, ans);
    }
};
