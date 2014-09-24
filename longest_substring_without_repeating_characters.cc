class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      const int kAsciiMax = 256;
      const int n = s.length();
      vector<int> last(kAsciiMax, -1);
      int res = 0, start = 0;
      for (int i = 0; i < n; ++i) {
        if (last[int(s[i])] >= start) {
          res = max(res, i - start);
          start = last[int(s[i])] + 1;
        }
        last[int(s[i])] = i;
      }
      res = max(res, n - start);
      return res;
    }
};

//---------

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
