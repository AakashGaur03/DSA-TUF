

#include <bits/stdc++.h>
using namespace std;

int bruteApproach(string s, int k) {
  // TC O(N^2)
  // SC O(26)  // fixed size array of 26

  // Brute force approach to find the longest substring
  // where at most k characters can be replaced
  // so that all characters in the substring become the same

  int size = s.size();
  int maxLen = 0;

  for (int i = 0; i < size; i++) {
    vector<int> hash(26, 0);

    // Stores the frequency of the most common character
    int maxFrequency = 0;
    for (int j = i; j < size; j++) {
      hash[s[j] - 'A']++;

      // Update the maximum frequency seen so far in this substring
      maxFrequency = max(maxFrequency, hash[s[j] - 'A']);

      // Number of characters that need to be replaced
      // = total length of substring - frequency of most common character
      int changes = (j - i + 1) - maxFrequency;
      if (changes <= k) {
        maxLen = max(maxLen, j - i + 1);
      } else {
        // If replacements exceed k, no need to expand further
        // because increasing j will only increase changes
        break;
      }
    }
  }

  return maxLen;
}
int optimalApproach(string s, int k) {
  // TC O(2N *26)
  // SC O(26)
  int size = s.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int maxFreq = 0;
  vector<int> hash(26, 0);

  while (right < size) {
    hash[s[right] - 'A']++;
    maxFreq = max(maxFreq, hash[s[right] - 'A']);
    while ((right - left + 1) - maxFreq > k) {
      // Not valid
      hash[s[left] - 'A']--;
      maxFreq = 0;
      // Update Max Freq acc by check all in hash
      for (int i = 0; i < 26; i++) {
        maxFreq = max(maxFreq, hash[i]);
      }
      left++;
    }
    if ((right - left + 1) - maxFreq <= k) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
  }
  return maxLen;
}
int optimalApproach2(string s, int k) {
  // TC O(N)
  // SC O(26)
  int size = s.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int maxFreq = 0;
  vector<int> hash(26, 0);

  while (right < size) {
    hash[s[right] - 'A']++;
    maxFreq = max(maxFreq, hash[s[right] - 'A']);
    if ((right - left + 1) - maxFreq > k) {
      // Not valid
      hash[s[left] - 'A']--;
      left++;
    }
    if ((right - left + 1) - maxFreq <= k) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
  }
  return maxLen;
}

int main() {
  cout << "7_L8_Longest_Repeating_Character_Replacement" << endl;
  string s = "AABABBA";
  int k = 2;

  // AT most K characters update them to any possible Uppercase Letter
  // then fig out the longest substring whick has all the characters as equal

  int res1 = bruteApproach(s, k);
  cout << res1 << endl;
  int res2 = optimalApproach(s, k);
  cout << res2 << endl;
  int res3 = optimalApproach2(s, k);
  cout << res3 << endl;
  return 0;
}
