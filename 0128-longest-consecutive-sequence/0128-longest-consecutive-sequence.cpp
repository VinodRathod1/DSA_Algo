class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        int cnt=0;
        int x=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                cnt=1;
                 x=it;
                 while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                 }
                 longest=max(longest,cnt);
            }
        }
        return longest;
    }
};