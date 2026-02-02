#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int key, val, freq;
  Node *prev, *next;

  Node(int k, int v) {
    key = k;
    val = v;
    freq = 1;
    prev = next = nullptr;
  }
};

class List {
public:
  int size;
  Node *head, *tail;

  List() {
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void addFront(Node *node) {
    Node *temp = head->next;
    node->next = temp;
    node->prev = head;
    head->next = node;
    temp->prev = node;
    size++;
  }

  void removeNode(Node *node) {
    Node *p = node->prev;
    Node *n = node->next;
    p->next = n;
    n->prev = p;
    size--;
  }

  Node *removeLast() {
    if (size == 0)
      return nullptr;
    Node *node = tail->prev;
    removeNode(node);
    return node;
  }
};

class LFUCache {
private:
  // Maximum capacity of cache
  int capacity;

  // Current number of keys in cache
  int currSize;

  // Minimum frequency among all keys currently in cache
  int minFreq;

  // Maps key -> corresponding node
  unordered_map<int, Node *> keyNode;

  // Maps frequency -> Doubly Linked List of nodes with that frequency
  unordered_map<int, List *> freqListMap;

public:
  // Constructor
  LFUCache(int cap) {
    capacity = cap;
    currSize = 0;
    minFreq = 0;
  }

  // Updates frequency of a node when it is accessed (get / put existing key)
  void updateFreq(Node *node) {
    int freq = node->freq;

    // Remove node from its current frequency list
    freqListMap[freq]->removeNode(node);

    // If this node was the only one with minFreq, increment minFreq
    if (freq == minFreq && freqListMap[freq]->size == 0) {
      minFreq++;
    }

    // Increase node frequency
    node->freq++;

    // If list for new frequency does not exist, create it
    if (freqListMap.find(node->freq) == freqListMap.end()) {
      freqListMap[node->freq] = new List();
    }

    // Add node to front (most recently used) of new frequency list
    freqListMap[node->freq]->addFront(node);
  }

  // Returns value of key if present, otherwise -1
  int get(int key) {
    // If key does not exist
    if (keyNode.find(key) == keyNode.end())
      return -1;

    // Key exists → update frequency
    Node *node = keyNode[key];
    updateFreq(node);

    return node->val;
  }

  // Inserts or updates key-value pair
  void put(int key, int value) {
    // Edge case: capacity is zero
    if (capacity == 0)
      return;

    // If key already exists
    if (keyNode.find(key) != keyNode.end()) {
      Node *node = keyNode[key];
      node->val = value;

      // Update frequency since key is accessed
      updateFreq(node);
      return;
    }

    // If cache is full, evict LFU key
    if (currSize == capacity) {
      // Get the list with minimum frequency
      List *list = freqListMap[minFreq];

      // Remove least recently used node from that frequency list
      Node *nodeToRemove = list->removeLast();

      // Remove from key-node map
      keyNode.erase(nodeToRemove->key);

      currSize--;
    }

    // Create new node with frequency = 1
    Node *newNode = new Node(key, value);

    // Reset min frequency to 1 for new key
    minFreq = 1;

    // If frequency-1 list does not exist, create it
    if (freqListMap.find(1) == freqListMap.end()) {
      freqListMap[1] = new List();
    }

    // Insert new node into frequency-1 list
    freqListMap[1]->addFront(newNode);

    // Add to key-node map
    keyNode[key] = newNode;

    currSize++;
  }
};

int main() {
  cout << "23 L19 Implement LFU Cache" << endl;

  // LFUCache(int capacity) Initializes the object with the capacity of the data
  // structure.

  // int get(int key) Gets the value of the key if the key exists in the cache.
  // Otherwise, returns -1.

  // void put(int key, int value) Update the value of the key if present, or
  // inserts the key if not already present. When the cache reaches its
  // capacity, it should invalidate and remove the least frequently used key
  // before inserting a new item. For this problem, when there is a tie (i.e.,
  // two or more keys with the same frequency), the least recently used key
  // would be invalidated.

  // The thing is here we have to work acc to Frequency whenever there is a put
  // or get frequency updates

  // Here we will use some concept of LRU
  // WE will be using two hash maps
  // map<freq,DLL> freqList and map<key,node*> keyNode
  // capacity = 0 and freq = 0

  // put comes we check the keyNode if it exist if yes then incr the frequency
  // otherwise check size<capacity if yes then Add in freqList and keyNode
  // also increase capacity
  // if not capacity remove lest frequency one or if tie then LRU
  return 0;
}
