class Solution {
  public:
    int findMin(vector<int> &num) {
      if (num.empty()) return 0;
      int res = num[0], l = 0, r = num.size() - 1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (num[0] < num[mid]) l = mid + 1;
        else if (num[0] > num[mid]) {
          res = min(res, num[mid]);
          r = mid - 1;
        } else res = min(res, num[l++]);
      }
      return res;
    }
};
