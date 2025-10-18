#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int capacity;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertAfterHead(Node* node) {
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next = first;
        first->prev = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        // If already exists, update and move to head
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } 
        else {
            // If at capacity, remove LRU node (tail->prev)
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }
};
