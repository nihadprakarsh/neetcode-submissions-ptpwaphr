#include<bits/stdc++.h>
class Solution {
public:
    int dp[10001][11];
    int find(vector<int>&coins, int ind, int amount){
        if(amount < 0) return 1e5;
        if(amount == 0) return 0;
        if(ind == coins.size()) return 1e5;
        if(dp[amount][ind] != -1) return dp[amount][ind];
        int ans = 1e5;
        if(amount - coins[ind] >= 0){
            ans = min(ans,1+find(coins,ind,amount-coins[ind]));
        }
        ans = min(ans,find(coins,ind+1,amount));
        return dp[amount][ind]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = find(coins,0,amount);
        return ans == 1e5?-1:ans;
    }
};
