class Solution {
  public:
    int findConsecutive(const int &x, unordered_map<int, int> &current) {
      int res = 0;
      for (int i = x; ; ++ i) {
        if (current.find(i) != current.end()) {
          ++ res;
          current.erase(i);
        } else break;
      }
      for (int i = x - 1; ; -- i) {
        if (current.find(i) != current.end()) {
          ++ res;
          current.erase(i);
        } else break;
      }
      return res;
    }
    int longestConsecutive(vector<int> &num) {
      unordered_map<int, int> current;
      for (int i = 0; i < num.size(); ++ i) current[num[i]] = 1;
      int res = 0;
      while (!current.empty()) {
        int x = current.begin()->first;
        res = max(res, findConsecutive(x, current));
      }
      return res;
    }
};
