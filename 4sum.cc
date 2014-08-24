class Solution {
  public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      for (int i = 0; i < num.size(); ++ i) {
        if (i > 0 && num[i] == num[i - 1]) continue;
        for (int j = i + 1; j < num.size(); ++ j) {
          if (j > i + 1 && num[j] == num[j - 1]) continue;
          for (int l = j + 1, r = num.size() - 1; l < r; ++ l) {
            if (l > j + 1 && num[l] == num[l - 1]) continue;
            while (l < r && num[i] + num[j] + num[l] + num[r] > target) -- r;
            if (l < r && num[i] + num[j] + num[l] + num[r] == target) {
              vector<int> tuple;
              tuple.push_back(num[i]);
              tuple.push_back(num[j]);
              tuple.push_back(num[l]);
              tuple.push_back(num[r]);
              res.push_back(tuple);
            }
          }
        }
      }
      return res;
    }
};
