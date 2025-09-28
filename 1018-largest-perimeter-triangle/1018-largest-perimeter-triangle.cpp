class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i + 2 < (int)nums.size(); ++i) {
            if (nums[i] < nums[i+1] + nums[i+2]) {
                int ans = nums[i] + nums[i+1] + nums[i+2];
                return ans;
            }
        }
        return 0;
    }
};
