class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int time=0;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int x=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            time=max(time,x);
            for(int k=0;k<4;k++){
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                    q.push({time+1,{ni,nj}});
                    grid[ni][nj]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};