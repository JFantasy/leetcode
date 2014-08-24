class Solution {
  public:
    vector<vector<int> > threeSum(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      for (int i = 0; i < num.size(); ++ i) {
        if (i > 0 && num[i] == num[i - 1]) continue;
        for (int l = i + 1, r = num.size() - 1; l < r; ++ l) {
          if (l - 1 > i && num[l] == num[l - 1]) continue;
          while (num[i] + num[l] + num[r] > 0 && l < r) -- r;
          if (l < r && num[i] + num[l] + num[r] == 0) {
            vector<int> tuple;
            tuple.push_back(num[i]);
            tuple.push_back(num[l]);
            tuple.push_back(num[r]);
            res.push_back(tuple);
          }
        }
      }
      return res;
    }
};
