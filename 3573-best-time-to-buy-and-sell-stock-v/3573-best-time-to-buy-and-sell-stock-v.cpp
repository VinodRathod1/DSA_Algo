class Solution {
    public:
    long long maximumProfit(vector<int>& a, int k) {
        int n=a.size();
        const long long m=-4e18;
        vector<long long> b(k+1,m), s(k+1,m), c(k+1,m);
        c[0]=0;
        for(int i=0;i<n;i++){
            int p=a[i];
            for(int j=k;j>=1;j--){
                b[j]=max(b[j],c[j-1]-p);
                s[j]=max(s[j],c[j-1]+p);
                c[j]=max(c[j],max(b[j]+p,s[j]-p));
            }
        }
        long long r=0;
        for(int j=0;j<=k;j++) r=max(r,c[j]);
        return r;
    }
};
