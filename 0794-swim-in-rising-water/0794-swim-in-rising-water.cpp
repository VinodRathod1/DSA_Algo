#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const int INF = numeric_limits<int>::max();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        dist[0][0] = grid[0][0];

        using T = tuple<int,int,int>; // (time, row, col)
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(dist[0][0], 0, 0);

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (t != dist[i][j]) continue; // skip outdated entry
            if (i == n - 1 && j == n - 1) return t; // reached destination

            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    int nt = max(t, grid[ni][nj]);
                    if (nt < dist[ni][nj]) {
                        dist[ni][nj] = nt;
                        pq.emplace(nt, ni, nj);
                    }
                }
            }
        }

        return -1; // should never happen
    }
};
