class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    // remove node from DLL
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // insert node just after head
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            remove(node);
            insert(node);
        } else {
            if (mpp.size() == capacity) {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                remove(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insert(newNode);
            mpp[key] = newNode;
        }
    }
};
