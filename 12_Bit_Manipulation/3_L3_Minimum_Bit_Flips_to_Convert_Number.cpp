#include <bits/stdc++.h>
using namespace std;

int countNumberOfSetBits(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt += n & 1; // n & 1 adds 1 if the last bit is set.
    n = n >> 1;
  }
  return cnt;
}

int minimumBitFlipsToConvertNumber(int start, int goal) {
  // TC O log(start ^ goal)
  int temp = start ^ goal;

  return countNumberOfSetBits(temp);
}

int main() {
  cout << "3 L3 Minimum Bit Flips to Convert Number" << endl;

  // we will be given a start and goal both will be positive integers including
  // zero

  // Example
  //     start = 10         goal = 7
  //      1 0 1 0           0 1 1 1
  // So   - -   -  3 bits need to be changed

  // Basic apporach is that we will perform a XOR oerations
  // it will give us 1 where bit needs to be changed as when both are
  // 0 or both are 1 it gives us 0

  //   So after start^goal
  // we have to count number of bits of the XOR result and that
  // will be our final answer
  int start = 10;
  int goal = 7;
  int res = minimumBitFlipsToConvertNumber(start, goal);
  cout << res;
  return 0;
}
