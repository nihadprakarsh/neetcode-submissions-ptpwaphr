class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode* prev = nullptr;
        while(node != nullptr){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);   
        dummy->next = head;                  
        ListNode* prev = dummy;              

        while(head != nullptr){
            ListNode* temp = head;          
            for(int i = 1; i < k; ++i){
                if(temp->next == nullptr) return dummy->next;
                temp = temp->next;
            }

            ListNode* nextNode = temp->next; 
            temp->next = nullptr;            

            ListNode* l1 = reverse(head);

            prev->next = l1;                 

            head->next = nextNode;           

            prev = head;                     
            head = nextNode;
        }
        return dummy->next;                  
    }
};