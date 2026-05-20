#include<bits/stdc++.h>
class Solution {
public:
    int dp[5001][2];
    int find(int ind, vector<int>&price, int buy){
        if(ind >= price.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans =0;
        if(!buy){
            ans = max(ans,-price[ind]+find(ind+1,price,1));
        }
        else{
            ans = max(ans,price[ind]+find(ind+2,price,0));
        }
        ans = max(ans,find(ind+1,price,buy));
        return dp[ind][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return find(0,prices,0);
    }
};
