/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });
        int i=0;
        while(i<intervals.size()){
            auto start = intervals[i].start;
            auto end = intervals[i].end;


            int j = i+1;
            if(j < intervals.size()){
                auto start1 = intervals[j].start;
                auto end1 = intervals[j].end;
                if(start1 < end)
                return false;
            }
            i++;
        }
        return true;
    }
};
