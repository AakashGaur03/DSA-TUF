#include <bits/stdc++.h>
using namespace std;

//  N is Number of nodes
//  M is Number of Edges

vector<vector<string>> ladderLength(string beginWord, string endWord,
                                    vector<string> &wordList) {
  // TC O(Depends on Question cant be measured)
  // SC O(N)
  // TLE On leetcode for this Solution will discuss for that too
  unordered_set<string> st(wordList.begin(), wordList.end());
  queue<vector<string>> q;
  q.push({beginWord});
  vector<string> usedOnLevel;
  usedOnLevel.push_back(beginWord);
  int level = 0;
  vector<vector<string>> ans;

  while (!q.empty()) {
    vector<string> vec = q.front();
    q.pop();
    if (vec.size() > level) {
      // Starting on new Level
      level++;
      // Erase all the words that has been used in Prev Level
      for (auto it : usedOnLevel) {
        st.erase(it);
      }
      usedOnLevel.clear();
    }
    string word = vec.back();
    if (word == endWord) {
      // The First Sequence where we reached End
      if (ans.size() == 0) {
        ans.push_back(vec);
      } else if (ans[0].size() == vec.size()) {
        // Should be Same Level Sequence
        ans.push_back(vec);
      }
    }

    for (int i = 0; i < word.size(); i++) {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == original)
          continue;
        word[i] = ch;
        if (st.count(word) > 0) {
          vec.push_back(word);
          q.push(vec);
          usedOnLevel.push_back(word);
          // Refer 27_G_30_Word_Ladder_II_Shortest_Paths_1
          vec.pop_back(); // So to check other levels too correctly
        }
      }
      word[i] = original;
    }
  }

  return ans;
}

int main() {
  cout << "27 G 30 Word Ladder II Shortest Paths" << endl;

  // Differnce in this Question is that we have to Print all the Paths

  // We will take set DS and keep all wordList elements in it so it is easy to
  // search and in less TC

  // Here in Queue we will store the list of words we have encountered so far
  // Here from set we wont erase on the step like we were doing before that is
  // as soon as we found it Here we will remove it once the whole level is
  // completed because we need to give all possible shortest paths not just one
  // shortest
  /*
        Problem:
        --------
        We have:
            beginWord = "bat"
            endWord   = "coz"

        Word List:
            {"pat", "bot", "pot", "poz", "coz"}

        We need to transform beginWord -> endWord
        by changing ONLY one character at a time.

        Also:
        - Every transformed word must exist in wordList.
        - We must return ALL SHORTEST possible sequences.
    */

  string beginWord = "bat";
  string endWord = "coz";

  vector<string> wordList = {"pat", "bot", "pot", "poz", "coz"};

  /*
      Expected Shortest Sequences:
      ----------------------------

      Path 1:
      bat -> bot -> pot -> poz -> coz

      Path 2:
      bat -> pat -> pot -> poz -> coz

      Both paths are shortest paths
      so we must return BOTH.
  */

  vector<vector<string>> ans = ladderLength(beginWord, endWord, wordList);

  cout << "\nAll Shortest Transformation Sequences:\n\n";

  /*
      Printing all shortest paths
  */

  for (auto sequence : ans) {

    for (int i = 0; i < sequence.size(); i++) {

      cout << sequence[i];

      // Avoid extra arrow after last word
      if (i != sequence.size() - 1) {
        cout << " -> ";
      }
    }

    cout << endl;
  }

  return 0;
}