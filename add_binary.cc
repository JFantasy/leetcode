class Solution {
  public:
    string addBinary(string a, string b) {
      string res;
      int n = a.length(), m = b.length(), len = max(n, m), add = 0;
      for (int i = 0; i < len; ++ i) {
        int l = i < n ? a[n - i - 1] - '0' : 0;
        int r = i < m ? b[m - i - 1] - '0' : 0;
        int x = (l + r + add) & 1, y = (l + r + add) >> 1;
        res.insert(res.begin(), '0' + x);
        add = y;
      }
      if (add) res.insert(res.begin(), '1');
      return res;
    }
};

//---------

class Solution {
  public:
    string addBinary(string a, string b) {
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      string res(max(a.length(), b.length()), 0);
      int add = 0;
      for (int i = 0; i < res.length(); ++ i) {
        int l = i < a.length() ? a[i] - '0' : 0;
        int r = i < b.length() ? b[i] - '0' : 0;
        int x = (l + r + add) & 1, y = (l + r + add) >> 1;
        res[i] = '0' + x;
        add = y;
      }
      if (add) res += '1';
      reverse(res.begin(), res.end());
      return res;
    }
};
