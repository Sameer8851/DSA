#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: 146. LRU Cache
 * Link: https://leetcode.com/problems/lru-cache/
 * Difficulty: Medium
 *
 * Description:
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 *   - LRUCache(int capacity) initializes the cache with a positive size capacity.
 *   - int get(int key) returns the value of the key if it exists, otherwise returns -1.
 *   - void put(int key, int value) updates or inserts the key-value pair.
 *
 * When the cache reaches its capacity, it should invalidate the least recently used item
 * before inserting a new one.
 *
 * Approach:
 * - Use a Doubly Linked List (DLL) + Hash Map.
 * - DLL maintains order of usage (most recent near head, least recent near tail).
 * - Hash Map provides O(1) access to nodes for update and deletion.
 */

struct Node {
    int key, val;
    Node *prev, *next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;  // Maps key to corresponding node in DLL
    int capacity;                  // Maximum capacity of cache
    Node *head, *tail;             // Dummy head and tail for easy insert/delete

    // ✅ Constructor: Initialize capacity and dummy nodes
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // ✅ Helper: Remove a node from the doubly linked list
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // ✅ Helper: Insert a node right after the head (mark as most recently used)
    void insertAfterHead(Node* node) {
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next = first;
        first->prev = node;
    }

    // ✅ Get value by key and mark as most recently used
    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);  // Move accessed node to front (most recent)
        return node->val;
    }

    // ✅ Insert or update key-value pair
    void put(int key, int value) {
        // If key already exists, update value and move to front
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } 
        else {
            // If cache is full, remove least recently used node (before tail)
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            // Insert new node as most recently used
            Node* node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }
};



