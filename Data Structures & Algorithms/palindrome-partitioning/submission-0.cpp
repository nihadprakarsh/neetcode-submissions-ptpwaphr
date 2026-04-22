class Solution {
public:
    vector<vector<string>> ans;

    bool checkPallin(string &temp){
        int i = 0, j = temp.size()-1;
        while(i < j){
            if(temp[i] != temp[j]) return false;
            i++, j--;
        }
        return true;
    }

    void find(string &s, int i, vector<string>& v){
        if(i == s.size()){
            ans.push_back(v);
            return;
        }

        string temp = "";
        for(int j = i; j < s.size(); j++){
            temp.push_back(s[j]);

            if(checkPallin(temp)){
                v.push_back(temp);
                find(s, j+1, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        find(s, 0, v);
        return ans;
    }
};