class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      int i, j;
      for (i = num.size() - 2; i >= 0; -- i) {
        if (num[i] < num[i + 1]) break;
      }
      if (i < 0) reverse(num.begin(), num.end());
      else {
        for (j = i; j + 1 < num.size() && num[j + 1] > num[i]; ++ j);
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
      }
    }
};

//---------

class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      int i, j;
      for (i = num.size() - 2; i >= 0; -- i) {
        if (num[i] < num[i + 1]) break;
      }
      if (i < 0) sort(num.begin(), num.end());
      else {
        for (j = i + 1; j < num.size() && num[j] > num[i]; ++ j);
        -- j;
        swap(num[i], num[j]);
        sort(num.begin() + i + 1, num.end());
      }
    }
};
