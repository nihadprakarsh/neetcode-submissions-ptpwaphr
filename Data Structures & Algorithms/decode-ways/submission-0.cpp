#include<bits/stdc++.h>
class Solution {
public:
    int dp[101];
    int find(string &s, int ind){
        if(ind == s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];
        int ans = 0;
        if(ind+1<s.size()){
            int ch = s[ind]-'0';
            int ch1 = s[ind+1]-'0';
            int num = ch*10+ch1;
            if(num>=10 && num <= 26){
                ans += find(s,ind+2);
            }
        }
        if(s[ind] != '0'){
            ans+=find(s,ind+1);
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return find(s,0);
    }
};
