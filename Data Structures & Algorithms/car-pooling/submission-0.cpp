class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> m;
        for(auto &i:trips){
            m[i[1]]+=i[0];
            m[i[2]]-=i[0];
        }

        int sum = 0;
        for(auto &i:m){
            sum+=i.second;
            i.second = sum;

            if(i.second > capacity)
            return false;
        }

        return true;
    }
};