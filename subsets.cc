class Solution {
  public:
    vector<vector<int> > subsets(vector<int> &S) {
      sort(S.begin(), S.end());
      vector<vector<int> > res;
      for (int i = 0; i < (1 << S.size()); ++ i) {
        vector<int> sub;
        for (int j = 0; j < S.size(); ++ j) {
          if (i & (1 << j)) sub.push_back(S[j]);
        }
        res.push_back(sub);
      }
      return res;
    }
};
