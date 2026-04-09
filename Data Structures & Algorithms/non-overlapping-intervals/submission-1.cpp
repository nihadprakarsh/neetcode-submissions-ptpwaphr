class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals),cmp);
        int i=0,ans=0;
        // vector<vector<int>> ans;
        while(i < intervals.size())
        {
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] < intervals[i][1]){
                ans++;
                j++;
            }
            i=j;
        }
        return ans;
    }
};
