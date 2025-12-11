#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int num) {
  // TC O(log n)
  // SC O(log n)

  string ans = "";
  while (num != 1) {
    if (num % 2 == 1)
      ans += "1";
    else
      ans += "0";
    num = num / 2;
  }
  ans += "1";
  reverse(ans.begin(), ans.end());
  return ans;
}
// minal approach
string convertToBinary2(int num) {
  string ans = "";
  while (num > 0) {
    ans += num % 2 ? "1" : "0";
    num = num / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int convertToDecimal(string x) {
  // Refer 1_Introduction_to_Bit_Manipulation_2

  // TC O(N)
  // SC O(1)
  int len = x.size();
  int num = 0;
  int powerOfTwo = 1;
  for (int i = len - 1; i >= 0; i--) {
    if (x[i] == '1') {
      num += powerOfTwo;
    }
    powerOfTwo *= 2; // SO we dont have to compute 2 ^ powers
  }
  return num;
}
int main() {
  cout << "1 Introduction to Bit Manipulation" << endl;

  // Integer to Number Refer to 1_Introduction_to_Bit_Manipulation_1

  // We divide the number by 2

  //    2 | 13    remainder 1
  //    ------
  //    2 | 6     remainder 0
  //    ------
  //    2 | 3     remainder 1
  //    ------
  //      | 1

  // Then take from bottom to top that is 1 1 0 1
  //  So 13 -> 1101
  int num = 13;
  string res = convertToBinary(num);
  cout << res << endl;
  string res2 = convertToBinary2(num);
  cout << res2 << endl;

  int res3 = convertToDecimal(res);
  cout << res3;

  // 1's Compliment
  // so we have a integer 13
  // we convert it to Binary we get 1101
  // and we flip all the bits 0010

  // 2's Compliment
  // Same as 1's Compliment add 1

  // so we have a integer 13
  // we convert it to Binary we get 1101
  // and we flip all the bits 0010 and now add 1
  // 0011

  // OPERATORS
  // AND OR XOR SHIFT NOT

  // AND
  // If all true then true
  // If 1 false then false

  // 13 & 7

  // 1 1 0 1
  // 0 1 1 1

  // 0 1 0 1

  // SO 13 & 7 = 5

  // A  B  A&B
  // 0  0   0
  // 0  1   0
  // 1  0   0
  // 1  1   1

  // OR
  // If 1 true then true
  // If all false then false

  // 13 | 7

  // 1 1 0 1
  // 0 1 1 1

  // 1 1 1 1

  // SO 13 | 7 = 15

  // A  B  A|B
  // 0  0   0
  // 0  1   1
  // 1  0   1
  // 1  1   1

  return 0;
}
