class Solution {
public:
    bool possible(int mid, vector<int>&piles, int h){
        int ans = 0;
        for(auto &i:piles){
            if(i%mid==0)
            ans+=i/mid;
            else
            ans+=i/mid+1;
        }
        return ans <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX, mid, ans = -1;
        while(low <= high){
            mid = low+(high-low)/2;
            if(possible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};
