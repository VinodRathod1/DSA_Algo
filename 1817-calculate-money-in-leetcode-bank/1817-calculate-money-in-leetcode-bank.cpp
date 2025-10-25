class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int start=1;
        while(n>0){
            for(int i=0;i<min(n,7);i++){
                ans+=i+start;
            }
            n-=7;
            start++;
        }
        return ans;
    }
};