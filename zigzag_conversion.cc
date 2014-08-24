class Solution {
  public:
    string convert(string s, int nRows) {
      if (nRows == 1) return s;
      string res = "";
      for (int i = 1; i <= nRows; ++ i) {
        int next = 2 * (i - 1);
        for (int j = i - 1; j < s.length(); j += next) {
          res += s[j];
          if (i > 1 && i < nRows) next = 2 * (nRows - 1) - next;
          else next = 2 * (nRows - 1);
        }
      }
      return res;
    }
};
