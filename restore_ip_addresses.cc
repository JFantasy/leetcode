class Solution {
  public:
    void dfs(const int &dep, const string &s, const int &start, string ip, vector<string> &res) {
      if (dep == 4) {
        if (start != s.length()) return;
        ip.pop_back();
        res.push_back(ip);
      } else {
        int num = 0;
        for (int i = start; i < s.length(); ++i) {
          num = num * 10 + s[i] - '0';
          if (num > 255) break;
          ip += s[i];
          dfs(dep + 1, s, i + 1, ip + ".", res);
          if (num == 0) break;
        }
      }
    }
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      dfs(0, s, 0, "", res);
      return res;
    }
};

//---------

class Solution {
  public:
    string itoa(const int &val) {
      stringstream res;
      res << val;
      return res.str();
    }
    int toNumber(const string &str) {
      if (str.length() == 0) return -1;
      if (str.length() > 1 && str[0] == '0') return -1;
      int val = atoi(str.c_str());
      if (val >= 0 && val <= 255) return val;
      else return -1;
    }
    void dfs(int dep, int start, const string &s, string current, vector<string> &res) {
      if (dep == 3) {
        string str = string(s.begin() + start, s.end());
        int val = toNumber(str);
        if (val == -1) return;
        res.push_back(current + itoa(val));
      } else {
        string str = "";
        int last = -1;
        for (int i = start, last = -1; i < s.length(); ++ i) {
          str += s[i];
          int val = toNumber(str);
          if (val == -1 || val == last) continue;
          last = val;
          dfs(dep + 1, i + 1, s, current + itoa(val) + ".", res);
        }
      }
    }
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      dfs(0, 0, s, "", res);
      return res;
    }
};
