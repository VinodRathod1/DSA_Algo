class Solution {
public:
    void dfs(int i,vector<vector<int>>&c,vector<bool>&vis){
        vis[i]=true;
        for(int j=0;j<c.size();j++){
            if(!vis[j] && c[i][j]==1){
                dfs(j,c,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        vector<bool>vis(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,c,vis);
            }
        }
        return provinces;
    }
};