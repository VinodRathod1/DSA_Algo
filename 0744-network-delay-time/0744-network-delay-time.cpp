class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n+1); 
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // Min-heap: {time, node}
        using P = pair<int,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

          

            for (auto &[nei, wt] : adj[node]) {
                if (time + wt < dist[nei]) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1; // unreachable
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
