class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        const int MOD = 1e9+7;

        for (auto &it : roads) {
            int u = it[0], v = it[1];
            long long wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, 1e18);  // must be long long
        vector<int> ways(n, 0);

        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;  // skip outdated

            for (auto &[v, wt] : adj[u]) {
                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v}); // <-- required
                }
                else if (d + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};
