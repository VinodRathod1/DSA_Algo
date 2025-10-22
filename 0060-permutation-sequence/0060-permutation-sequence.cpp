class Solution {
public:
    int cnt=0;
    string ans="";
    void rec(vector<int>&nums,vector<bool>&used,string& curr,int k){
        if(curr.size()==nums.size()){
            cnt++;
            if(cnt==k)ans=curr;
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                curr.push_back(nums[i]+'0');
                rec(nums,used,curr,k);
                if(!ans.empty())return ;
                curr.pop_back();
                used[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++)nums.push_back(i);
        vector<bool>used(n,false);
        string curr="";
        rec(nums,used,curr,k);
        return ans;
    }
};