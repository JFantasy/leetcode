class Solution {
  public:
    bool isValidSudoku(vector<vector<char> > &board) {
      const int n = board.size();
      vector<vector<bool> > row(n, vector<bool>(n)), column(n, vector<bool>(n)), group(n, vector<bool>(n));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == '.') continue;
          int val = board[i][j] - '1';
          if (row[i][val] || column[j][val] || group[(i / 3) * 3 + (j / 3)][val]) return false;
          row[i][val] = column[j][val] = group[(i / 3) * 3 + (j / 3)][val] = true;
        }
      }
      return true;
    }
};

//---------

class Solution {
  public:
    bool check(const vector<char> &arr) {
      vector<int> tot(9);
      for (int i = 0; i < arr.size(); ++ i) {
        if (arr[i] == '.') continue;
        ++ tot[arr[i] - '1'];
        if (tot[arr[i] - '1'] > 1) return false;
      }
      return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
      bool res = true;
      for (int i = 0; i < board.size() && res; ++ i) {
        res &= check(board[i]);
      }
      for (int j = 0; j < board[0].size() && res; ++ j) {
        vector<char> arr;
        for (int i = 0; i < board.size(); ++ i) {
          arr.push_back(board[i][j]);
        }
        res &= check(arr);
      }
      for (int x = 0; x < board.size() && res; x += 3) {
        for (int y = 0; y < board[0].size() && res; y += 3) {
          vector<char> arr;
          for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
              arr.push_back(board[x + i][y + j]);
            }
          }
          res &= check(arr);
        }
      }
      return res;
    }
};
