class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> count;
      int res = 0;
      for (int l = 0, r = 0; r < s.length(); ++ r) {
        ++ count[s[r]];
        while (count[s[r]] > 1 && l < r) {
          -- count[s[l]];
          ++ l;
        }
        res = max(res, r - l + 1);
      }
      return res;
    }
};
