class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        set<char> st;
        for(auto &i:t){
            m[i]++;
        }
        int i =0 , j=0,count=0;
        string temp = "",ans="";
        while(j < s.size()){
            char ch = s[j];
            temp.push_back(ch);
            if(m.count(ch)){
                m[ch]--;
                if(m[ch]<=0){
                    st.insert(ch);
                }
            }
            while(st.size()==m.size()){
                if(ans == "" || temp.size() < ans.size()){
                    ans = temp;
                }
                char ch1 = s[i];
                if(m.count(ch1)){
                    m[ch1]++;
                    if(m[ch1] > 0){
                        st.erase(ch1);
                    }
                }
                temp.erase(0,1);
                i++;
            }
            j++;
        }
        return ans;
    }
};
