#include<bits/stdc++.h>
class Solution {
public:
    int dp[101][101];
    vector<pair<int,int>> v = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i, int j, vector<vector<int>>&matrix){
        return i>=0 and i < matrix.size() and j >=0 and j < matrix[0].size();
    }
    int dfs(int i, int j, vector<vector<int>>&matrix){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(auto &ind:v){
            int first = ind.first;
            int second = ind.second;
            int di = i+first;
            int dj = j+second;
            if(isValid(di,dj,matrix) && matrix[di][dj] > matrix[i][j]){
                ans = max(ans,1+dfs(di,dj,matrix));
            }
        }
        return dp[i][j]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
       int n = matrix.size(), m = matrix[0].size();
       int ans =0 ;
       for(int i =0 ; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans = max(ans,dfs(i,j,matrix));
            }
       }
       return ans;
    }
};
