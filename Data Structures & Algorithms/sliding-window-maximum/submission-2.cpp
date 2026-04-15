class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i =0, j =0;
        vector<int> ans;
        while(j < nums.size()){
            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            while(dq.front() < i){
                dq.pop_front();
            }
            if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
