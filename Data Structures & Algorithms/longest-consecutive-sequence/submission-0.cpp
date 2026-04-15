class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums),end(nums));
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int j = nums[i] - 1;
            int count = 1;
            while(s.count(j)){
                count++;
                j--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
