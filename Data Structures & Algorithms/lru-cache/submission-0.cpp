class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key_, int value_){
        key = key_;
        val = value_;
        next = nullptr;
        prev = nullptr;
    }
};  

class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    map<int,Node*> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;  
        tail->next = nullptr;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            int value = temp->val;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            Node* headNext = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = headNext;
            headNext->prev = temp;

            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete(temp);
            mp.erase(key);
        }
        else{
            if(mp.size() == capacity){
                Node* tmp = tail->prev;

                tmp->prev->next = tail;
                tail->prev = tmp->prev;

                mp.erase(tmp->key);
                delete(tmp);
            }
        }

        Node* newNode = new Node(key,value);
        Node* headNext = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = headNext;
        headNext->prev = newNode;

        mp[key] = newNode;
    }
};