class Solution {
public:
    void stringToVec(const string &version, vector<int> *num) {
        string current = "";
        for (char ch : version) {
            if (ch == '.') {
                num->push_back(atoi(current.c_str()));
                current = "";
            } else current += ch;
        }
        num->push_back(atoi(current.c_str()));
    }
    int compareVersion(string version1, string version2) {
        vector<int> num1, num2;
        stringToVec(version1, &num1);
        stringToVec(version2, &num2);
        auto iter1 = num1.begin(), iter2 = num2.begin();
        while (iter1 != num1.end() && iter2 != num2.end()) {
            if (*iter1 > *iter2) return 1;
            if (*iter1 < *iter2) return -1;
            ++iter1;
            ++iter2;
        }
        int back1 = accumulate(iter1, num1.end(), 0), back2 = accumulate(iter2, num2.end(), 0);
        if (back1 > back2) return 1;
        else if (back1 < back2) return -1;
        else return 0;
    }
};
