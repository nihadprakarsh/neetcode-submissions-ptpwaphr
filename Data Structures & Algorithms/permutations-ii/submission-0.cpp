class Solution {
public:
    vector<vector<int>> ans;

    void find(vector<int>& nums, vector<int>& temp, vector<int>& marked) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(marked[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !marked[i-1]) continue;

            marked[i] = 1;
            temp.push_back(nums[i]);

            find(nums, temp, marked);

            temp.pop_back();
            marked[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<int> temp;
        vector<int> marked(nums.size(), 0);
        find(nums, temp, marked);
        return ans;
    }
};