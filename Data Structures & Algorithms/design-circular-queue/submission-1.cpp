class MyCircularQueue {
private:
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};
    int space;
    ListNode* left;
    ListNode* right;
public:
    MyCircularQueue(int k) {
        left = new ListNode(0);
        right = left;
        space = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        ListNode* curr = new ListNode(value);
        if(isEmpty()){
            left->next = curr;
            right = curr;
        }
        else{
            right->next = curr;
            right=curr;
        }
        space--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        ListNode* tmp = left->next;
        left->next=left->next->next;
        delete tmp;
        if(!left->next){
            right=left;
        }
        space++;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return right->val;
    }
    
    bool isEmpty() {
        return left->next == nullptr;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */