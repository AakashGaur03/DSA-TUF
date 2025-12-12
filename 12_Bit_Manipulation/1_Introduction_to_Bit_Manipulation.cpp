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

  // XOR

  // Number of 1's are odd then 1
  // Number of 1's are even then 0
  // 13^7

  // 1 1 0 1
  // 0 1 1 1

  //  1 0 1 0

  // SO 13 ^ 7 = 10

  // SHIFT OPERATOR

  // RIGHT SHIFT OPERATOR

  // 13 >> 1
  // means 13 right shift of 1

  // 1 1 0 1
  //       - goes off the cliff

  // 110 ANS  = 6

  // 13 >> 2
  // means 13 right shift of 2

  // 1 1 0 1
  //     - - goes off the cliff

  // 1 1 ANS 3

  // 13 >> 4
  // 1 1 0 1
  // - - - - goes off the cliff
  // ANS 0

  // x >> k = x / pow(2, k);

  // 13 >> 1 = 13/2 = 6
  // 13 >> 2 = 13/2^2 = 13/4 = 3
  // 13 >> 4 = 13/2^4 = 13/16 = 0
  // ALSO REFER TO 1_Introduction_to_Bit_Manipulation_3

  // HOW System stores negative number

  // so simple we have 13 we have 32 bitset

  // 31st bit                        0th bit
  //  0        0  0  0 ..... 1 1 0     1

  // 31st bit if 0 then means positive

  // now if we have -13

  // how system stores it in is 2s compliment

  // 000 .......0 1101
  // first flip all bits
  // 111 .......1 0010
  // ADD 1
  // 111 .......1 0011 this is negative storage of 13

  // LARGEST positive Number

  // 0 111111....1111
  // (2^31 -1) = INT_MAX

  // SMALLEST NUMBER

  // 1 00000....0000

  // Now flip all bits

  // 0 11111....1111

  // ADD 1

  // 1 0000....000
  // -2^31 = INT_MIN

  // LEFT SHIFT OPERATOR

  // means left shift

  // 13 << 1
  // Left shit 13 by 1
  // 0    000000 .. 1101
  //  - goes out
  // 0000000... 11010
  // 13 << 1 = 26

  // SO num << k = num * 2^k

  // 13 * 2^1 = 13 * 2 = 26

  // (2^31 -1) << 1

  // - it is of sign
  // 0 1    11111...1111
  //   - tries to go left

  // SO OVERFLOW

  // NOT OPERATOR (~)

  // ~ 5
  // 1st Step Flip
  // 2nd Step check if Negative number then store 2's Compliment
  // If Positive then stop

  // ~ 5
  // 0 000000...  1 0 1
  // Step 1 Flip
  // 1 111111.. 0 1 0

  // Check Negative YES
  // STORE 2s compliment
  // So now for 2s compliment flip and add 1

  // 1 111111.. 1010
  // 0 000000...0101

  // NOW ADD 1

  // 0 00000... 0110

  // SO ~5 = -6

  // -----------------------------------------------------------
  /*
  Now let’s walk through your example:
  Step 1: Start with 5
  0000 ... 0101

  Step 2: Apply ~ (flip all bits)
  1111 ... 1010

  ❗ This bit pattern has MSB = 1 → This means the RESULT IS NEGATIVE

  We already know the output is negative, we do NOT deduce sign later.

  So the value is:

  Negative number whose magnitude we still need to compute

  Why do we compute the 2’s complement?

  We do this ONLY to figure out “how big it is”:

  Take the flipped bits:

  1111 ... 1010

  Flip again:
  0000 ... 0101

  Add 1:
  0000 ... 0110  =  6


  This tells us:
  👉 “The magnitude of the negative result is 6.”

  So the final value is:

  -6
  */

  // -----------------------------------------------------------

  // Now Lets calculate for ~(-6)

  // -6 will be stored as 2s compliment of 6 so
  // 0000 ... 110
  // flip
  // 1111 ... 001
  // Plus 1
  // 111111....010 this is -6

  // NOW lets do ~ operations First step flip
  // 00000000... 101
  // Check Negative
  // False
  // Stores same
  return 0;
}
