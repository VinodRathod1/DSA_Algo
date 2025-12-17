class Solution {
    public:
    int numberOfWays(string s) {
        long a = 1, m = 1e9 + 7;
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'S') v.push_back(i);
        }
        if (v.empty() || v.size() % 2 != 0) return 0;
        for (int i = 2; i < v.size(); i += 2) {
            a = (a * (v[i] - v[i - 1])) % m;
        }
        return (int)a;
    }
};

