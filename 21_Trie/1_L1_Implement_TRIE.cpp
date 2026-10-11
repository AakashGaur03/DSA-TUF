#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *links[26];
  bool flag = false;

  Node() {
    for (int i = 0; i < 26; i++) {
      links[i] = nullptr;
    }
  }

  bool containsKey(char ch) {
    // Return True if exists
    return links[ch - 'a'] != NULL;
  }
  void put(char ch, Node *node) {
    // Put the Character into new node
    links[ch - 'a'] = node;
  }
  Node *get(char ch) { return links[ch - 'a']; }

  void setEnd() {
    // Set last flag to True
    flag = true;
  }

  bool isEnd() {
    // Return last Flag value
    return flag;
  }
};

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    // TC O(N)
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      // Moves to Reference Trie
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool search(string word) {
    // TC O(N)
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  bool startsWith(string word) {
    // TC O(N)
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        return false;
      }
      node = node->get(word[i]);
    }
    return true;
  }
};

// Time Complexity:
// insert()     -> O(N)
// search()     -> O(N)
// startsWith() -> O(N)

// Space Complexity:
// insert()     -> O(N) in the worst case for newly created nodes
// search()     -> O(1) auxiliary space
// startsWith() -> O(1) auxiliary space

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  cout << "1 L1. Implement TRIE | INSERT | SEARCH | STARTSWITH" << endl;

  //   Implement Trie (Prefix Tree)
  // A trie (pronounced as "try") or prefix tree is a tree data structure used
  // to efficiently store and retrieve keys in a dataset of strings. There are
  // various applications of this data structure, such as autocomplete and
  // spellchecker.

  // Implement the Trie class:

  // Trie() Initializes the trie object.
  // void insert(String word) Inserts the string word into the trie.
  // boolean search(String word) Returns true if the string word is in the trie
  // (i.e., was inserted before), and false otherwise. boolean startsWith(String
  // prefix) Returns true if there is a previously inserted string word that has
  // the prefix prefix, and false otherwise.

  //   ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]

  // [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
  // Output
  // [null, null, true, false, true, null, true]

  // Explanation
  // Trie trie = new Trie();
  // trie.insert("apple");
  // trie.search("apple");   // return True
  // trie.search("app");     // return False
  // trie.startsWith("app"); // return True
  // trie.insert("app");
  // trie.search("app");     // return True

  // Refer 1_L1_Implement_TRIE_1,1_L1_Implement_TRIE_2,1_L1_Implement_TRIE_3

  Trie trie;

  trie.insert("apple");

  cout << boolalpha;
  cout << trie.search("apple") << endl;   // true
  cout << trie.search("app") << endl;     // false
  cout << trie.startsWith("app") << endl; // true

  trie.insert("app");

  cout << trie.search("app") << endl; // true
  return 0;
}