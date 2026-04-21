class Solution {
public:
    vector<string> ans;
    void find(int n, int open, string &temp){
        if(n==0){
            if(open == 0)
            ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        find(n-1,open+1,temp);
        temp.pop_back();
        if(open > 0){
            temp.push_back(')');
            find(n-1,open-1,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        find(n*2,0,temp);
        return ans;
    }
};
