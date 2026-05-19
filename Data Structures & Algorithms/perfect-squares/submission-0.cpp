#include<bits/stdc++.h>
class Solution {
public:
    int dp[10001];
    int find(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 1e7;
        for(int i = 1;i*i <= n; ++i){
            if(n-(i*i)>=0)
            ans = min(ans,1+find(n-(i*i)));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};