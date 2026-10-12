#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *links[26];
  int countEndsWith = 0;
  int countPrefix = 0;

  Node() {
    for (int i = 0; i < 26; i++) {
      links[i] = nullptr;
    }
  }
  bool containsKey(char ch) {
    // Return True if exists
    return (links[ch - 'a'] != NULL);
  }

  Node *get(char ch) { return links[ch - 'a']; }

  void put(char ch, Node *node) {
    // Put the Character into new node
    links[ch - 'a'] = node;
  }

  void increaseEnd() { countEndsWith++; }
  void increasePrefix() { countPrefix++; }

  void deleteEnd() { countEndsWith--; }

  void reducePrefix() { countPrefix--; }

  int getCountEnd() { return countEndsWith; }

  int getPrefix() { return countPrefix; }
};

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
      node->increasePrefix();
    }
    node->increaseEnd();
  }

  int countWordsEqualTo(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
      } else {
        return 0;
      }
    }
    return node->getCountEnd();
  }

  int countWordsStartingWith(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
      } else {
        return 0;
      }
    }
    return node->getPrefix();
  }

  void erase(string word) {
    Node *node = root;

    // First, check whether the complete word exists.
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        return;
      }

      node = node->get(word[i]);
    }

    // Check whether this exact word was inserted.
    if (node->getCountEnd() == 0) {
      return;
    }

    // Traverse again and reduce prefix counts.
    node = root;

    for (int i = 0; i < word.size(); i++) {
      node = node->get(word[i]);
      node->reducePrefix();
    }

    // Remove one occurrence of the complete word.
    node->deleteEnd();
  }
};

// Time Complexity:
// insert()                  -> O(N)
// countWordsEqualTo()       -> O(N)
// countWordsStartingWith()  -> O(N)
// erase()                   -> O(N)

// Space Complexity:
// insert()                  -> O(N) in the worst case for newly created nodes
// countWordsEqualTo()       -> O(1) auxiliary space
// countWordsStartingWith()  -> O(1) auxiliary space
// erase()                   -> O(1) auxiliary space

// N = length of the input word or prefix
// Each Trie node stores 26 pointers and 2 counters, so space per node is O(1).
// Total Trie space: O(T), where T is the total number of nodes.

int main() {
  cout << "2 L2 Implement Trie-2 | INSERT | countWordsEqualTo() | "
          "countWordsStartingWith() | C++ | Java"
       << endl;

  // Implement Trie II (Prefix Tree)
  // A trie (pronounced as "try") or prefix tree is a tree data structure used
  // to efficiently store and retrieve keys in a dataset of strings. There are
  // various applications of this data structure, such as autocomplete and
  // spellchecker.

  // Implement the Trie class:

  // Trie(): Initializes the trie object.
  // void insert(string word): Inserts the string word into the trie.
  // int countWordsEqualTo(string word): Returns the number of instances of the
  // string word in the trie. int countWordsStartingWith(string prefix): Returns
  // the number of strings in the trie that have the string prefix as a prefix.
  // void erase(string word): Erases the string word from the trie.
  // Constraints:

  // 1 <= word.length, prefix.length <= 2000
  // word and prefix consist only of lowercase English letters.
  // At most 3 * 10^4 calls in total will be made to insert, countWordsEqualTo,
  // countWordsStartingWith, and erase. It is guaranteed that for any function
  // call to erase, the string word will exist in the trie.

  // Example 1:

  // Input
  // ["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith",
  // "erase", "countWordsEqualTo", "countWordsStartingWith", "erase",
  // "countWordsStartingWith"]
  // [[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"],
  // ["app"], ["apple"], ["app"]] Output [null, null, null, 2, 2, null, 1, 1,
  // null, 0]

  // Explanation
  // Trie trie = new Trie();
  // trie.insert("apple"); // Inserts "apple".
  // trie.insert("apple"); // Inserts another "apple".
  // trie.countWordsEqualTo("apple"); // There are two instances of "apple" so
  // return 2. trie.countWordsStartingWith("app"); // "app" is a prefix of
  // "apple" so return 2. trie.erase("apple"); // Erases one "apple".
  // trie.countWordsEqualTo("apple"); // Now there is only one instance of
  // "apple" so return 1. trie.countWordsStartingWith("app"); // return 1
  // trie.erase("apple"); // Erases "apple". Now the trie is empty.
  // trie.countWordsStartingWith("app"); // return 0

  Trie trie;

  trie.insert("apple");
  trie.insert("apple");

  cout << trie.countWordsEqualTo("apple") << endl;    // 2
  cout << trie.countWordsStartingWith("app") << endl; // 2

  trie.erase("apple");

  cout << trie.countWordsEqualTo("apple") << endl;    // 1
  cout << trie.countWordsStartingWith("app") << endl; // 1

  trie.erase("apple");

  cout << trie.countWordsStartingWith("app") << endl; // 0

  return 0;
}