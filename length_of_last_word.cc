class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      if (s == NULL) return 0;
      string str = "";
      for (int i = strlen(s) - 1; i >= 0; -- i) {
        if (s[i] == ' ') {
          if (str.length() > 0) return str.length();
          str = "";
        } else str += s[i];
      }
      return str.length();
    }
};
