class Solution {
  public:
    string getPermutation(int n, int k) {
      string num(n, '0'), res;
      int base = 1;
      -- k;
      for (int i = 0; i < n; ++ i) num[i] += i + 1;
      for (int i = 2; i < n; ++ i) base *= i;
      for (int i = n - 1; i > 0; k %= base, base /= i, -- i) {
        auto iter = next(num.begin(), k / base);
        res.push_back(*iter);
        num.erase(iter);
      }
      return res + *num.begin();
    }
};

//---------

class Solution {
  public:
    string getPermutation(int n, int k) {
      vector<int> fact(n, 1), use(n, 0);
      string res = "";
      -- k;
      for (int i = 2; i < n; ++ i) fact[i] = fact[i - 1] * i;
      for (int i = 0; i < n; ++ i) {
        int j;
        for (j = 0; k >= fact[n - i - 1] || use[j]; ++ j) {
          if (!use[j]) k -= fact[n - i - 1];
        }
        use[j] = 1;
        res += '0' + j + 1;
      }
      return res;
    }
};
