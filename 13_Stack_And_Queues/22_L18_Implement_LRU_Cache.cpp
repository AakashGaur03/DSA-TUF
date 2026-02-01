#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int key;
  int val;
  Node *next;
  Node *prev;

public:
  Node(int key1, int val1, Node *next1, Node *prev1) {
    key = key1;
    val = val1;
    next = next1;
    prev = prev1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int key1, int val1) {
    key = key1;
    val = val1;
    next = nullptr;
    prev = nullptr;
  }
};

class LRUCache {
private:
  int capacity;
  unordered_map<int, Node *> mpp;
  Node *head;
  Node *tail;

  void deleteNodeDoublyLL(Node *node) {
    if (node == head || node == tail) {
      return;
    }
    Node *prev = node->prev;
    Node *front = node->next;
    prev->next = front;
    front->prev = prev;
  }

  void insertNodeAfterHeadDoublyLL(Node *node) {
    Node *temp = head->next;
    head->next = node;
    node->prev = head;
    node->next = temp;
    temp->prev = node;
  }

public:
  LRUCache(int cap) {
    capacity = cap;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) { // O(1)
    if (mpp.find(key) == mpp.end()) {
      return -1;
    }
    Node *node = mpp[key];
    deleteNodeDoublyLL(node);
    insertNodeAfterHeadDoublyLL(node);
    return node->val;
  }

  void put(int key, int val) { // O(1)
    if (mpp.find(key) != mpp.end()) {
      Node *node = mpp[key];
      node->val = val;
      deleteNodeDoublyLL(node);
      insertNodeAfterHeadDoublyLL(node);
    } else {
      if (mpp.size() == capacity) {
        Node *lru = tail->prev;
        mpp.erase(lru->key);
        deleteNodeDoublyLL(lru);
        delete lru;
      }
      Node *node = new Node(key, val);
      mpp[key] = node;
      insertNodeAfterHeadDoublyLL(node);
    }
  }
};

int main() {
  cout << "22 L18 Implement LRU Cache" << endl;

  // LRUCache(int capacity) Initialize the LRU cache with positive size
  // capacity.

  // int get(int key) Return the value of the key if the key
  // exists, otherwise return -1.

  // void put(int key, int value) Update the value of the key if the key exists.
  // Otherwise, add the key-value pair to the cache. If the number of keys
  // exceeds the capacity from this operation, evict the least recently used
  // key.

  // The functions get and put must each run in O(1) average time
  // complexity.

  // Doubly Linked List and Map

  // 22_L18_Implement_LRU_Cache_1
  // Doubly LL with head and tail -1 -1 values
  // and empty map DS
  // and a capacity acc to question

  // 22_L18_Implement_LRU_Cache_2
  // Now we insert the value after the head and insert the key in map with
  // address

  // 22_L18_Implement_LRU_Cache_3
  // Now we check if present in map and less than capacity
  // insert in DLL and map

  // 22_L18_Implement_LRU_Cache_4
  // Whenever we ask to get we check in Map then go to DLL and get the value
  // and delete that node and insert that in the Front

  // 22_L18_Implement_LRU_Cache_5
  // Whenever we ask to put then we check in map and capacity is full
  // then remove the Least one from DLL and from map and insert the new one at
  // top in DLL and insert in map too

  // If there is put and same value in map then update the DLL to put that in
  // front and update the value too
  return 0;
}
