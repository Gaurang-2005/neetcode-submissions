class Node {
public:
    int val;
    Node* next = nullptr;
    Node(int val) : val(val) {}
};

class LRUCache {
    unordered_map<int, int> store;
    Node* head = nullptr;
    Node* end = nullptr;
    int cap;
public:
    LRUCache(int capacity) : cap(capacity) {
        store.reserve(capacity);
    }
    
    int get(int key) {
        if (store.find(key) == store.end()) return -1;
        if (store.size() < 2) return store.at(key);
        if (head -> val == key) {
            auto temp = head;
            if (head -> next) head = head -> next;
            if (end != temp) end -> next = temp;
            end = end -> next;
            end -> next = nullptr;
            return store.at(key);
        }
        auto prev = head;
        auto temp = head -> next;
        while (temp && temp -> val != key) {
            prev = temp;
            temp = temp -> next;
        }
        if (!temp)
            return -1;

        if (temp == end)
            return store.at(key);
        prev -> next = temp -> next;
        end -> next = temp;
        end = temp;
        end -> next = nullptr;
        return store.at(key);
    }
    
    void put(int key, int value) {
        if (store.find(key) != store.end()) {
            store[key] = value;
            if (store.size() < 2) {
                return;
            }
            if (head -> val == key) {
                auto temp = head;
                if (head -> next) head = head -> next;
                if (end != temp) end -> next = temp;
                end = end -> next;
                end -> next = nullptr;
                return;
            }
            auto prev = head;
            auto temp = head -> next;
            while (temp && temp -> val != key) {
                prev = temp;
                temp = temp -> next;
            }
            if (temp == end) return;
            prev -> next = temp -> next;
            if (end!=temp)end -> next = temp;
            end = temp;
            end -> next = nullptr;
        }
        else {
            if (head) {
                if (store.size() + 1 <= cap) {
                    end -> next = new Node(key);
                    end = end -> next;
                }
                else {
                    auto temp = head;
                    head = head -> next;
                    store.erase(temp -> val);
                    delete temp;
                    if (cap > 1) {
                        end -> next = new Node(key);
                        end = end -> next;
                    }
                    else {
                        head = new Node(key);
                        end = head;
                    }
                }
            } 
            else {
                head = new Node(key);
                end = head;
            }
            
            store[key] = value;
        }
    }
};
