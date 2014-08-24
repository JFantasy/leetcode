class Solution {
  public:
    bool legal(int x, int y, int n, int m) {
      return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool find(vector<vector<int> > &use, vector<vector<char> > &board, int x, int y, int current, string word) {
      if (current == word.length()) return true;
      use[x][y] = 1;
      const int dx[4] = {-1, 0, 1, 0};
      const int dy[4] = {0, -1, 0, 1};
      int ans = 0;
      for (int i = 0; i < 4 && !ans; ++ i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (!legal(tx, ty, board.size(), board[0].size())) continue;
        if (board[tx][ty] != word[current]) continue;
        if (use[tx][ty]) continue;
        ans |= find(use, board, tx, ty, current + 1, word);
      }
      if (ans) return true;
      use[x][y] = 0;
      return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
      vector<vector<int> > use(board.size(), vector<int>(board[0].size(), 0));
      for (int i = 0; i < board.size(); ++ i) {
        for (int j = 0; j < board[0].size(); ++ j) {
          if (board[i][j] != word[0]) continue;
          if (find(use, board, i, j, 1, word)) return true;
        }
      }
      return false;
    }
};
