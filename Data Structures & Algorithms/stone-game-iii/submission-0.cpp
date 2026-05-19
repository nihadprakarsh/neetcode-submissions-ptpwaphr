#include<bits/stdc++.h>
class Solution {
public:
    int dp[50001];
    int find(vector<int>&s, int ind){
        if(ind == s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MIN;
        ans = max(ans,s[ind]-find(s,ind+1));
        if(ind+1 < s.size())
        ans = max(ans,s[ind]+s[ind+1]-find(s,ind+2));
        if(ind+2 < s.size())
        ans = max(ans,s[ind]+s[ind+1]+s[ind+2]-find(s,ind+3));

        return dp[ind]=ans;

    }
    string stoneGameIII(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        int ans = find(s,0);
        if(ans < 0)
        return "Bob";
        else if(ans > 0)
        return "Alice";
        return "Tie";
    }
};