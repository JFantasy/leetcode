class Solution {
  public:
    void sortColors(int A[], int n) {
      int total[3] = {0, 0, 0};
      for (int i = 0; i < n; ++ i) ++ total[A[i]];
      for (int i = 0, j = 0; i < 3; ++ i) {
        for (int h = 0; h < total[i]; ++ h, ++ j) A[j] = i;
      }
    }
};
