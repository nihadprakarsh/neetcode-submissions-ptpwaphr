#include<bits/stdc++.h>
class Solution {
public:
    int dp[101][5001];
    int find(int amount, int ind, vector<int>&coins){
        if(amount == 0) return 1;
        if(ind >= coins.size()) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int ans = 0;
        if(amount - coins[ind] >= 0){
            ans += find(amount-coins[ind],ind,coins);
        }
        ans += find(amount,ind+1,coins);
        return dp[ind][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return find(amount,0,coins);
    }
};
