class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low =0, high=heights.size()-1;
        int ans =0;
        while(low < high)
        {
            int len = high-low;
            int brd = min(heights[low],heights[high]);
            ans = max(ans,len*brd);
            if(heights[low] >= heights[high])
            high--;
            else
            low++;
        }
        return ans;
    }
};
