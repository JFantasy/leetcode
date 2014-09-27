class Solution {
  public:
    bool isScramble(string s1, string s2) {
      if (s1.length() != s2.length()) return false;
      const int n = s1.length();
      vector<vector<vector<int> > > f(n + 1, vector<vector<int> >(n, vector<int>(n, 0)));
      for (int i = 1; i <= n; ++i) {
        for (int x = 0; x + i <= n; ++x) {
          for (int y = 0; y + i <= n; ++y) {
            if (i == 1) f[i][x][y] = (s1[x] == s2[y]);
            else {
              for (int k = 1; k < i && !f[i][x][y]; ++k) {
                f[i][x][y] |= ((f[k][x][y] && f[i - k][x + k][y + k]) ||
                    (f[k][x][y + i - k] && f[i - k][x + k][y]));
              }
            }
          }
        }
      }
      return f[n][0][0];
    }
};

//---------

class Solution {
  public:
    bool process(int len, int p1, int p2, const string &s1, const string &s2, map<pair<int, pair<int, int> >, bool> &res) {
      if (res.find(make_pair(len, make_pair(p1, p2))) != res.end()) return res[make_pair(len, make_pair(p1, p2))];
      bool &check = res[make_pair(len, make_pair(p1, p2))];
      check = false;
      if (s1.substr(p1, len) == s2.substr(p2, len)) return (check = true);
      for (int i = 1; i < len && !check; ++ i) {
        check |= (process(i, p1, p2 + len - i, s1, s2, res) && process(len - i, p1 + i, p2, s1, s2, res));
        check |= (process(i, p1, p2, s1, s2, res) && process(len - i, p1 + i, p2 + i, s1, s2, res));
      }
      return check;
    }
    bool isScramble(string s1, string s2) {
      map<pair<int, pair<int, int> >, bool> res;
      if (s1.length() != s2.length()) return false;
      return process(s1.length(), 0, 0, s1, s2, res);
    }
};
