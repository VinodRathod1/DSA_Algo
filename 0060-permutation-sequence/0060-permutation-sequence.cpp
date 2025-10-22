class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
            nums.push_back(i);
        }
        k--;
        string ans="";
        for(int i=n;i>=1;i--){
            fact/=i;
            int index=k/fact;
            ans+=to_string(nums[index]);
            nums.erase(nums.begin()+index);
            k%=fact;
        }
        return ans;
    }
};