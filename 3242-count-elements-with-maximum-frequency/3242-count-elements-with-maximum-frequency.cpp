#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int x : nums) {
            freq[x]++;
        }
        int mx = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for (int f : freq) {
            if (f == mx) ans += f;
        }

        return ans;
    }
};
