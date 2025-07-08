#include <bits/stdc++.h>
using namespace std;

// Max array size in int that we can declare is 10^7 outside main that is
// globally Max array size in int that we can declare is 10^6 inside main Max
// array size in bool that we can declare is 10^8 outside main that is globally
// Max array size in bool that we can declare is 10^7 inside main

int main() {
  cout << "Hashing and Maps" << endl;
  // Hashing -> Prestoring / fetching

  const int MAX = 1000;
  int n;
  cin >> n;
  int arr[MAX];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // How namy queries i want to perform
  int q;
  cin >> q;

  // Precomputing
  int hash[13] = {0}; // Depending on max size of array we can declare hash
  for (int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
  }

  while (q--) {
    int number;
    cin >> number;

    // Fetching
    cout << number << " appears " << hash[number] << " Times" << endl;
  }

  return 0;
}