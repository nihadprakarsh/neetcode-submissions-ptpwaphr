class Solution {
public:
    int jump(vector<int>& nums) {
        int mx = 0, curr=0, jumps=0;
        for(int i =0 ; i < nums.size()-1; ++i){
            mx = max(mx,i+nums[i]);
            if(i==curr){
                jumps++;
                curr=mx;
            }
        }
        return jumps;
    }
};
