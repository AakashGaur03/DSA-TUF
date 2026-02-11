

#include <bits/stdc++.h>
using namespace std;

string bruteApporach(string s, string t) {
  // TC O(N^2)
  // SC O(256)
  int sizeS = s.size();
  int sizeT = t.size();
  int minLen = INT_MAX;
  int startIndex = -1;

  for (int i = 0; i < sizeS; i++) {
    vector<int> hash(256, 0);
    int cnt = 0;
    for (int j = 0; j < sizeT; j++) {
      hash[t[j]]++;
    }

    for (int j = i; j < sizeS; j++) {
      if (hash[s[j]] > 0) {
        // It was pre inserted
        cnt++;
      }
      hash[s[j]]--;

      if (cnt == sizeT) {
        if (j - i + 1 < minLen) {
          minLen = j - i + 1;
          startIndex = i;
        }
        break;
      }
    }
  }
  if (startIndex == -1) {
    return "";
  }
  return s.substr(startIndex, minLen);
}

string optimalApproach(string s, string t) {}

int main() {
  cout << "9 L12 Minimum Window Substring" << endl;
  string s = "ddaaabbca";
  string t = "abc";

  // We have to give smallest window that has the t substring
  // order doesnt matter
  // So here bca can be the answer
  // Also note that all characters and there frequency should be there
  // if t = abbc then bca cant be the answer it should also match the number
  // of character too

  string res = bruteApporach(s, t);
  cout << res << endl;

  string res2 = optimalApproach(s, t);
  cout << res2 << endl;
  return 0;
}
