class Solution {
  public:
    int maximumGap(vector<int> &num) {
      const int n = num.size();
      if (n < 2) return 0;
      vector<int> max_value(n, INT_MIN), min_value(n, INT_MAX);
      int lower = *min_element(num.begin(), num.end()), upper = *max_element(num.begin(), num.end());
      for (int value : num) {
        int index = (long long)(value - lower) * (n - 1) / (upper - lower);
        max_value[index] = max(max_value[index], value);
        min_value[index] = min(min_value[index], value);
      }
      int max_gap = 0;
      for (int l = 0, r = 1; r < n; ++l) {
        if (max_value[l] == INT_MIN) continue;
        while (r < n && (r <= l || min_value[r] == INT_MAX)) ++r;
        if (l < r && r < n) max_gap = max(max_gap, min_value[r] - max_value[l]);
      }
      return max_gap;
    }
};
