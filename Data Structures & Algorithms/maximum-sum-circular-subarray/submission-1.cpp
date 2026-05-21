class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = INT_MIN, totalSum=0, sum =0;
        for(auto &i:nums){
            totalSum+=i;
        }
        int minMx = INT_MAX;
        for(auto &i:nums){
            sum+=i;
            minMx = min(minMx,sum);
            if(sum > 0)
            sum = 0;
        }

        mx = max(mx,totalSum-minMx);
        int mx1=INT_MIN;
        sum = 0;
        for(auto &i:nums){
            sum += i;
            mx1 = max(mx1,sum);
            if(sum < 0)
            sum = 0;
        }

        if(mx1 < 0) return mx1;

        return max(mx1,mx);
    }
};