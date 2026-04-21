class Solution {
public:
    int find(int ind, vector<int>& nums, int currXor) {
        if (ind == nums.size()) return currXor;
        return find(ind + 1, nums, currXor ^ nums[ind]) +
               find(ind + 1, nums, currXor);
    }

    int subsetXORSum(vector<int>& nums) {
        return find(0, nums, 0);
    }
};