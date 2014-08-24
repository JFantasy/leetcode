class Solution {
  public:
    void findNext(char *str, vector<int> &next) {
      int m = strlen(str);
      for (int i = 0, j = -1; i < m; ) {
        if (j == -1 || str[i] == str[j]) {
          ++ i;
          ++ j;
          next[i] = j;
        } else j = next[j];
      }
    }
    char *strStr(char *haystack, char *needle) {
      if (!strcmp(needle, "")) return haystack;
      int n = strlen(haystack), m = strlen(needle);
      vector<int> next(m + 1, -1);
      findNext(needle, next);
      for (int i = 0, j = 0; i < n && j < m; ) {
        if (j == -1 || haystack[i] == needle[j]) {
          ++ i;
          ++ j;
          if (j == m) return haystack + i - j;
        } else j = next[j];
      }
      return NULL;
    }
};
