class Solution {
public:
    bool possible(int mid, vector<int>& nums, int k){
        int count = 0;
        int sum = 0;
        for(auto &i:nums){
            if(sum + i > mid){
                count++;
                sum = i;
            }
            else
            sum += i;
        }
        if(sum) count++;
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid,ans;
        while(low <= high){
            mid = low + (high-low)/2;
            if(possible(mid,nums,k)){
                ans = mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};