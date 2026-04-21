class Solution {
public:
    vector<vector<int>> ans;

    void find(vector<int>& nums, int ind, vector<int>& temp) {
        ans.push_back(temp);

        for(int i = ind; i < nums.size(); i++) {
            // skip duplicates
            if(i > ind && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            find(nums, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<int> temp;
        find(nums, 0, temp);
        return ans;
    }
};