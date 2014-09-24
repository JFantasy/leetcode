class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      int res = 0;
      for (int i = 1; i < prices.size(); ++i) res += max(0, prices[i] - prices[i - 1]);
      return res;
    }
};

//---------

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() <= 1) return 0;
      vector<int> f(prices.size(), 0);
      int res = 0;
      for (int i = 1, pre = -prices[0]; i < prices.size(); ++ i) {
        f[i] = max(pre + prices[i], f[i - 1]);
        pre = max(pre, f[i - 1] - prices[i]);
        res = max(res, f[i]);
      }
      return res;
    }
};
