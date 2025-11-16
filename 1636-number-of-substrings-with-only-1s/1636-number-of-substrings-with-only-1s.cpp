class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') {
                    j++;
                }
                long long len = j - i; 
                ans = (ans + len * (len + 1) / 2) % MOD;
                i = j; 
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
