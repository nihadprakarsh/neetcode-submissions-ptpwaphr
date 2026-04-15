class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int i=0,j=0,sum=0;
        m[0]=1; int count=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            int rem = sum-k;
            if(m[rem] > 0){
                count+=m[rem];
            }
            m[sum]++;
            j++;
        }
        return count;
    }
};