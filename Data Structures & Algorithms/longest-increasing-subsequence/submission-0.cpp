class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(auto &i:nums){
            if(temp.empty() || temp.back() < i){
                temp.push_back(i);
            }
            else{
                int lb = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
                temp[lb] = i;
            }
        }
        return temp.size();
    }
};
