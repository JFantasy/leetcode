class Solution {
public:
    int minCut(string s) {
        const int n = s.length();
        vector<vector<bool> > palindrome(n, vector<bool>(n, false));
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || palindrome[i + 1][j - 1])) palindrome[i][j] = true;
            }
            for (int j = i; j < n; ++j) {
                if (!palindrome[i][j]) continue;
                if (dp[i] == 0 || dp[i] > dp[j + 1] + 1) dp[i] = dp[j + 1] + 1;
            }
        }
        return dp[0] - 1;
    }
};
