class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;
        while (isspace(*s)) ++s;
        if (*s == '\0') return false;
        bool op_appear = false, dot_appear = false, exponent_appear = false, number_appear = false;
        for (char last = '\0'; *s != '\0' && !isspace(*s); last = *s, ++s) {
            if (isdigit(*s)) {
                number_appear = true;
                continue;
            } else if (*s == '+' || *s == '-') {
                if (op_appear) return false;
                if (last == '.') return false;
                if (number_appear) return false;
                op_appear = true;
                number_appear = false;
            } else if (*s == 'e') {
                if (exponent_appear) return false;
                if (!number_appear) return false;
                exponent_appear = true;
                op_appear = false;
                number_appear = false;
            } else if (*s == '.') {
                if (dot_appear || exponent_appear) return false;
                dot_appear = true;
            } else return false;
        }
        while (*s != '\0' && isspace(*s)) ++s;
        return *s == '\0' && number_appear;
    }
};

//---------

class Solution {
  public:
    bool check(const char *s, int l, int r, int op, int e, int point) {
      if (l > r) return false;
      if (op) {
        if (s[l] == '+' || s[l] == '-') {
          return check(s, l + 1, r, 0, e, point);
        }
      }
      int res = false;
      if (e || point) {
        for (int i = l; i <= r && !res; ++ i) {
          if (e && s[i] == 'e') {
            res |= check(s, l, i - 1, op, 0, 1) && check(s, i + 1, r, 1, 0, 0);
          }
          if (point && s[i] == '.') {
            if (i == l) {
              res |= check(s, i + 1, r, 0, 0, 0);
            } else if (i == r) {
              res |= check(s, l, i - 1, op, 0, 0);
            } else {
              res |= check(s, l, i - 1, op, 0, 0) && check(s, i + 1, r, 0, 0, 0);
            }
          }
        }
      }
      if (res) return true;
      for (int i = l; i <= r; ++ i) {
        if (s[i] < '0' || s[i] > '9') return false;
      }
      return true;
    }
    bool isNumber(const char *s) {
      int l = 0, r = strlen(s) - 1;
      while (l <= r) {
        if (s[l] == ' ') ++ l;
        else if (s[r] == ' ') -- r;
        else break;
      }
      return check(s, l, r, 1, 1, 1);
    }
};
