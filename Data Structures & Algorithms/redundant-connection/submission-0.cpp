class Solution {
public:
    bool hasCycle(vector<vector<int>>&v,int src,int n)
    {
        queue<pair<int,int>> q;
        vector<int> vis(n+1,0);
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty())
        {
            auto node = q.front().first;
            auto parent = q.front().second;
            q.pop();
            for(auto &childNode : v[node])
            {
                if(vis[childNode] == 1 && childNode != parent)
                return true;
                if(childNode != parent)
                {
                    vis[childNode] = 1;
                    q.push({childNode,node});
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> v(n+1);
        for(auto &it : edges){
            int node1 = it[0];
            int node2 = it[1];
            v[node1].push_back(node2);
            v[node2].push_back(node1);
            if(hasCycle(v,node1,n))
            return it;
        }
        return {};
    }
};