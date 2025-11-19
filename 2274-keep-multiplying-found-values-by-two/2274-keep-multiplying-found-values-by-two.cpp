class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        while(mpp.find(original)!=mpp.end()){
            original*=2;
           
        }
        return original;
    }
};