class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto &nei : adj[node]) {
            if (!vis[nei]) {
                if (!dfs(nei, node, adj, vis))
                    return false;
            }
            else if (nei != parent)
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        if (!dfs(0, -1, adj, vis))
            return false;

        for (auto &x : vis) {
            if (!x)
                return false;
        }

        return true;
    }
};