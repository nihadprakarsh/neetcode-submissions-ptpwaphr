class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto &[dx, dy] : dir) {
                int ni = i + dx;
                int nj = j + dy;

                if(ni >= 0 && nj >= 0 &&
                   ni < n && nj < m &&
                   grid[ni][nj] == 2147483647) {

                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};