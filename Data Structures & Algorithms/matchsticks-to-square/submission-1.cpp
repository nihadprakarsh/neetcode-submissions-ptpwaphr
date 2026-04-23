#include<bits/stdc++.h>
class Solution {
public:
    int dp[1<<15];
    bool find(vector<int>&m, int vis, int k, int target, int sum){
        if(k==1) return true;
        if(dp[vis] != -1) return dp[vis];
        bool flag = false;
        for(int i =0; i < m.size(); ++i)
        {
            if((vis & (1<<i))) continue;
            if(sum - m[i] >= 0){
                int temp = vis;
                temp = temp | (1<<i);
                if(sum - m[i] == 0){
                    flag = flag or find(m,temp,k-1,target,target);
                }
                else{
                    flag = flag or find(m,temp,k,target,sum-m[i]);
                }
            }
        }
        return dp[vis]=flag;
    }
    bool makesquare(vector<int>& m) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(begin(m),end(m),0);
        if(sum % 4 != 0) return false;
        int side = sum / 4;
        int vis = 0;
        return find(m,vis,4,sum/4,sum/4);
    }
};