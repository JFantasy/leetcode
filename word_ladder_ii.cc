class Solution {
  public:
    void bfs(const string &start, map<string, int> &dis, unordered_set<string> &dict) {
      queue<string> que;
      dis[start] = 0;
      que.push(start);
      while (!que.empty()) {
        string current = que.front();
        que.pop();
        for (int i = 0; i < current.length(); ++ i) {
          for (int j = 0; j < 26; ++ j) {
            string next = current;
            next[i] = 'a' + j;
            if (dict.find(next) == dict.end()) continue;
            if (dis.find(next) != dis.end()) continue;
            que.push(next);
            dis[next] = dis[current] + 1;
          }
        }
      }
    }
    void dfs(const string &current, vector<string> &path, vector<vector<string> > &res, map<string, int> &dis) {
      path.push_back(current);
      if (dis[current] == 0) {
        vector<string> ans(path);
        reverse(ans.begin(), ans.end());
        res.push_back(ans);
      } else {
        for (int i = 0; i < current.length(); ++ i) {
          for (int j = 0; j < 26; ++ j) {
            string next = current;
            next[i] = 'a' + j;
            if (dis.find(next) == dis.end()) continue;
            if (dis[next] + 1 != dis[current]) continue;
            dfs(next, path, res, dis);
          }
        }
      }
      path.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
      map<string, int> dis;
      bfs(start, dis, dict);
      vector<vector<string> > res;
      vector<string> path;
      if (dis.find(end) != dis.end()) dfs(end, path, res, dis);
      return res;
    }
};
