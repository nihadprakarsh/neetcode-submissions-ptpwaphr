class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>& grid){
        if(i<0 or i==grid.size() or j < 0 or j==grid[0].size() or vis[i][j]==1 or grid[i][j]==0) return 0;
        vis[i][j]=1;
        int ans = 1;
        ans+=dfs(i+1,j,vis,grid);
        ans+=dfs(i-1,j,vis,grid);
        ans+=dfs(i,j+1,vis,grid);
        ans+=dfs(i,j-1,vis,grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count=0;
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        for(int i =0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(vis[i][j] != 1 && grid[i][j]==1){
                    count = max(count,dfs(i,j,vis,grid));
                    
                }
            }
        }
        return count;
    }
};
