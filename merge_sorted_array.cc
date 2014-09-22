class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, current = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) A[current--] = A[i--];
            else A[current--] = B[j--]; 
        }
        while (j >= 0) A[current--] = B[j--];
    }
};

//---------

class Solution {
  public:
    void merge(int A[], int m, int B[], int n) {
      for (int ap = m - 1, bp = n - 1, index = m + n - 1; index >= 0; -- index) {
        if (ap < 0) A[index] = B[bp --];
        else if (bp < 0) A[index] = A[ap --];
        else if (A[ap] > B[bp]) A[index] = A[ap --];
        else A[index] = B[bp --];
      }
    }
};
