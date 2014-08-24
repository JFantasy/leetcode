class Solution {
  public:
    int longestValidParentheses(string s) {
      stack<int> stk;
      int res = 0, start = 0;
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == '(') stk.push(i);
        else {
          if (stk.empty()) {
            start = i + 1;
            continue;
          } else stk.pop();
          res = max(res, stk.empty() ? i - start + 1: i - stk.top());
        }
      }
      return res;
    }
};
