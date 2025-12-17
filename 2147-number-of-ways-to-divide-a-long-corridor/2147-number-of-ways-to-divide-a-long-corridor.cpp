class Solution {
    public:
    int numberOfWays(string s) {
        long a = 1, m = 1e9 + 7;
        int c = 0, p = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'S') {
                c++;
                if (c > 2 && c % 2 == 1) {
                    a = (a * (i - p)) % m;
                }
                p = i;
            }
        }
        return (c > 0 && c % 2 == 0) ? a : 0;
    }
};

