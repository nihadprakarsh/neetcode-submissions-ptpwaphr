class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>&nums,int ind,vector<int>&temp)
    {
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        find(nums,ind+1,temp);
        temp.pop_back();
        find(nums,ind+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        find(nums,0,temp);
        return ans;
    }
};
