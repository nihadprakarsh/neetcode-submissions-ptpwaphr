#include<bits/stdc++.h>
class Solution {
public:
    int dp[101][101];
    int find(int i, int j, string &word1, string &word2)
    {
        if(i==word1.size() && j==word2.size()) return 0;
        if(i==word1.size() && j < word2.size()) return (int)word2.size()-j;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e7;
        if(j==word2.size() && i < word1.size()) 
        ans = min(ans,1+find(i+1,j,word1,word2));
        else
        {
            if(word1[i] == word2[j]) ans = min(ans,find(i+1,j+1,word1,word2));
            else if(word1[i] != word2[j])
            {
                ans = min(ans,1+find(i,j+1,word1,word2));
                ans = min(ans,1+find(i+1,j,word1,word2));
                ans = min(ans,1+find(i+1,j+1,word1,word2));
            }
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,word1,word2);
    }
};
