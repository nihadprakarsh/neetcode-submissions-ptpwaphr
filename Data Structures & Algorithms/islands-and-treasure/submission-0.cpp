class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>&grid){
        return i>=0 and j>=0 and i<grid.size() and j<grid[0].size();
    }
    void dfs(int i,int j,vector<vector<int>>&grid, int steps){
        vector<pair<int,int>> v = {{0,1},{1,0},{0,-1},{-1,0}};

        if(grid[i][j]!=0 and grid[i][j]!=-1)
            grid[i][j]=steps;

        for(auto &ind:v){
            int di = i+ind.first;
            int dj = j+ind.second;
            if(isValid(di,dj,grid) and grid[di][dj] != -1)
            {
                if(steps+1<grid[di][dj])
                    dfs(di,dj,grid,steps+1);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i =0 ; i < n; ++i){
            for(int j =0; j < m; ++j){
                if(grid[i][j] == 0){
                    dfs(i,j,grid,0);
                }
            }
        }
    }
};
