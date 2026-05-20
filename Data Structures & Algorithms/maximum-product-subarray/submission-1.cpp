class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            ans = max(ans,max(pre,suff));
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
        }
        return ans;
    }
};
