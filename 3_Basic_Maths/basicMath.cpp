#include <bits/stdc++.h>
using namespace std;

int countDigits(int num) {
  // Time Complexity is log base 10 (N)

  // When division is happening by 10 then log base 10 (N)
  // When division is happening by 2 then log base 2 (N)
  // When division is happening by 5 then log base 5 (N)
  // ...
  // int cnt = 0;
  // while (num > 0) {
  //   num = num / 10;
  //   cnt++;
  // }
  // return cnt;

  int cnt = (int)(log10(num) + 1);
  return cnt;
}

int reverseNumber(int num) {
  int lastDigit;
  int revNum = 0;
  while (num > 0) {
    lastDigit = num % 10;
    num = num / 10;
    revNum = (revNum * 10) + lastDigit;
  }
  return revNum;
}

bool checkPalindrome(int num) {
  int lastDigit;
  int numCopy = num;
  int revNum = 0;
  while (num > 0) {
    lastDigit = num % 10;
    num = num / 10;
    revNum = (revNum * 10) + lastDigit;
  }
  return revNum == numCopy;
}

bool armStrongNumber(int num) {
  // Let N = 371 if 3^3 + 7^3 + 1^3 == 371 then armstrong otherwise not
  // Number of digits is what will be the power
  // 371       power of 3 to each
  // 1634      power of 4 to each
  int duplicateNum = num;
  int numDigits = 0;

  int temp = num;
  while (temp > 0) {
    numDigits++;
    temp /= 10;
  }

  int finalNum = 0;
  temp = num;
  while (temp > 0) {
    int digit = temp % 10;
    finalNum += pow(digit, numDigits);
    temp /= 10;
  }
  cout << "finalNum : " << finalNum << endl;
  cout << "duplicateNum : " << duplicateNum << endl;
  return finalNum == duplicateNum;
}

void printAllDivisors(int num) {
  cout << "Printing Divisors :" << endl;
  // TC is O(n)
  for (int i = 1; i <= num; i++) {
    if (num % i == 0) {
      cout << i << " ";
    }
  }
  cout << endl;
  cout << "Other Way" << endl;
  // TC is O(sqrt(n)) + O(n log n)
  vector<int> v;

  // O(sqrt(n))
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      if (i == num / i) {
        // cout << i << " ";
        v.push_back(i);
      } else {
        // cout << i << " " << num / i << " ";
        v.push_back(i);
        v.push_back(num / i);
      }
    }
  }
  // O(n log n)
  sort(v.begin(), v.end());

  // O(n)
  for (auto it : v) {
    cout << it << " ";
  }
}

int main() {
  cout << "Hi Basic Maths" << endl;

  // // Digit Concept
  // int n = 7789;
  // // extraction of digits

  // while (n > 0) {
  //   int lastDigit = n % 10;
  //   cout << lastDigit;
  //   n = n / 10;
  // }

  // Count Digits
  cout << endl;
  int num;
  cout << "Enter Number to get Digits :";
  cin >> num;
  cout << endl;

  // cout << countDigits(num);
  // cout << "Reverse Number is : " << reverseNumber(num);
  // cout << endl;
  // cout << checkPalindrome(num);
  // cout << "Palindrom or Not : " << checkPalindrome(num);
  // cout << armStrongNumber(num);
  // cout << "Armstrong or Not : " << armStrongNumber(num);

  cout << endl;
  printAllDivisors(num);
  return 0;
}