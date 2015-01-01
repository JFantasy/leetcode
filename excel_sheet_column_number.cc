class Solution {
  public:
    int trailingZeroes(int n) {
      const int kBase = 5;
      int res = 0;
      for (long long current = kBase; n >= current; current *= kBase) res += n / current;
      return res;
    }
};
