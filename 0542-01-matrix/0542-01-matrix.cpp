class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans=mat;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>vis(n,vector<int>(m,0));
       queue<pair<int,pair<int,int>>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({0,{i,j}});
                vis[i][j]=2;

            }
        }
       }
     while(!q.empty()){
        auto it=q.front();q.pop();
        int dist=it.first;
        int u=it.second.first;
        int v=it.second.second;
       for(int k=0;k<4;k++){
          int i=u+dir[k][0];
          int j=v+dir[k][1];
         if(i>=0 and i<n and j>=0 and j<m and vis[i][j]!=2){
            vis[i][j]=2;
            ans[i][j]=dist+1;
            q.push({dist+1,{i,j}});
         }
       }
     }
      mat=ans;
       return mat;
    }
};