class Solution {
public:
    vector<int>row(int n){
        vector<int>ds;
        int ans=1;
        ds.push_back(1);
        for(int i=1;i<n;i++){
          ans*=(n-i);
          ans/=i;
          ds.push_back(ans);
        }
        return ds;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(row(i));
        }
        return ans;
    }
};