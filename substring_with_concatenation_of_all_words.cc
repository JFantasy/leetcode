class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      unordered_map<string, int> dict;
      for (int i = 0; i < L.size(); ++ i) ++ dict[L[i]];
      vector<int> res;
      int len = L[0].length();
      for (int start = 0; start < len; ++ start) {
        unordered_map<string, int> current;
        int l = start, r = l, reach = 0;
        while (true) {
          if (r + len > S.length()) break;
          string word = S.substr(r, len);
          r += len;
          if (dict.find(word) == dict.end()) {
            reach = 0;
            current.clear();
            l = r;
          } else {
            ++ current[word];
            if (current[word] == dict[word]) ++ reach;
            else {
              while (current[word] > dict[word]) {
                string rword = S.substr(l, len);
                if (current[rword] == dict[rword]) -- reach;
                -- current[rword];
                l += len;
              }
            }
            if (reach == dict.size()) res.push_back(l);
          }
        }
      }
      return res;
    }
};

//---------

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
