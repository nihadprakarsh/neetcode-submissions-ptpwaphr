class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int low =0, high = people.size()-1;
        int res = 0;
        while(low<=high)
        {
            int limitleft = limit - people[high--];
            res++;
            if(low <= high && limitleft >= people[low]){
                low++;
            }
        }
        return res;
    }
};