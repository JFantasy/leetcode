class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int val = x, y = 0, bak = val;
      for ( ; val; val /= 10) y = y * 10 + val % 10;
      return bak == y;
    }
};
