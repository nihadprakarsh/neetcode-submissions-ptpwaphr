class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n+1);
        for(auto &i:p){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i =0 ; i < n; ++i){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto &children:adj[node]){
                indegree[children]--;
                if(indegree[children] == 0)
                q.push(children);
            }
        }

        for(auto &i:indegree){
            if(i>0) return false;
        }
        return true;
    }
};
