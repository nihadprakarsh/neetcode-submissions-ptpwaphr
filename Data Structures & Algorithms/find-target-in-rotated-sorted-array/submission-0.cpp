class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int low =0 , high = nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(target>=nums[low] and target <=nums[mid]){
                    high=mid;
                }
                else
                low=mid+1;
            }
            else{
                if(target>=nums[mid] and target<=nums[high]){
                    low=mid;
                }
                else
                high=mid-1;
            }
        }
        return -1;
    }
};
