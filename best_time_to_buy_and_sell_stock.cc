class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() == 0) return 0;
      int res = 0, min_val = prices[0];
      for (int i = 1; i < prices.size(); ++ i) {
        res = max(res, prices[i] - min_val);
        min_val = min(min_val, prices[i]);
      }
      return res;
    }
};
