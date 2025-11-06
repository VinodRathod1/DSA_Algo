class DSU {
public:
    vector<int> parent;
    DSU(int n) : parent(n + 1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[b] = a;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections) dsu.unite(e[0], e[1]);

        unordered_map<int, set<int>> online;
        for (int i = 1; i <= c; ++i){
            online[dsu.find(i)].insert(i);
        }
        vector<int> ans;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) {
                if (online[root].find(x) != online[root].end()) {
                    ans.push_back(x);                        
                } else if (!online[root].empty()) {
                    ans.push_back(*online[root].begin());  
                } else {
                    ans.push_back(-1);
                }
            } else {
                online[root].erase(x);
            }
        }
        return ans;
    }
};
