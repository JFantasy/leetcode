class Solution {
  public:
    string multiply(string num1, string num2) {
      int op = *num1.begin() == '-' ^ *num2.begin() == '-';
      if (*num1.begin() == '-') num1 = num1.substr(1);
      if (*num2.begin() == '-') num2 = num2.substr(1);
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      const int n = num1.length(), m = num2.length();
      string res(n + m, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          res[i + j] += (num1[i] - '0') * (num2[j] - '0');
          if (res[i + j] >= 10) {
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
          }
        }
      }
      while (res.length() > 1 && *res.rbegin() == 0) res.pop_back();
      for (auto &ch : res) ch += '0';
      if (op > 0) res.push_back('-');
      reverse(res.begin(), res.end());
      return res;
    }
};

//---------

class Solution {
  public:
    string process(string num1, string num2) {
      string res(num1.length() + num2.length(), '0');
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      for (int i = 0; i < num1.length(); ++ i) {
        for (int j = 0; j < num2.length(); ++ j) {
          int l = num1[i] - '0', r = num2[j] - '0';
          int cal = l * r + res[i + j] - '0';
          if (cal >= 10) {
            res[i + j + 1] += cal / 10;
            res[i + j] = '0' + cal % 10;
          } else res[i + j] = cal + '0';
        }
      }
      int len = num1.length() + num2.length();
      while (len > 1 && res[len - 1] == '0') {
        -- len;
        res.pop_back();
      }
      reverse(res.begin(), res.end());
      return res;
    }
    string multiply(string num1, string num2) {
      int flag = 0;
      if (num1[0] == '-') {
        flag ^= 1;
        num1 = num1.substr(1, num1.length() - 1);
      }
      if (num2[0] == '-') {
        flag ^= 1;
        num2 = num2.substr(1, num2.length() - 1);
      }
      string res = process(num1, num2);
      if (flag == 0 || res[0] == '0') return res;
      else return string("-") + res;
    }
};
