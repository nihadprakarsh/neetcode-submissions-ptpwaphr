class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>&nums, vector<int>&temp, vector<int>&marked, int count)
    {
        if(count == marked.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(marked[i] == 1) continue;
            marked[i] = 1;
            temp.push_back(nums[i]);
            find(nums,temp,marked,count+1);
            temp.pop_back();
            marked[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> marked(nums.size(),0);
        find(nums,temp,marked,0);
        return ans;
    }
};
