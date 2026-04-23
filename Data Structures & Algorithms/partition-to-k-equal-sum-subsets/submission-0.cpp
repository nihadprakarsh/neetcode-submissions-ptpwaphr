#include<bits/stdc++.h>
class Solution {
public:
    int dp[1<<17];
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum % k != 0) return false;
        return find(nums,0,k,sum/k,sum/k);
    }
};