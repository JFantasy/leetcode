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
