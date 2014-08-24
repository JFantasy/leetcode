class Solution {
  public:
    void add(char ch, map<char, int> &current, map<char, int> &target, int &reach) {
      ++ current[ch];
      if (target.find(ch) == target.end()) return;
      if (target[ch] == current[ch]) ++ reach;
    }
    void remove(char ch, map<char, int> &current, map<char, int> &target, int &reach) {
      if (target.find(ch) == target.end()) return;
      if (target[ch] == current[ch]) -- reach;
      -- current[ch];
    }
    void update(pair<int, int> &res, int l, int r) {
      if (res.first < 0 || res.second - res.first > r - l) res = make_pair(l, r);
    }
    string minWindow(string S, string T) {
      map<char, int> current, target;
      pair<int, int> res(-1, -1);
      int reach = 0;
      for (int i = 0; i < T.length(); ++ i) ++ target[T[i]];
      for (int l = 0, r = 0; r < S.length(); ++ r) {
        add(S[r], current, target, reach);
        while (l <= r && reach == target.size()) {
          update(res, l, r);
          remove(S[l ++], current, target, reach);
        }
      }
      return res.first == -1 ? "" : string(S.begin() + res.first, S.begin() + res.second + 1);
    }
};
