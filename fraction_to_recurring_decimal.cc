class Solution {
  public:
    typedef long long LL;
    string myitoa(LL number) {
      stringstream ss;
      ss << number;
      return ss.str();
    }
    string fractionToDecimal(int numerator, int denominator) {
      if (numerator == 0) return "0";
      string op = "";
      if (numerator < 0 && denominator > 0) op = "-";
      if (numerator > 0 && denominator < 0) op = "-";
      LL p = numerator, q = denominator;
      if (p < 0) p = -p;
      if (q < 0) q = -q;
      string integer, real;
      integer = myitoa(p / q);
      LL mod = p % q;
      if (mod == 0) return op + integer;
      unordered_map<LL, int> pos;
      int index = 0;
      while (mod > 0) {
        if (pos.find(mod) == pos.end()) {
          pos[mod] = index++;
          mod = mod * 10;
          real += myitoa(mod / q);
          mod %= q;
        } else return op + integer + "." + real.substr(0, pos[mod]) + "(" + real.substr(pos[mod]) + ")";
      }
      return op + integer + "." + real;
    }
};
