class Solution {
public:
    int isPallin(int i, int j, string &s){
        int count=0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--,j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i =0 ; i < s.size(); ++i){
            int odd = isPallin(i,i,s);
            int even = isPallin(i,i+1,s);
            ans += odd + even;
        }
        return ans;
    }
};
