class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      unordered_map<string, int> dict;
      for (int i = 0; i < L.size(); ++ i) ++ dict[L[i]];
      vector<int> res;
      int len = L[0].length();
      for (int i = 0; i + L.size() * len <= S.length(); ++ i) {
        unordered_map<string, int> current;
        bool flag = true;
        for (int j = 0; j < L.size() * len && flag; j += len) {
          string word = S.substr(i + j, len);
          if (dict.find(word) == dict.end()) flag = false;
          if (current[word] == dict[word]) flag = false;
          ++ current[word];
        }
        if (flag) res.push_back(i);
      }
      return res;
    }
};
