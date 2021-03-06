class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for (auto current = path.begin(); current != path.end();) {
            ++current;
            auto next = find(current, path.end(), '/');
            string name(current, next);
            if (name != "." && name.length() > 0) {
                if (name == "..") {
                    if (!dirs.empty()) dirs.pop_back();
                } else dirs.push_back(name);
            }
            current = next;
        }
        if (dirs.empty()) return "/";
        string res = "";
        for (const auto &name : dirs) res += "/" + name;
        return res;
    }
};

//---------

class Solution {
  public:
    void update(vector<string> &res, string &current) {
      if (current != ".") {
        if (current == "..") {
          if (res.size() > 0) res.pop_back();
        } else if (current != "") res.push_back(current);
      }
      current = "";
    }
    string simplifyPath(string path) {
      vector<string> res;
      string current = "";
      for (int i = 0; i <= path.length(); ++ i) {
        if (i == path.length() || path[i] == '/') update(res, current);
        else current += path[i];
      }
      if (res.size() == 0) return "/";
      string res_str = "";
      for (int i = 0; i < res.size(); ++ i) res_str += "/" + res[i];
      return res_str;
    }
};
