#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(const vector<vector<int>>& h, vector<vector<char>>& vis, int r, int c){
        int n = h.size(), m = h[0].size();
        vis[r][c] = 1;
        for (auto &d: dirs){
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (vis[nr][nc]) continue;
            // From ocean outward we can move to neighbor if neighbor height >= current
            if (h[nr][nc] >= h[r][c]) dfs(h, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int n = heights.size(), m = heights[0].size();
        vector<vector<char>> pac(n, vector<char>(m, 0)), atl(n, vector<char>(m, 0));
        
        // Pacific borders: top row and left column
        for (int j = 0; j < m; ++j) if (!pac[0][j]) dfs(heights, pac, 0, j);
        for (int i = 0; i < n; ++i) if (!pac[i][0]) dfs(heights, pac, i, 0);
        // Atlantic borders: bottom row and right column
        for (int j = 0; j < m; ++j) if (!atl[n-1][j]) dfs(heights, atl, n-1, j);
        for (int i = 0; i < n; ++i) if (!atl[i][m-1]) dfs(heights, atl, i, m-1);

        vector<vector<int>> res;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
