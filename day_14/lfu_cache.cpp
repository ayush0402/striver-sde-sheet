class Node {
public:
    int key, val, freq;
    Node* prev;
    Node* next;
    Node(int _key, int _val) {
        this->key = _key;
        this->val = _val;
        this->freq = 0;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LFUCache {
private:
    void addAfterHead(Node* node, int freq) {
        node->freq = freq;
        Node* head = freqDLL[freq].first;
        Node* tail = freqDLL[freq].second;
        Node* nextToHead = head->next;
        node->prev = head;
        node->next = nextToHead;
        head->next = node;
        nextToHead->prev = node;
    }
    void promote(Node* node) {
        int freq = (node->freq) + 1;
        Node* head = freqDLL[node->freq].first;
        if (node->freq == leastFreq) {
            if (head->next->key == -1) {
                leastFreq++;
            }
        }
        if (freqDLL.find(freq) != freqDLL.end()) {
            addAfterHead(node, freq);
        }
        else {
            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);
            head->next = tail; tail->prev = head;
            freqDLL.insert({freq, {head, tail}});
            addAfterHead(node, freq);
        }
    }
    void deleteNode(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    void addNew(Node* node) {

    }
public:
    map <int, pair<Node*, Node*>> freqDLL;
    map <int, Node*> keyToNode;

    int capacity; int size = 0; int leastFreq = 1;
    LFUCache(int _capacity) {
        this->capacity = _capacity;
    }

    int get(int key) {
        if (capacity == 0)return -1;
        if (keyToNode.find(key) != keyToNode.end()) {
            int res = keyToNode[key]->val;
            deleteNode(keyToNode[key]);
            promote(keyToNode[key]);
            return res;
        }
        else return -1;
    }

    void put(int key, int value) {
        if (capacity == 0)return;
        if (keyToNode.find(key) != keyToNode.end()) {
            keyToNode[key]->val = value;
            deleteNode(keyToNode[key]);
            promote(keyToNode[key]);
        }
        else {
            if (size == capacity) {
                Node* head = freqDLL[leastFreq].first;
                Node* tail = freqDLL[leastFreq].second;
                Node* todelete = tail->prev;
                keyToNode.erase(todelete->key);
                deleteNode(todelete);
                size--;
            }
            Node* add = new Node(key, value);
            size++;
            promote(add);
            leastFreq = 1;
            keyToNode.insert({key, add});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
