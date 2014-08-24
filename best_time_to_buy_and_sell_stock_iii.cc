class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() <= 1) return 0;
      vector<vector<int> > f(2, vector<int>(prices.size()));
      int res = 0;
      for (int i = 1, min_cost = prices[0]; i < prices.size(); ++ i) {
        f[0][i] = max(f[0][i - 1], prices[i] - min_cost);
        min_cost = min(min_cost, prices[i]);
        res = max(res, f[0][i]);
      }
      for (int i = 1, pre = -prices[0]; i < prices.size(); ++ i) {
        f[1][i] = max(f[1][i - 1], pre + prices[i]);
        pre = max(pre, f[0][i - 1] - prices[i]);
        res = max(res, f[1][i]);
      }
      return res;
    }
};
