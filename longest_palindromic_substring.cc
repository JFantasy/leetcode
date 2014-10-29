class Solution {
public:
    string longestPalindrome(string s) {
        string extend;
        for (char ch : s) {
            extend += '#';
            extend += ch;
        }
        extend += '#';
        const int n = extend.length();
        vector<int> len(n, 0);
        for (int i = 1, current = 0, index = 0; i < n; ++i) {
            if (current > i) len[i] = min(len[2 * index - i], current - i);
            else len[i] = 1;
            while (i + len[i] < n && i >= len[i] && extend[i - len[i]] == extend[i + len[i]]) ++len[i];
            if (len[i] + i > current) {
                current = len[i] + i;
                index = i;
            }
        }
        int res_index = 0;
        for (int i = 1; i < n; ++i) {
            if (len[i] > len[res_index]) res_index = i;
        }
        string res;
        for (int i = res_index - len[res_index] + 1; i < res_index + len[res_index]; ++i) {
            if (extend[i] != '#') res += extend[i];
        }
        return res;
    }
};
