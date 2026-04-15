class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> st;
        int i = 0, j =0 ;
        while(j < nums.size()){
            st.insert(nums[j]);
            if(j-i+1==k){
                ans.push_back(*st.rbegin());
                st.erase(st.lower_bound(nums[i++]));
            }
            j++;
        }
        return ans;
    }
};
