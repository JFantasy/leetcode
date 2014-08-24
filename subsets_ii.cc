class Solution {
  public:
    int getNext(int start, const vector<int> &S) {
      while (start < S.size() - 1 && S[start] == S[start + 1]) ++ start;
      return start + 1;
    }
    void dfs(int start, vector<int> &S, vector<int> &current, vector<vector<int> > &res) {
      if (start == S.size()) {
        res.push_back(current);
        return;
      }
      int next = getNext(start, S);
      dfs(next, S, current, res);
      for (int i = start; i < next; ++ i) {
        current.push_back(S[i]);
        dfs(next, S, current, res);
      }
      for (int i = start; i < next; ++ i) {
        current.pop_back();
      }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      vector<vector<int> > res;
      vector<int> current;
      sort(S.begin(), S.end());
      dfs(0, S, current, res);
      return res;
    }
};
