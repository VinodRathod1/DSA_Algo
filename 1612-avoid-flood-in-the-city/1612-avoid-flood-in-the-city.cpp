class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        map<int, int> lake_last;
        set<int> dry_days;
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry_days.insert(i);
            } else {
                int lake = rains[i];
                if (lake_last.count(lake)) {
                    auto it = dry_days.upper_bound(lake_last[lake]);
                    if (it == dry_days.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dry_days.erase(it);
                }
                lake_last[lake] = i;
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};
