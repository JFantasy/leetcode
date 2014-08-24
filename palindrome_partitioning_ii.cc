class Solution {
  public:
    bool isPalindrome(int l, int r, vector<vector<int> > &check, const string &s) {
      if (l >= r) return true;
      if (check[l][r] >= 0) return check[l][r];
      return (check[l][r] = (s[l] == s[r] && isPalindrome(l + 1, r - 1, check, s)));
    }
    int minCut(string s) {
      if (s.length() == 0) return 0;
      vector<vector<int> > check(s.length(), vector<int>(s.length(), -1));
      vector<int> dp(s.length() + 1, 0);
      for (int i = 0; i < s.length(); ++ i) {
        for (int j = 0; j <= i; ++ j) {
          if (isPalindrome(j, i, check, s)) {
            dp[i + 1] = !dp[i + 1] ? dp[j] + 1 : min(dp[i + 1], dp[j] + 1);
          }
        }
      }
      return dp[s.length()] - 1;
    }
};
