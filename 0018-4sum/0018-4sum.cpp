class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate j

                long long sum = (long long)target - nums[i] - nums[j]; // use long long
                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long twoSum = nums[left] + nums[right];

                    if (twoSum < sum) {
                        left++;
                    } 
                    else if (twoSum > sum) {
                        right--;
                    } 
                    else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicate numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
