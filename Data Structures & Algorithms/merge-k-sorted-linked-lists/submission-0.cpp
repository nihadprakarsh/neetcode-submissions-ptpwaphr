/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto cmp = [](ListNode* node1, ListNode* node2){
            return node1->val > node2->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);

        for(auto &vec:lists){
            if(vec != nullptr)
            pq.push(vec);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            dummy->next = node;
            dummy=dummy->next;
            node=node->next;
            if(node != nullptr){
                pq.push(node);
            }
        }
        return temp->next;
    }
};
