class Solution {
  public:
    bool isPalindrome(string s) {
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      for (int l = 0, r = s.length() - 1; l < r; ) {
        if (!::isalnum(s[l])) ++ l;
        else if (!::isalnum(s[r])) -- r;
        else if (s[l] != s[r]) return false;
        else {
          ++ l;
          -- r;
        }
      }
      return true;
    }
};

//---------

class Solution {
  public:
    bool check(const string &str) {
      for (int l = 0, r = str.length() - 1; l < r; ++ l, -- r) {
        if (str[l] != str[r]) return false;
      }
      return true;
    }
    bool isPalindrome(string s) {
      string str = "";
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] >= 'A' && s[i] <= 'Z') str += s[i] - 'A' + 'a';
        if (s[i] >= 'a' && s[i] <= 'z') str += s[i];
        if (s[i] >= '0' && s[i] <= '9') str += s[i];
      }
      return check(str);
    }
};
