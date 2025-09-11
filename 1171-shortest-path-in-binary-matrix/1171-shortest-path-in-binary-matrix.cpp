class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dir = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        using Node = pair<int, pair<int,int>>; // {distance, {x,y}}
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto [currdist, cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;

            if (x == n-1 && y == n-1) return currdist;

            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    if (currdist + 1 < dist[nx][ny]) {
                        dist[nx][ny] = currdist + 1;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
