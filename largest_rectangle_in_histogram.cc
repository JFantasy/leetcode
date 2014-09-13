class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int res = 0;
        const int n = height.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] < height[stk.top()]) { //<或者<=随便
                int j = stk.top();
                stk.pop();
                res = max(res, height[j] * (stk.empty() ? i : i - stk.top() - 1));
            }
            stk.push(i);
        }
        return res;
    }
};

//------

class Solution {
  public:
    void process(const vector<int> &height, vector<int> &back) {
      stack<int> stk;
      for (int i = 0; i < height.size(); ++ i) {
        while (!stk.empty() && height[i] <= height[stk.top()]) stk.pop();
        if (stk.empty()) back[i] = i + 1;
        else back[i] = i - stk.top();
        stk.push(i);
      }
    }
    int largestRectangleArea(vector<int> &height) {
      vector<int> left(height.size()), right(height.size());
      process(height, left);
      reverse(height.begin(), height.end());
      process(height, right);
      int res = 0;
      for (int i = 0; i < height.size(); ++ i) res = max(res, (left[height.size() - i - 1] + right[i] - 1) * height[i]);
      return res;
    }
};
