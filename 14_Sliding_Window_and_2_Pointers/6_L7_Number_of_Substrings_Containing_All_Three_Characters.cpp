

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
        ans++;
      }
    }
  }

  return ans;
}

int main() {
  cout << "6 L7 Number of Substrings Containing All Three Characters" << endl;
  string s = "bbacba";
  int k = 3;

  int res = bruteApproach(s, k);
  cout << res << endl;
  int res2 = bruteApproach2(s, k);
  cout << res2 << endl;
  return 0;
}
