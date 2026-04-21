class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>&nums,int target, int ind, vector<int>&temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(ind >= nums.size()){
            return;
        }


        if(target-nums[ind] >= 0){
            temp.push_back(nums[ind]);
            find(nums,target-nums[ind],ind,temp);
            temp.pop_back();
        }
        find(nums,target,ind+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        find(nums,target,0,temp);
        return ans;
    }
};
