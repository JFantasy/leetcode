class Solution {
public:
    string convertToTitle(int n) {
        --n;
        const int base = 26;
        int k = 1;
        while (n / k >= base) {
            n -= k * base;
            k *= base;
        }
        string res = "";
        while (k > 0) {
            res += 'A' + n / k;
            n %= k;
            k /= base;
        }
        return res;
    }
};
