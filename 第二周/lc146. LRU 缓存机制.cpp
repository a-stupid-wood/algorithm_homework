class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (keys.find(key) == keys.end()) {
            return -1;
        }
        Node *node = keys[key];
        int value = node->value;
        removeFromList(node);
        insertToList(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            removeFromList(keys[key]);
            insertToList(key, value);
        }else {
            insertToList(key, value);
        }
        if (keys.size() > capacity) {
            keys.erase(tail->pre->key);
            removeFromList(tail->pre);
        }
    }

private:
     struct Node {
         int key;
         int value;
         Node *pre;
         Node *next;
     };

     Node *head;
     Node *tail;

     unordered_map<int, Node *> keys;
     int capacity;

     void removeFromList(Node *node) {
         node->pre->next = node->next;
         node->next->pre = node->pre;
         delete node;
     }

     Node* insertToList(int key, int value) {
         Node *node = new Node();
         node->key = key;
         node->value = value;
         node->next = head->next;
         head->next->pre = node;
         node->pre = head;
         head->next = node;
         keys[key] = node;
         return node;
     }
};
