class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        queue<pair<int,int>> qp, qa;

        for(int i = 0; i < n; i++) {
            qp.push({i,0});
            qa.push({i,m-1});

            pac[i][0] = 1;
            atl[i][m-1] = 1;
        }

        for(int j = 0; j < m; j++) {
            qp.push({0,j});
            qa.push({n-1,j});

            pac[0][j] = 1;
            atl[n-1][j] = 1;
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<int>>& vis) {
            while(!q.empty()) {
                auto [i,j] = q.front();
                q.pop();

                for(auto &[dx,dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;

                    if(ni>=0 && nj>=0 && ni<n && nj<m &&
                       !vis[ni][nj] &&
                       heights[ni][nj] >= heights[i][j]) {

                        vis[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }
        };

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};