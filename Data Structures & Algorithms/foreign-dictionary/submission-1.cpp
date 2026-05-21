class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,int> indegree;
        unordered_map<char,vector<char>> adj;
        for(auto &i:words){
            for(auto &j:i){
                indegree[j] = 0;
            }
        }
        for(int i = 0; i < words.size()-1; ++i){
            string a = words[i];
            string b = words[i+1];
            int mn = min(a.size(),b.size());
            if(a.substr(0,mn) == b.substr(0,mn) && a.size() > b.size()) return "";
            for(int j=0;j<mn;j++)
            {
                if(a[j] != b[j]){
                    adj[a[j]].push_back(b[j]);
                    indegree[b[j]]++;
                    break;
                }
            }
        }
        queue<char> q;
        for(auto &i:indegree){
            if(i.second == 0)
            q.push(i.first);
        }

        string ans = "";
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &ch:adj[node]){
                indegree[ch]--;
                if(indegree[ch] == 0)
                q.push(ch);
            }
        }
        return ans.size()==indegree.size()?ans:"";
    }
};
