class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      vector<int> f(s.length() + 1, 0);
      f[0] = 1;
      for (int i = 0; i < s.length(); ++ i) {
        if (!f[i]) continue;
        string current = "";
        for (int j = i; j < s.length(); ++ j) {
          current += s[j];
          if (dict.find(current) != dict.end()) f[j + 1] = 1;
        }
      }
      return f[s.length()] > 0;
    }
};
