class Solution {
  public:
    static bool cmp(const int &l, const int &r) {
      stringstream ss1, ss2;
      ss1 << l << r;
      ss2 << r << l;
      return ss1.str() > ss2.str();
    }
    string largestNumber(vector<int> &num) {
      sort(num.begin(), num.end(), cmp);
      string res = "";
      for (int n : num) {
        if (res == "" && n == 0) continue;
        stringstream ss;
        string str;
        ss << n;
        ss >> str;
        res += str;
      }
      if (res == "") return "0";
      return res;
    }
};
