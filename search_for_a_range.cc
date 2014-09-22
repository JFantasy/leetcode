class Solution {
  public:
    vector<int> searchRange(int A[], int n, int target) {
      int l = distance(A, lower_bound(A, A + n, target));
      int r = distance(A, upper_bound(A, A + n, target) - 1);
      return l == n || A[l] != target ? vector<int>({-1, -1}) : vector<int>({l, r});
    }
};

//----------

class Solution {
  public:
    int find(int A[], int n, int target, int flag) {
      int low = 0, upp = n - 1, res = -1;
      while (low <= upp) {
        int mid = (low + upp) >> 1;
        if (A[mid] == target) {
          res = mid;
          if (!flag) upp = mid - 1;
          else low = mid + 1;
        } else if (A[mid] < target) low = mid + 1;
        else upp = mid - 1;
      }
      return res;
    }
    vector<int> searchRange(int A[], int n, int target) {
      vector<int> res;
      res.push_back(find(A, n, target, 0));
      res.push_back(find(A, n, target, 1));
      return res;
    }
};
