#include<bits/stdc++.h>
class Solution {
public:
    int dp[59][59];
    int find(int n, int count){
        if(n==0) return count >= 2;
        if(dp[n][count] != -1) return dp[n][count];
        int prod = 1;
        for(int i = 1; i <=n ; ++i){
            if(n-i>=0){
                prod = max(prod,i*find(n-i,count+1));
            }
        }
        return dp[n][count]=prod;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,0);
    }
};