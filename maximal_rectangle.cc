class Solution {
  public:
    int maximalRectangle(vector<vector<char> > &matrix) {
      if (matrix.empty()) return 0;
      const int n = matrix.size();
      const int m = matrix[0].size();
      vector<int> left(m, 0), right(m, m - 1), height(m, 0);
      int area = 0;
      for (int i = 0; i < n; ++i) {
        int l = 0, r = m - 1;
        for (int j = 0; j < m; ++j) {
          if (matrix[i][j] == '1') {
            ++height[j];
            left[j] = max(left[j], l);
          } else {
            height[j] = left[j] = 0;
            right[j] = m - 1;
            l = j + 1;
          }
        }
        for (int j = m - 1; j >= 0; --j) {
          if (matrix[i][j] == '1') {
            right[j] = min(right[j], r);
            area = max(area, height[j] * (right[j] - left[j] + 1));
          } else r = j - 1;
        }
      }
      return area;
    }
};

//---------

class Solution {
  public:
    void calLength(vector<int> &arr, vector<int> &res) {
      stack<int> stk;
      for (int i = 0; i < arr.size(); ++ i) {
        while (!stk.empty()) {
          int val = arr[stk.top()];
          if (val >= arr[i]) stk.pop();
          else break;
        }
        if (stk.empty()) res[i] = i + 1;
        else res[i] = i - stk.top();
        stk.push(i);
      }
    }
    int process(vector<int> &arr) {
      vector<int> l(arr.size(), 0), r(arr.size());
      calLength(arr, l);
      reverse(arr.begin(), arr.end());
      calLength(arr, r);
      int res = 0;
      for (int i = 0; i < arr.size(); ++ i) {
        res = max(res, (l[arr.size() - i - 1] + r[i] - 1) * arr[i]);
      }
      return res;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
      if (matrix.size() == 0) return 0;
      vector<vector<int> > s(matrix.size(), vector<int>(matrix[0].size(), 0));
      for (int i = 0; i < matrix.size(); ++ i) {
        for (int j = 0; j < matrix[i].size(); ++ j) {
          if (matrix[i][j] == '0') s[i][j] = 0;
          else {
            if (i > 0) s[i][j] = s[i - 1][j] + 1;
            else s[i][j] = 1;
          }
        }
      }
      int res = 0;
      for (int i = 0; i < matrix.size(); ++ i) {
        res = max(res, process(s[i]));
      }
      return res;
    }
};
