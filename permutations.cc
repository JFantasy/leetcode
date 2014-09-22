class Solution {
  public:
    void dfs(const vector<int> &num, vector<int> &current, vector<vector<int> > &res) {
      if (current.size() == num.size()) res.push_back(current);
      else {
        for (const auto &i : num) {
          if (find(current.begin(), current.end(), i) != current.end()) continue;
          current.push_back(i);
          dfs(num, current, res);
          current.pop_back();
        }
      }
    }
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > res;
      vector<int> current;
      dfs(num, current, res);
      return res;
    }
};

//---------

class Solution {
  public:
    void dfs(vector<vector<int> > &res, vector<int> &current, int dep, vector<int> &num, vector<int> &use) {
      if (dep == num.size()) res.push_back(current);
      else {
        for (int i = 0; i < num.size(); ++ i) {
          if (use[i]) continue;
          use[i] = 1;
          current.push_back(num[i]);
          dfs(res, current, dep + 1, num, use);
          current.pop_back();
          use[i] = 0;
        }
      }
    }
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > res;
      vector<int> current;
      vector<int> use(num.size(), 0);
      dfs(res, current, 0, num, use);
      return res;
    }
};
