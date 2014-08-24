class Solution {
  public:
    static bool cmp(const pair<vector<int>, string> &lhs, const pair<vector<int>, string> &rhs) {
      for (int i = 0; i < 26; ++ i) {
        if ((lhs.first)[i] < (rhs.first)[i]) return false;
        if ((lhs.first)[i] > (rhs.first)[i]) return true;
      }
      return false;
    }
    bool isAnagrams(const pair<vector<int>, string> &lhs, const pair<vector<int>, string> &rhs) {
      for (int i = 0; i < 26; ++ i) {
        if ((lhs.first)[i] != (rhs.first)[i]) return false;
      }
      return true;
    }
    vector<int> calArray(const string &str) {
      vector<int> res(26, 0);
      for (int i = 0; i < str.length(); ++ i) {
        ++ res[str[i] - 'a'];
      }
      return res;
    }
    vector<string> anagrams(vector<string> &strs) {
      vector<pair<vector<int>, string> > arr;
      for (int i = 0; i < strs.size(); ++ i) {
        arr.push_back(make_pair(calArray(strs[i]), strs[i]));
      }
      sort(arr.begin(), arr.end(), cmp);
      vector<string> res;
      for (int i = 0; i < arr.size(); ++ i) {
        int j;
        for (j = i; j + 1 < arr.size() && isAnagrams(arr[i], arr[j + 1]); ++ j);
        if (i < j) {
          for (int h = i; h <= j; ++ h) res.push_back(arr[h].second);
        }
        i = j;
      }
      return res;
    }
};
