class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      map<int, int> pos;
      int x = 0, y = 0;
      for (int i = 0; i < numbers.size(); ++ i) {
        if (pos.find(target - numbers[i]) != pos.end()) {
          x = i + 1;
          y = pos[target - numbers[i]];
          break;
        }
        pos[numbers[i]] = i + 1;
      }
      if (x > y) swap(x, y);
      vector<int> res(2, 0);
      res[0] = x;
      res[1] = y;
      return res;
    }
};
