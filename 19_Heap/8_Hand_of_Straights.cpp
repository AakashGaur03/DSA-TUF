#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize) {
  // TC O(N log N * groupSize)
  // TC O(N)
  int n = hand.size();

  if (n % groupSize != 0) {
    return false;
  }

  map<int, int> mpp;
  for (int handNubmer : hand) {
    mpp[handNubmer]++;
  }

  while (!mpp.empty()) {
    int curr = mpp.begin()->first; // Second will be frequency
    for (int i = 0; i < groupSize; i++) {
      if (mpp[curr + i] == 0) {
        // Means consecutive Card/Number is not present
        return false;
      }
      mpp[curr + i]--; // Reduce the Frequency
      if (mpp[curr + i] == 0) {
        mpp.erase(curr + i);
      }
    }
  }
  return true;
}

int main() {
  cout << "8 Hand of Straights" << endl;

  // Alice has some number of cards and she wants to rearrange the cards into
  // groups so that each group is of size groupSize, and consists of groupSize
  // consecutive cards.

  // Given an integer array hand where hand[i] is the value written on the ith
  // card and an integer groupSize, return true if she can rearrange the cards,
  // or false otherwise.

  // Example 1:

  // Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
  // Output: true
  // Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3;

  bool ans = isNStraightHand(hand, groupSize);

  cout << "Hand: ";
  for (int card : hand) {
    cout << card << " ";
  }
  cout << "\nGroup Size: " << groupSize << endl;

  cout << "Output: " << (ans ? "true" : "false") << endl;

  return 0;
}
