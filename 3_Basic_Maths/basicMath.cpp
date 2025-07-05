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

bool primeNumber(int num) {
  // prime Number is
  // That has exactly two factors 1 and Itself

  // TC O(n)
  // int cnt = 0;
  // for (int i = 0; i <= num; i++) {
  //   if (num % i == 0) {
  //     cnt++;
  //   }
  // }
  // if (cnt == 2) {
  //   return true;
  // } else
  //   return false;

  // TC O(sqrt n)
  int cnt = 0;
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      if (i == num / i) {
        cnt++;
      } else {
        cnt += 2;
      }
    }
  }
  return cnt == 2;
}

int GCD_HCF(int num1, int num2) {
  // Greatest Comman Divisor or Highest Common Factor
  // Ex N1 = 9 , N2 = 12
  // Factors of 9 : 1,3,9
  // Factors of 12 : 1,2,3,4,6,12
  // GCD or HCF is 3
  // int smallNum = -1;
  // if (num1 < num2) {
  //   smallNum = num1;
  // } else {
  //   smallNum = num2;
  // }
  // int smallNum = min(num1, num2);
  // Brute Force
  // TC O(minimum of num1 and num2) O(min(n1,n2))
  int smallNum = num1 < num2 ? num1 : num2;
  int result = -1;
  // for (int i = 1; i <= smallNum; i++) {
  //   if (num1 % i == 0 && num2 % i == 0) {
  //     result = i;
  //   }
  // }
  // In Most cases we can do
  for (int i = smallNum; i >= 1; i--) {
    if (num1 % i == 0 && num2 % i == 0) {
      result = i;
      break;
    }
  }
  return result;
}

int optimizedGCD_HCF(int num1, int num2) {
  // Euclidean Algorithm
  // gcd of n1, n2
  // gcd(n1,n2) = gcd(n1-n2,n2) where n1>n2
  // gcd(a,b) = gcd(a-b,b) where a>b
  // Lets take an example
  // n1=20 n2 =15
  // gcd(20, 15) = gcd(20-15,15)=gcd(5,15)
  // gcd(5,15) =now we will find gcd(15,5)
  // gcd(15,5) = gc(15-5,5) => gcd(10,5)
  // gcd(10,5) = gc(10-5,5) => gcd(5,5)
  // gcd(5,5) = gc(5-5,5) => gcd(0,5)
  // When one number becomes zero then second number is gcd

  // in easy way we can also say to save more dividing steps
  // gcd(a,b) = gcd(a%b,b);  where a>b;
  // Till one number becomes zero

  // TC O(log φ(min(n1,n2)) )
  // φ can be any number
  int result;
  while (num1 > 0 && num2 > 0) {
    if (num1 > num2)
      num1 = num1 % num2;
    else
      num2 = num2 % num1;
  }
  if (num1 == 0)
    return num2;
  return num1;
}

int LCM(int num1, int num2) {
  int maxNum = (num1 > num2) ? num1 : num2;

  for (int i = maxNum;; i++) {
    if (i % num1 == 0 && i % num2 == 0) {
      return i;
    }
  }
}

int GCD(int num1, int num2) {
  while (num1 > 0 && num2 > 0) {
    if (num1 > num2)
      num1 = num1 % num2;
    else
      num2 = num2 % num1;
  }
  return (num1 == 0) ? num2 : num1;
}

int LCM_With_GCD(int num1, int num2) {
  // Optimized
  return (num1 * num2) / GCD(num1, num2);
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

  // cout << endl;
  // printAllDivisors(num);
  cout << endl;
  cout << "Is Prime Number :" << primeNumber(num);
  return 0;
}