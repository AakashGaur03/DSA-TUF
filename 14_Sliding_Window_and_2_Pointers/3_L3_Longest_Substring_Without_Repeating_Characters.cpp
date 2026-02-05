

#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharactersBrute(string s) {
  // TC O(N^2)
  // SC O(256)
  int size = s.size();
  int maxLen = 0;
  for (int i = 0; i < size; i++) {
    vector<int> hash(256, 0);
    int len = 0;
    for (int j = i; j < size; j++) {
      if (hash[s[j]] == 1) {
        break;
      }
      hash[s[j]] = 1;
      len = j - i + 1;
      maxLen = max(len, maxLen);
    }
  }
  return maxLen;
}

int longestSubstringWithoutRepeatingCharactersOptimal(string s) {
  // TC O(N)
  // SC O(256)

  // 0 1 2 3 4 5 6 7 8
  // c a d b z a b c d

  // We will take a hashmap char and index
  // if we have seen right in hashmap if not
  // then add in hashmap update maxlen move right++
  // repeat same till a char comes that in hashmap
  // now a char comes that in hashmap now leftPtr moves to
  // 1 index front where previous repeating character was (we will get this from
  // hashMap index) also update the index of repeting character in map with the
  // new one
  // ALSO NOTE WHEN WE ARE CHECKING INDEX IN HASHMAP WE NEED TO CHECK THAT
  // HASMAP INDEX >= leftptr

  // We can use HashArr as well as we know max size is 255

  vector<int> hashArr(256, -1);
  int size = s.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int len = 0;
  while (right < size) {
    if (hashArr[s[right]] >= left) {
      left = hashArr[s[right]] + 1;
    }
    hashArr[s[right]] = right;
    len = right - left + 1;
    maxLen = max(len, maxLen);
    right++;
  }
  return maxLen;
}

int main() {
  cout << "3 L3 Longest Substring Without Repeating Characters" << endl;

  string s = "cadbzabcd";
  cout << longestSubstringWithoutRepeatingCharactersBrute(s) << endl;
  cout << longestSubstringWithoutRepeatingCharactersOptimal(s) << endl;

  // we will be given a string with any 256 characters we need to give length of
  // longest substring that has no repreating characters
  return 0;
}
