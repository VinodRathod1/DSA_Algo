class Solution {
public:
    void recursion(int ind, vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums) {
        int n = nums.size();
        ans.push_back(ds); 
        for (int i = ind; i < n; i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            recursion(i + 1, ans, ds, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 
        recursion(0, ans, ds, nums);
        return ans;
    }
};
