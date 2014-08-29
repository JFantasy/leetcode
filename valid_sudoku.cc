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
