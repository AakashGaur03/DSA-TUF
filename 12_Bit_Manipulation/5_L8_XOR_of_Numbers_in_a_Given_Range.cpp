#include <bits/stdc++.h>
using namespace std;

int bruteXorNElements(int n) {
  // TC O(N)
  // SC O(1)
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans ^= i;
  }
  return ans;
}

int optimalXorNElements(int N) {
  // TC O(1)
  // SC O(1)

  // REFER 5_L8_XOR_of_Numbers_in_a_Given_Range_1
  // Refer to see the pattern

  if (N % 4 == 1) {
    return 1;
  } else if (N % 4 == 2) {
    return N + 1;
  } else if (N % 4 == 3) {
    return 0;
  } else {
    return N;
  }
}

int optimalXorElementsInRange(int l, int r) {
  // TC O(1)
  // SC O(1)
  // We will try to convert it to 1 to N
  // Refer to 5_L8_XOR_of_Numbers_in_a_Given_Range_2
  // Basically what we will do is Take from 1 to L
  // and a Xor from 1 - R
  // Then XOR them both
  return optimalXorNElements(l - 1) ^ optimalXorNElements(r);
}
int main() {
  cout << "5_L8_XOR_of_Numbers_in_a_Given_Range" << endl;
  // We will be given a nunber n
  // Questions asks us to XOR numbers from 1 to n
  //   Ex n = 4
  //   So we need to do
  //   1^2^3^4
  int n = 4;
  int res = bruteXorNElements(n);
  cout << res;
  int res2 = optimalXorNElements(n);
  cout << res2;

  // Another Type is Find XOR from L to R
  //   Means L = 4 R = 7
  // Find  4^5^6^7
  // Brute is same run a loop from R to L and Xor everything
  // TC O(R-L+1) basically number of elements
  // SC O(1)
  int l = 4;
  int r = 7;
  int res3 = optimalXorElementsInRange(l, r);
  cout << res3;

  return 0;
}
