class Solution {
  public:
    int maxArea(vector<int> &height) {
      int res = 0;
      for (int l = 0, r = height.size() - 1; l < r; ) {
        res = max(res, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) ++ l;
        else -- r;
      }
      return res;
    }
};
