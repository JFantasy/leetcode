class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
      vector<int> res(digits);
      reverse(res.begin(), res.end());
      ++ res[0];
      for (int i = 0; res[i] >= 10; ++ i) {
        if (i + 1 == digits.size()) res.push_back(1);
        else ++ res[i + 1];
        res[i] -= 10;
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
