/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    static bool cmp(const Interval &lhs, const Interval &rhs) {
      return lhs.start < rhs.start;
    }
    bool match(const Interval &lhs, const Interval &rhs) {
      return rhs.start <= lhs.end;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
      if (intervals.size() == 0) return vector<Interval>();
      sort(intervals.begin(), intervals.end(), cmp);
      vector<Interval> res;
      res.push_back(intervals[0]);
      int current = 0;
      for (int i = 1; i < intervals.size(); ++ i) {
        if (match(res[current], intervals[i])) res[current].end = max(res[current].end, intervals[i].end);
        else {
          ++ current;
          res.push_back(intervals[i]);
        }
      }
      return res;
    }
};
