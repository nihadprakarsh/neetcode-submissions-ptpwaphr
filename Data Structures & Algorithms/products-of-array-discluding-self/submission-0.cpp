class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        for(auto &it:nums) if(it==0) count++;
        if(count>=2) {
            vector<int>v(nums.size(),0);
            return v;
        }

        int p = 1;
        for(auto &i:nums) {
            if(i!=0) p*=i;
        }

        vector<int> ans(nums.size(),-1);
        for(int i =0; i< nums.size();++i){
            if(nums[i]==0){
                ans[i]=p;
            }
            else if(count==1){
                ans[i]=0;
            }
            else{
                ans[i]=p/nums[i];
            }
        }
        return ans;
    }
};
