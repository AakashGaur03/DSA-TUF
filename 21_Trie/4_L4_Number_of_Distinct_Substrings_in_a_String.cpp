#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *links[26];

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
};

int countDistinctSubstring(string s) {
  int cnt = 0;
  Node *root = new Node();

  for (int i = 0; i < s.size(); i++) {
    Node *node = root;
    for (int j = i; j < s.size(); j++) {
      if (!node->containsKey(s[j])) {
        cnt++;
        node->put(s[j], new Node());
      }
      node = node->get(s[j]);
    }
  }
  return cnt + 1; // because also considering ""
}
// Time Complexity: (O(n^2)) — two nested loops, with each Trie operation taking
// (O(1)) time for a fixed alphabet of 26 lowercase letters.

// Space Complexity: (O(n^2)) — the Trie can contain up to (O(n^2)) nodes in the
// worst case.

int main() {
  cout << "4 L4 Number of Distinct Substrings in a String " << endl;
  // Number of distinct substrings in a string
  // Given a string s, determine the number of distinct substrings (including
  // the empty substring) of the given string.

  // A string B is a substring of a string A if B can be obtained by deleting
  // several characters (possibly none) from the start of A and several
  // characters (possibly none) from the end of A.

  // Two strings X and Y are considered different if there is at least one index
  // i such that the character of X at index i is different from the character
  // of Y at index i (X[i] != Y[i]).

  // Example 1:
  // Input : s = "aba"

  // Output : 6

  // Explanation :

  // The distinct substrings are "a", "ab", "ba", "b", "aba", "".

  // Example 2:
  // Input : s = "abc"

  // Output : 7

  // Explanation :

  // The distinct substrings are "a", "ab", "abc", "b", "bc", "c", "".

  // Example 1
  string s1 = "aba";
  cout << "Input: " << s1 << endl;
  cout << "Output: " << countDistinctSubstring(s1) << endl;

  cout << endl;

  // Example 2
  string s2 = "abc";
  cout << "Input: " << s2 << endl;
  cout << "Output: " << countDistinctSubstring(s2) << endl;
  return 0;
}