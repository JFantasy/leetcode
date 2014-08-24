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
    bool cmp(const Interval &lhs, const Interval &rhs) {
      return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
    }
    bool match(const Interval &lhs, const Interval &rhs) {
      return rhs.start <= lhs.end;
    }
    void merge(vector<Interval> &res, const Interval &interval) {
      if (res.size() == 0) res.push_back(interval);
      else {
        if (match(res[res.size() - 1], interval)) res[res.size() - 1].end = max(res[res.size() - 1].end, interval.end);
        else res.push_back(interval);
      }
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval> res;
      for (int i = 0, j = 0; i < intervals.size() || j < 1; ) {
        if (i == intervals.size()) {
          merge(res, newInterval);
          ++ j;
        } else if (j == 1) {
          merge(res, intervals[i ++]);
        } else {
          if (cmp(intervals[i], newInterval)) {
            merge(res, intervals[i ++]);
          } else {
            merge(res, newInterval);
            ++ j;
          }
        }
      }
      return res;
    }
};
