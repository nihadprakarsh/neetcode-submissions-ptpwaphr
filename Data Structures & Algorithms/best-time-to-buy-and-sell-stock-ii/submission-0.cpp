#include<bits/stdc++.h>
class Solution {
public:
    int dp[30001][2];
    int find(vector<int>&prices,int ind, int buy){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans = 0;
        if(buy == 1){
            ans = prices[ind] + find(prices,ind+1,0);
            ans = max(ans,find(prices,ind+1,buy));
        }
        else{
            ans = -prices[ind] + find(prices,ind+1,1);
            ans = max(ans,find(prices,ind+1,buy));
        }
        return dp[ind][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return find(prices,0,0);
    }
};