class Solution {
  public:
    int threeSumClosest(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int res = num[0] + num[1] + num[2];
      for (int i = 0; i < num.size(); ++ i) {
        for (int l = i + 1, r = num.size() - 1; l < r; ++ l) {
          while (l < r && num[i] + num[l] + num[r] > target) {
            if (abs(res - target) > abs(num[i] + num[l] + num[r] - target)) res = num[i] + num[l] + num[r];
            -- r;
          }
          if (l < r) {
            if (abs(res - target) > abs(num[i] + num[l] + num[r] - target)) res = num[i] + num[l] + num[r];
          }
        }
      }
      return res;
    }
};
