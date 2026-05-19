class Solution {
public:
    int isPallin(int i, int j, string &s){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--,j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = -1;
        for(int i =0 ; i < s.size(); ++i){
            int odd = isPallin(i,i,s);
            int even = isPallin(i,i+1,s);
            int mx = max(odd,even);
            if(mx > maxLen){
                maxLen = mx;
                start = i - (maxLen - 1)/2;
            }
        }
        return s.substr(start,maxLen);
    }       
};
