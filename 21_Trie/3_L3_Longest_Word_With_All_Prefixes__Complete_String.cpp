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

  bool checkIfPrefixExists(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
        if (!node->isEnd())
          return false;
      } else {
        return false;
      }
    }
    return true;
  }
};

string completeString(vector<string> &nums) {
  Trie trie;
  for (auto &it : nums) {
    trie.insert(it);
  }

  string longest = "";
  for (auto &it : nums) {
    if (trie.checkIfPrefixExists(it)) {
      if (it.size() > longest.size()) {
        longest = it;
      } else if (it.size() == longest.size() && it < longest) {
        longest = it;
      }
    }
  }
  if (longest == "") {
    return "None";
  }

  return longest;
}

// Time Complexity: O(N * L)
// Space Complexity: O(N * L)

// N = Number of strings in the input vector
// L = Maximum length of a string
// Trie Space: O(N * L) in the worst case
// Auxiliary Space: O(1), excluding Trie storage

int main() {
  cout << "Longest Word with All Prefixes | COMPLETE STRING" << endl;
  // Longest Word with All Prefixes
  // Given a string array nums of length n. A string is called a complete string
  // if every prefix of this string is also present in the array nums.

  // Find the longest complete string in the array nums.

  // If there are multiple strings with the same length, return the
  // lexicographically smallest one and if no string exists, return "None"
  // (without quotes).

  // Example 1:
  // Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]

  // Output : ninja

  // Explanation :

  // The word "ninja" is the longest word which has all its prefixes present in
  // the array.

  // Example 2:
  // Input : nums = [ "ninja" , "night" , "nil" ]

  // Output : None

  // Explanation :

  // There is no string that has all its prefix present in array. So we return
  // None.

  vector<string> nums = {"n", "ni", "nin", "ninj", "ninja", "nil"};

  cout << completeString(nums) << endl;

  return 0;
}