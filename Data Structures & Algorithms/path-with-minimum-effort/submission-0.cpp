class Solution {
public:
    typedef pair<int,pair<int,int>> pt;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        pq.push({0,{0,0}});
        vector<pair<int,int>> p = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            auto steps = node.first;
            auto i = node.second.first;
            auto j = node.second.second;
            if(i==n-1 and j==m-1) return steps;
            for(auto &ind:p){
                int di = i+ind.first;
                int dj = j+ind.second;
                if(di>=0 && di<n && dj>=0 && dj<m){
                    int len = abs(heights[i][j] - heights[di][dj]);
                    int mx = max(len,steps);
                    if(dist[di][dj] > mx)
                    {
                        dist[di][dj] = mx;
                        pq.push({dist[di][dj],{di,dj}});
                    }
                }
            }
        }
        return -1;
    }
};