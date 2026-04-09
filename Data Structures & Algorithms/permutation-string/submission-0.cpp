class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        for(auto &it:s1){
            m1[it]++;
        }

        int i = 0, j =0 ;
        while(j<s2.size())
        {
            m2[s2[j]]++;
            if(m1==m2) return true;
            while(m2[s2[j]] > m1[s2[j]]){
                m2[s2[i]]--;
                i++;
            }
            j++;
        }
        return false;
    }
};
