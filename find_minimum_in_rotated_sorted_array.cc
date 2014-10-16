class Solution {
  public:
    int findMin(vector<int> &num) {
      int l = 0, r = num.size() - 1;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (num[l] > num[mid]) r = mid;
        else if (num[mid] > num[r]) l = mid + 1;
        else return num[l];
      }
      return num[l];
    }
};
