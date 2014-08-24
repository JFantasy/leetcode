class Solution {
  public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      unordered_map<string, int> dis;
      queue<string> que;
      dis[start] = 1;
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
            dis[next] = dis[current] + 1;
            que.push(next);
          }
        }
      }
      return dis[end];
    }
};
