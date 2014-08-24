class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      if (gas.size() == 0) return -1;
      map<int, int> current;
      int sum = 0;
      for (int i = 0; i < gas.size(); ++ i) {
        sum += gas[i] - cost[i];
        ++ current[sum];
      }
      for (int i = 0, delta = 0; i <= gas.size(); ++ i) {
        if (current.begin()->first - delta >= 0) return i;
        if (i == gas.size()) break;
        delta += gas[i] - cost[i];
        -- current[delta];
        if (current[delta] == 0) current.erase(delta);
        ++ current[sum + delta];
      }
      return -1;
    }
};
