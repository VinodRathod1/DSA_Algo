class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int c=target-nums[i];
            if(mpp.find(c)!=mpp.end()){
                return {mpp[c],i};
            }else{
            mpp[nums[i]]=i;
            }
        }
        return {};
    }
};