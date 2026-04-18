class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int diff=INT_MAX,ind=-1;
        for(int i =0 ;i < arr.size(); ++i){
            if(diff > abs(arr[i]-x)){
                ind=i;
                diff=abs(arr[i]-x);
            }
        }
        int i = ind-1,j = ind+1;
        deque<int> dq;
        dq.push_front(arr[ind]);
        k--;
        while(k>0){
            int diffi=INT_MAX,diffj=INT_MAX;
            if(i>=0)
            diffi=abs(x-arr[i]);
            if(j<arr.size())
            diffj = abs(x-arr[j]);
            if(diffi <= diffj){
                dq.push_front(arr[i]);
                k--;
                i--;
            }
            else{
                dq.push_back(arr[j]);
                k--;
                j++;
            }
        }
        vector<int> ans;
        for(auto &i:dq){
            ans.push_back(i);
        }
        return ans;
    }
};