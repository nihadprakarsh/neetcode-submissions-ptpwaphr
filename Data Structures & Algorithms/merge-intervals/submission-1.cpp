class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int i=0;
        vector<vector<int>> ans;
        while(i < intervals.size())
        {
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] <= intervals[i][1]){
                intervals[i][0] = min(intervals[i][0],intervals[j][0]);
                intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                j++;
            }
            ans.push_back(intervals[i]);
            i=j;
        }
        return ans;

    }
};
