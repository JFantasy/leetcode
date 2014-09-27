class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int power = 1;
      while (power <= x / 10) power *= 10;
      while (x > 0) {
        int i = x / power, j = x % 10;
        if (i != j) return false;
        x = x % power / 10;
        power /= 100;
      }
      return true;
    }
};

//---------

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int val = x, y = 0, bak = val;
      for ( ; val; val /= 10) y = y * 10 + val % 10;
      return bak == y;
    }
};
