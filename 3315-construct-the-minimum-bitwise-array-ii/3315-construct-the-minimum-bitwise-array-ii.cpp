class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int x:nums){
            int cnt=0;
            int temp=x;
            while(temp&1){
                cnt++;
                temp>>=1;
            }
            if(cnt==0){
                ans.push_back(-1);
            }else{
                ans.push_back(x-(1<<(cnt-1)));
            }
            
        }
        return ans;
    }
};