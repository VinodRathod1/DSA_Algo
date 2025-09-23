class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        // Split version1
        stringstream ss1(version1);
        string token;
        while (getline(ss1, token, '.')) {
            v1.push_back(stoi(token));
        }
        
        // Split version2
        stringstream ss2(version2);
        while (getline(ss2, token, '.')) {
            v2.push_back(stoi(token));
        }
        
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }
        
        return 0;
    }
};
