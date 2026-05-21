class Solution {
public:
    vector<int> parent,size;
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void UnionBySize(int u, int v){
        int a = find(u);
        int b = find(v);

        if(a==b) return;

        parent[a] = b;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
        for(auto &i:edges){
            UnionBySize(i[0],i[1]);
        }
        unordered_set<int> st;
        for(auto &i:parent){
            st.insert(find(i));
        }
        return st.size();
    }
};
