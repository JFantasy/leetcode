class Solution {
  public:
    void reverseWords(string &s) {
      vector<string> arr;
      string current;
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == ' ') {
          if (current == "") continue;
          arr.push_back(current);
          current = "";
        } else current += s[i];
      }
      if (current != "") arr.push_back(current);
      s = "";
      for (int i = arr.size() - 1; i >= 0; -- i) {
        s += arr[i];
        if (i > 0) s += " ";
      }
    }
};
