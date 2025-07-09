#include <bits/stdc++.h>
using namespace std;

// Max array size in int that we can declare is 10^7 outside main that is
// globally Max array size in int that we can declare is 10^6 inside main Max
// array size in bool that we can declare is 10^8 outside main that is globally
// Max array size in bool that we can declare is 10^7 inside main

int main() {
  cout << "Hashing and Maps" << endl;
  // Hashing -> Prestoring / fetching

  // const int MAX = 1000;
  // int n;
  // cin >> n;
  // int arr[MAX];
  // for (int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  // // How namy queries i want to perform
  // int q;
  // cin >> q;

  // // Precomputing
  // int hash[13] = {0}; // Depending on max size of array we can declare hash
  // for (int i = 0; i < n; i++) {
  //   hash[arr[i]] += 1;
  // }

  // while (q--) {
  //   int number;
  //   cin >> number;

  //   // Fetching
  //   cout << number << " appears " << hash[number] << " Times" << endl;
  // }

  // // charactrer Hashing
  // string s;
  // cin >> s;

  // // pre compute

  // // If only lowercase letter
  // // a ASCII is 97 so to refer it as 0 index we do a-a,
  // // similarly we can map any letter ex f - a is on index 5
  // // int charHash[26] = {0};
  // // for (int i = 0; i < s.size(); i++) {
  // //   charHash[s[i] - 'a']++;
  // // }

  // // if uppercase too
  // int charHash[256] = {0};
  // for (int i = 0; i < s.size(); i++) {
  //   charHash[s[i]]++;
  // }

  // int q;
  // cin >> q;
  // while (q--) {
  //   char c;
  //   cin >> c;

  //   // fetch
  //   // cout << charHash[c - 'a'] << endl;

  //   // if uppercase too
  //   cout << charHash[c] << endl;
  // }

  // For Number Hashing when there are numbers that can make us use more
  // memory like if we have 1 2 3 1 12 so here we had declared array size of
  // 13 to get all numbers hash array but we only need 4 positions so here

  // Map comes in play

  const int MAX = 1000;
  int n;
  cin >> n;
  int arr[MAX];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // pre compute

  unordered_map<long, long> mpp;
  for (int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }

  // it stores all in sorted order
  // iterate in the map
  for (auto it : mpp) {
    cout << it.first << " " << it.second << endl;
  }

  //  How namy queries i want to perform
  int q;
  cin >> q;

  while (q--) {
    int number;
    cin >> number;
    cout << mpp[number] << endl;
    // Fetching
  }
  long maxFreq = 0;
  for (auto it : mpp) {
    maxFreq = max(maxFreq, it.second);
  }

  cout << "Maximum frequency is: " << maxFreq << endl;

  long maxFreq2 = 0;
  long mostFrequent = -1;
  for (auto it : mpp) {
    if (it.second > maxFreq2) {
      maxFreq2 = it.second;
      mostFrequent = it.first;
    }
  }
  cout << "Most frequent number is: " << mostFrequent
       << " with frequency: " << maxFreq2 << endl;

  // TC of map Storing and fetching takes log(n) in all cases best avg and worst

  // so what we can do is use unordered_map
  // we just do unordered_map instead of map

  // TC of unordered_map Storing and fetching takes O(1) in best and avg case
  // and O(N) in worst case that is once in a blue moon
  // so in worst case storing and fatching takes O(n) and also note that we are
  // running for loop that goes on each iteration to store so it takes O(N) too
  // so total O(N^2) overall complexity

  return 0;

  // Division Method + Linear Chain (Will Learn more in Linked List)
}