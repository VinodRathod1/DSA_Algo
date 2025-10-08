class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (auto s : spells) {
            long long need = (success + s - 1) / s;
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};
