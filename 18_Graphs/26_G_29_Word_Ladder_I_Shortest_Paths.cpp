#include <bits/stdc++.h>
using namespace std;

//  N is Number of nodes
//  M is Number of Edges

int ladderLength(string startWord, string targetWord,
                 vector<string> &wordList) {
  // TC O(wordLength *26 * wordList)
  // SC O(N)
  queue<pair<string, int>> q;

  // Queue stores {currentWord, stepsTaken}
  q.push({startWord, 1});

  // Store all words for fast lookup
  unordered_set<string> st(wordList.begin(), wordList.end());
  // if it exist it erase it
  st.erase(startWord);

  while (!q.empty()) {
    string word = q.front().first;
    int steps = q.front().second;
    q.pop();

    if (word == targetWord) {
      return steps;
    }

    // wordList* wordLength * 26
    // Try changing every character
    for (int i = 0; i < word.size(); i++) {
      char original = word[i];

      // Replace current character from a -> z
      for (char ch = 'a'; ch <= 'z'; ch++) {
        word[i] = ch;
        // if it exists in the set
        if (st.find(word) != st.end()) {
          st.erase(word);
          q.push({word, steps + 1});
        }
      }
      word[i] = original;
    }
  }
  return 0;
}

int main() {
  cout << "26 G 29 Word Ladder I Shortest Paths" << endl;

  //   Given two distinct words startWord and targetWord, and a list denoting
  //   wordList of unique words of equal lengths. Find the length of the
  //   shortest transformation sequence from startWord to targetWord.
  // Keep the following conditions in mind:

  // A word can only consist of lowercase characters.
  // Only one letter can be changed in each transformation.
  // Each transformed word must exist in the wordList including the targetWord.
  // startWord may or may not be part of the wordList

  // Note: If no possible way to transform sequence from startWord to targetWord
  // return 0

  // Refer 26_G_29_Word_Ladder_I_Shortest_Paths_1 for Example

  // We will go by word to word and try changing each letter from a to z and see
  // updated one is in wordList or not

  // we will do BFS Traversal
  // Refer 26_G_29_Word_Ladder_I_Shortest_Paths_2

  // We will take set DS and keep all wordList elements in it so it is easy to
  // search and in less TC
  string startWord = "hit";
  string targetWord = "cog";

  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  int ans = ladderLength(startWord, targetWord, wordList);

  cout << "Shortest Transformation Length: " << ans << endl;

  return 0;
}