class Solution {
  public:
    string intToRoman(int num) {
      const char *letters = "IVXLCDM";
      string res = "";
      int arr[4];
      for (int i = 0; i < 4; ++ i) {
        arr[i] = num % 10;
        num /= 10;
      }
      for (int i = 3, h = 6; i >= 0; -- i, h -= 2) {
        if (arr[i] <= 3) {
          for (int j = 0; j < arr[i]; ++ j) res += letters[h];
        } else if (arr[i] < 9) {
          for (int k = 0; k < 5 - arr[i]; ++ k) res += letters[h];
          res += letters[h + 1];
          for (int k = 0; k < arr[i] - 5; ++ k) res += letters[h];
        } else {
          res += letters[h];
          res += letters[h + 2];
        }
      }
      return res;
    }
};
