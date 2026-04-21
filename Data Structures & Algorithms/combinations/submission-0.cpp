class Solution {
public:
    vector<vector<int>> ans;
    void find(int i, int n, int k, vector<int>&temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i > n){
            return;
        }
        temp.push_back(i);
        find(i+1,n,k-1,temp);
        temp.pop_back();
        find(i+1,n,k,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        find(1,n,k,temp);
        return ans;
    }
};