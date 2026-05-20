#include<bits/stdc++.h>
class Solution {
public:
    int dp[101][101][101];
    int find(int i, int j, int k, string &s1, string &s2, string &s3){
        if(k >= s3.size()) {
            return i==s1.size() and j==s2.size();
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool flag = false;
        if(s1[i] == s3[k] and s2[j] == s3[k])
        flag = flag or find(i+1,j,k+1,s1,s2,s3) or find(i,j+1,k+1,s1,s2,s3);
        else if(s1[i] == s3[k])
        flag = flag or find(i+1,j,k+1,s1,s2,s3);
        else if(s2[j] == s3[k])
        flag = flag or find(i,j+1,k+1,s1,s2,s3);
        return dp[i][j][k]=flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,s1,s2,s3);
    }
};
