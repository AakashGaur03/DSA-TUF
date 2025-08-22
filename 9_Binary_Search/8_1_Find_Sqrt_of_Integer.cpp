#include <bits/stdc++.h>
using namespace std;
int bruteSquareRoot(int num) {
  int ans = -1;

  for (int i = 1; i <= num; i++) {
    if (i * i <= num) {
      ans = i;
    } else {
      break;
    }
  }

  return ans;
}
int optimalSquareRootBinarySearch(int num) {
  // TC O(log base 2 n)
  int ans = -1;

  int low = 0;
  int high = num;

  while (low <= high) {
    long long mid = (low + high) / 2;
    long long val = mid * mid;
    if (val == num) {
      return mid;
    } else if (val < num) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  // return ans;
  return high;
}

int main() {
  cout << "BS 8" << endl;
  // Return the Floor value of square root of an integer

  int res = bruteSquareRoot(28);
  cout << res << endl;
  int res2 = optimalSquareRootBinarySearch(28);
  cout << res2 << endl;
  return 0;
}