#include <bits/stdc++.h>
using namespace std;

int bruteCountSubarraysWithXOR(vector<int> &arr, int size, int k) {
  int cnt = 0;

  for (int i = 0; i < size; i++) {
    int xr = 0;
    for (int j = i; j < size; j++) {
      xr ^= arr[j];
      if (xr == k)
        cnt++;
    }
  }

  return cnt;
}
int optimalCountSubarraysWithXOR(vector<int> &arr, int size, int k) {

  // TC (n log n)
  // SC (n)

  // We are using prefix XOR + hashmap to count subarrays with XOR equal to `k`

  int xr = 0;
  int cnt = 0;
  map<int, int> mpp;
  mpp[xr]++; // {0,1} is inserted in the map

  for (int i = 0; i < size; i++) {
    xr = xr ^ arr[i];

    int x = xr ^ k;
    cnt += mpp[x]; // If it doesnt exist it will be 0 otherwise added in cnt;
    mpp[xr]++;
  }
  return cnt;
}

int main() {
  cout << "Array 5" << endl;
  cout << "Number of Subarray with XOR K" << endl;
  //   vector<int> arr = {4, 2, 2, 6, 4};
  //   int res = bruteCountSubarraysWithXOR(arr, arr.size(), 6);
  //   cout << res << endl;
  vector<int> arr = {4, 2, 2, 6, 4};
  int res = optimalCountSubarraysWithXOR(arr, arr.size(), 6);
  cout << res << endl;
  return 0;
}