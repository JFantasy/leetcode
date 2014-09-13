class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
      stack<int> stk;
      const string op("+-*/");
      for (int i = 0; i < tokens.size(); ++ i) {
        if (op.find(tokens[i]) == string::npos) stk.push(atoi(tokens[i].c_str()));
        else {
          int y = stk.top();
          stk.pop();
          int x = stk.top();
          stk.pop();
          if (tokens[i] == "+") stk.push(x + y);
          if (tokens[i] == "-") stk.push(x - y);
          if (tokens[i] == "*") stk.push(x * y);
          if (tokens[i] == "/") stk.push(x / y);
        }
      }
      return stk.top();
    }
};
