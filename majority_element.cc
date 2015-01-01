class Solution {
  public:
    int majorityElement(vector<int> &num) {
      const int n = num.size();
      int res = num[0], count = 1;
      for (int i = 1; i < n; ++i) {
        if (res == num[i]) ++count;
        else {
          --count;
          if (count < 0) {
            count = 1;
            res = num[i];
          }
        }
      }
      return res;
    }
};
