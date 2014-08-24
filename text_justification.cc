class Solution {
  public:
    string getString(vector<string> &words, int l, int r, int L) {
      string res;
      int num = r - l, sum = 0;
      for (int i = l; i <= r; ++ i) sum += words[i].length();
      for (int i = l; i <= r; ++ i) {
        res += words[i];
        if (num == 0 || i == r) continue;
        int space = (L - sum) / num + ((i - l) < (L - sum) % num);
        if (r == words.size() - 1) space = 1;
        res += string(space, ' ');
      }
      while (res.length() < L) res += " ";
      return res;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
      vector<string> res;
      int pre = 0;
      for (int i = 0, length = 0; i < words.size(); ++ i) {
        if (length + words[i].length() + (i > pre) > L) {
          res.push_back(getString(words, pre, i - 1, L));
          pre = i;
          length = words[i].length();
        } else length += words[i].length() + (i > pre);
      }
      res.push_back(getString(words, pre, words.size() - 1, L));
      return res;
    }
};
