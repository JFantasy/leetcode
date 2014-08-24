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
