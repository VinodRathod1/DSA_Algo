#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& hei) {
        int n = hei.size();
        int m = hei[0].size();
        if (n <= 2 || m <= 2) return 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

 
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;

        // Push boundary cells
        for (int i = 0; i < n; i++) {
            pq.push({hei[i][0], {i, 0}});
            pq.push({hei[i][m-1], {i, m-1}});
            vis[i][0] = vis[i][m-1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({hei[0][j], {0, j}});
            pq.push({hei[n-1][j], {n-1, j}});
            vis[0][j] = vis[n-1][j] = true;
        }

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int water = 0;

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            for (auto dir : directions) {
                int u = x + dir.first;
                int v = y + dir.second;

                if (u < 0 || v < 0 || u >= n || v >= m || vis[u][v])
                    continue;

                vis[u][v] = true;

                water += max(0, h - hei[u][v]);

                pq.push({max(h, hei[u][v]), {u, v}});
            }
        }

        return water;
    }
};
