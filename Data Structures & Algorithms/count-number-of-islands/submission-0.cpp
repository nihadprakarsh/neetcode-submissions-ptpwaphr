class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<char>>& grid){
        if(i<0 or i==grid.size() or j < 0 or j==grid[0].size() or vis[i][j]==1 or grid[i][j]=='0') return;
        vis[i][j]=1;
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count=0;
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        for(int i =0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(vis[i][j] != 1 && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};
