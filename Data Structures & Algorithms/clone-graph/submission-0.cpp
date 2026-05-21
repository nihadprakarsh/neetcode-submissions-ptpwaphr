/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> mp;
        mp[node] = new Node(node->val);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto &nei:node->neighbors){
                if(mp.find(nei) == mp.end()){
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mp[node]->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
};
