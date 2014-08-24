class Solution {
  public:
    string longestPalindrome(string s) {
      string t = "";
      for (int i = 0; i < s.length(); ++ i) {
        t += '#';
        t += s[i];
      }
      t += '#';
      vector<int> ans(t.length(), 0);
      for (int i = 1, mx = 0, id = 0; i < t.length(); ++ i) {
        if (mx > i) ans[i] = min(ans[2 * id - 1], mx - i);
        else ans[i] = 1;
        while (i + ans[i] < t.length() && i - ans[i] >= 0 && t[i + ans[i]] == t[i - ans[i]]) ++ ans[i];
        if (ans[i] + i > mx) {
          mx = ans[i] + i;
          id = i;
        }
      }
      int p = 0;
      for (int i = 1; i < t.length(); ++ i) {
        if (ans[i] > ans[p]) p = i;
      }
      string res = "";
      for (int i = p - ans[p] + 1; i < p + ans[p]; ++ i) {
        if (t[i] != '#') res += t[i];
      }
      return res;
    }
};
