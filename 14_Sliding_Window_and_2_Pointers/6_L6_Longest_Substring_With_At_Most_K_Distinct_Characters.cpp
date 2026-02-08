

#include <bits/stdc++.h>
using namespace std;

string bruteApproach(string s, int k) {
  // TC O(N^2)
  // SC O(k)
  // We generate all subStrings
  // we see at most k unique elements with maxLen
  if (k == 0) {
    return "";
  }
  int size = s.size();
  int maxLen = 0;
  string res;
  for (int i = 0; i < size; i++) { // O(N)
    set<char> st;
    for (int j = i; j < size; j++) { // O(N)
      st.insert(s[j]);               // O(log N) = log(3) = 1
      if (st.size() > k) {
        break;
      }
      if (maxLen < j - i + 1) {
        maxLen = j - i + 1;
        res = s.substr(i, j - i + 1);
      }
    }
  }
  return res;
}

string optimalApproach(string s, int k) {
  // TC O(2N)
  // SC O(K)
  int size = s.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  unordered_map<char, int> mpp;
  string ans;

  while (right < size) { // O(N)
    mpp[s[right]]++;

    if (mpp.size() > k) {
      while (mpp.size() > k) { // O(N)
        mpp[s[left]]--;
        if (mpp[s[left]] == 0) {
          mpp.erase(s[left]);
        }
        left++;
      }
    }

    if (mpp.size() <= k && maxLen < right - left + 1) {
      maxLen = max(maxLen, right - left + 1);
      ans = s.substr(left, right - left + 1);
    }
    right++;
  }
  return ans;
}

int main() {
  cout << "6 L6 Longest Substring With At Most K Distinct Characters" << endl;
  string s = "aaabbccd";
  int k = 2;
  // It is a similar Kind of question that we have done in rev that is
  // 5_L5_Fruit_Into_Baskets
  // Here we have to return the Substring
  // If we have to return Number of Longest Substring
  // so prev solution is exaclty same
  // In this also we do minimum changes to just store the string as answer

  string res = bruteApproach(s, k);
  cout << res << endl;
  string res2 = optimalApproach(s, k);
  cout << res2 << endl;
  return 0;
}
