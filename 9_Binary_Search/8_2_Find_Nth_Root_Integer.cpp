#include <bits/stdc++.h>
using namespace std;
int bruteNthRoot(int n, int num) {
  // TC O(num × n)
  for (int i = 1; i < num; i++) {
    long long val = 1;
    for (int j = 1; j <= n; j++) {
      val *= i;
      if (val == num)
        return i;
      if (val > num)
        break;
    }
  }

  return -1;
}
int optimalNthRoot(int n, int num) {
  // TC O(n * log(num))
  int low = 1;
  int high = num;

  while (low <= high) {
    int mid = (low + high) / 2;
    long long val = 1;

    for (int i = 1; i <= n; i++) {
      val *= mid;
      if (val > num)
        break;
    }

    if (val == num)
      return mid;
    if (val > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

int main() {
  cout << "BS 8_2" << endl;
  // Find Nth Root of an integer
  // N = 3 num = 27 ans = 3
  // N = 4 num = 69 ans = -1
  int n = 3;
  int num = 27;
  int res = bruteNthRoot(n, num);
  cout << res << endl;
  int res2 = optimalNthRoot(n, num);
  cout << res2 << endl;
  return 0;
}