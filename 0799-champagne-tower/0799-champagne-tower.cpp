class Solution {
public:
    double solve(int poured,int q,int g,vector<vector<double>>&dp){
        if(q<0 || g<0 || q<g)return 0;
        if(q==0 && g==0)return poured;
        if(dp[q][g]!=-1.0)return dp[q][g];
        double left=(solve(poured,q-1,g-1,dp)-1)/2.0;
        double right=(solve(poured,q-1,g,dp)-1)/2.0;
        if(left<0)left=0.0;
        if(right<0)right=0.0;
        return dp[q][g]=left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(100,vector<double>(100,-1.0));
        return min(1.0,solve(poured,query_row,query_glass,dp));
    }
};