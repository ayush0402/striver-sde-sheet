class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        this->key = _key;
        this->val = _val;
        this->prev = NULL;
        this->next = NULL;
    }

};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity = 0;
    int size = 0;
    map <int, Node*> mep;

    void addNode(Node* node) {
        Node* secondNode = head->next;
        node->next = secondNode;
        node->prev = head;
        head->next = node;
        secondNode->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    LRUCache(int _capacity) {
        this->capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mep.find(key) != mep.end()) {
            Node* temp = mep[key];
            deleteNode(temp);
            addNode(temp);
            return temp->val;
        }
        else return -1;
    }

    void put(int key, int value) {
        if (mep.find(key) != mep.end()) {
            Node* temp = mep[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
        }
        else if (size == capacity) {
            Node* lastNode = tail->prev;
            mep.erase(lastNode->key);
            deleteNode(lastNode);
            lastNode->key = key;
            lastNode->val = value;
            addNode(lastNode);
            mep[key] = lastNode;
        }
        else {
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mep[key] = newNode;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
