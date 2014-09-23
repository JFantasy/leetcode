class Solution {
  public:
    vector<vector<string>> partition(string s) {
      const int n = s.length();
      vector<vector<vector<string> > > res(n);
      vector<vector<int> > palindrome(n, vector<int>(n));
      for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++ j) {
          palindrome[i][j] = ((j - i < 2 || palindrome[i + 1][j - 1]) && s[i] == s[j]);
        }
      }
      for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
          if (!palindrome[i][j]) continue;
          string str = s.substr(i, j - i + 1);
          if (j + 1 < n) {
            for (vector<string> items : res[j + 1]) {
              items.insert(items.begin(), str);
              res[i].push_back(items);
            }
          } else res[i].push_back(vector<string>({str}));
        }
      }
      return res[0];
    }
};

//---------

class Solution {
  public:
    bool checkPalindrome(vector<vector<int> > &palindrome, const string &s, int l, int r) {
      if (l >= r) return true;
      if (palindrome[l][r] != -1) return palindrome[l][r];
      return (palindrome[l][r] = checkPalindrome(palindrome, s, l + 1, r - 1) && (s[l] == s[r]));
    }
    void dfs(int start, const string &s, vector<string> &current, 
        vector<vector<string> > &res, vector<vector<int> > &palindrome) {
      if (start == s.length()) res.push_back(current);
      else {
        string str = "";
        for (int i = start; i < s.length(); ++ i) {
          str += s[i];
          if (checkPalindrome(palindrome, s, start, i)) {
            current.push_back(str);
            dfs(i + 1, s, current, res, palindrome);
            current.pop_back();
          }
        }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<int> > palindrome(s.length(), vector<int>(s.length(), -1));
      vector<vector<string> > res;
      vector<string> current;
      dfs(0, s, current, res, palindrome);
      return res;
    }
};
