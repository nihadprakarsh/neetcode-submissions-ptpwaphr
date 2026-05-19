#include<bits/stdc++.h>
class Solution {
public:
    int dp[1001][1001];
    bool pallin(int i, int j, string &s){
        while(i<=j){
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] != s[j]) return false;
            i++,j--;
        }
        return dp[i][j]=true;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int len = 0; string ans = ""; 
        string temp = "";
        for(int i =0; i < s.size(); ++i){
            temp = "";
            for(int j = i; j < s.size(); ++j){
                temp.push_back(s[j]);
                if(pallin(i,j,s)){
                    if(temp.size() > len){
                        len = temp.size();
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
