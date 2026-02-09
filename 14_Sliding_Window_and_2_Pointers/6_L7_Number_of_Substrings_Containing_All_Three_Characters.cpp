

#include <bits/stdc++.h>
using namespace std;

int bruteApproach(string s, int k) {
  // TC O(N^2 log K)
  // SC O(K)
  if (k == 0) {
    return 0;
  }
  int size = s.size();
  int ans = 0;

  for (int i = 0; i < size; i++) {
    set<char> st;
    for (int j = i; j < size; j++) {
      st.insert(s[j]);
      if (st.size() == k) {
        ans++;
      }
    }
  }

  return ans;
}

int bruteApproach2(string s, int k) {
  // TC O(N^2)
  // SC O(1)  // fixed size array of 3
  if (k == 0) {
    return 0;
  }
  int size = s.size();
  int ans = 0;

  for (int i = 0; i < size; i++) {
    vector<int> hash(3, 0);
    for (int j = i; j < size; j++) {
      hash[s[j] - 'a'] = 1;
      if (hash[0] + hash[1] + hash[2] == 3) {
        // ans++; // by simply adding one by one
        // Slight Improvement when we get it is valid add other substring at
        // once
        ans = ans + (size - j);
        break;
      }
    }
  }

  return ans;
}

int optimalApproach(string s, int k) {
  // TC O(N)
  // SC O(1)
  // With every character there is a substring that ends
  // we will be figuring out minimum window where it is valic
  // after that adding the front ones
  // will be traversing in backward Direction
  int size = s.size();
  int cnt = 0;
  vector<int> lastSeen(3, -1);
  for (int i = 0; i < size; i++) {
    lastSeen[s[i] - 'a'] = i;
    if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
      cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
    }
  }
  return cnt;
}

int main() {
  cout << "6 L7 Number of Substrings Containing All Three Characters" << endl;
  string s = "bbacba";
  int k = 3;

  int res = bruteApproach(s, k);
  cout << res << endl;
  int res2 = bruteApproach2(s, k);
  cout << res2 << endl;
  int res3 = optimalApproach(s, k);
  cout << res3 << endl;
  return 0;
}
