class Solution {
  public:
    bool check(const int &x, const int &y, const vector<vector<char> > &board) {
      for (int i = 0; i < 9; ++i) {
        if (i != y && board[x][i] == board[x][y]) return false;
        if (i != x && board[i][y] == board[x][y]) return false;
        int gx = (x / 3) * 3 + (i / 3), gy = (y / 3) * 3 + (i % 3);
        if ((gx != x || gy != y) && board[gx][gy] == board[x][y]) return false;
      }
      return true;
    }
    void dfs(const int &step, bool &finish, vector<vector<char> > &board) {
      if (step == 9 * 9) finish = true;
      else {
        int x = step / 9, y = step % 9;
        if (board[x][y] != '.') dfs(step + 1, finish, board);
        else {
          for (int i = 0; i < 9 && !finish; ++i) {
            board[x][y] = '1' + i;
            if (!check(x, y, board)) continue;
            dfs(step + 1, finish, board);
          }
          if (!finish) board[x][y] = '.';
        }
      }
    }
    void solveSudoku(vector<vector<char> > &board) {
      bool finish = false;
      dfs(0, finish, board);
    }
};

//---------

class Solution {
  public:
    int calGroupId(const int &x, const int &y) {
      return (x / 3) * 3 + y / 3;
    }
    void calExistNumber(const vector<vector<char> > &board, 
        vector<int> &row,
        vector<int> &column, 
        vector<int> &group) {
      for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
          if (board[i][j] == '.') continue;
          int val = board[i][j] - '1';
          row[i] |= (1 << val);
          column[j] |= (1 << val);
          group[calGroupId(i, j)] |= (1 << val);
        }
      }                        
    }
    void dfs(int step, vector<vector<char> > &board,
        vector<int> &row,
        vector<int> &column, 
        vector<int> &group,
        bool &finish) {
      if (step == 9 * 9) {
        finish = true;
        return;
      }
      int x = step / 9, y = step % 9;
      if (board[x][y] != '.') dfs(step + 1, board, row, column, group, finish);
      else {
        for (int i = 0; i < 9; ++ i) {
          if (row[x] & (1 << i)) continue;
          if (column[y] & (1 << i)) continue;
          if (group[calGroupId(x, y)] & (1 << i)) continue;
          row[x] ^= (1 << i);
          column[y] ^= (1 << i);
          group[calGroupId(x, y)] ^= (1 << i);
          board[x][y] = '1' + i;
          dfs(step + 1, board, row, column, group, finish);
          if (finish) return;
          row[x] ^= (1 << i);
          column[y] ^= (1 << i);
          group[calGroupId(x, y)] ^= (1 << i);
          board[x][y] = '.';
        }
      }
    }
    void solveSudoku(vector<vector<char> > &board) {
      vector<int> row(9), column(9), group(9);
      calExistNumber(board, row, column, group);
      bool finish = false;
      dfs(0, board, row, column, group, finish);
    }
};
