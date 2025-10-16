class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>count(value,0);
        for(int num:nums){
            int rem=(num%value+value)%value;
            count[rem]++;
        }
        int mex=0;
        while(true){
           int r=mex%value;
           if(count[r]>0){
            count[r]--;
            mex++;
           }else{
            return mex;
           }
        }
    }
};