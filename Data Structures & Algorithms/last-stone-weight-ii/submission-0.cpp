#include<bits/stdc++.h>
class Solution {
public:
    int dp[31][3001];
    int find(int ind, vector<int>&stones, int sum){
        if(ind == stones.size()) {
            if(sum < 0) return 1e8;
            return sum;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int f1 = find(ind+1,stones,sum+stones[ind]);
        int f2 = find(ind+1,stones,sum-stones[ind]);
        return dp[ind][sum]=min(f1,f2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return find(0,stones,0);
    }
};