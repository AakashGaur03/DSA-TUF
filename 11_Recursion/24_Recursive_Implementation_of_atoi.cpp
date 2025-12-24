// // Recursive Implementation of ATOI

// class Solution {
// public:
//     int recutsiveHelper(string& s, int i, long long num, int sign) {
//         int size = s.size();
//         if (i >= size || !isdigit(s[i])) {
//             return (int)(sign * num);
//         }
//         int digit = s[i] - '0';
//         num = num * 10 + digit;

//         if (sign * num <= INT_MIN)
//             return INT_MIN;
//         if (sign * num >= INT_MAX)
//             return INT_MAX;

//         return recutsiveHelper(s, i + 1, num, sign);
//     }
//     int myAtoi(string s) {
//         // Skip Leading Whitespaces
//         int i = 0;
//         int size = s.size();
//         while (i < size && s[i] == ' ') {
//             i++;
//         }
//         // Hadnle Sign
//         int sign = 1;
//         if (i < size && (s[i] == '-' || s[i] == '+')) {
//             if (s[i] == '-')
//                 sign = -1;
//             i++;
//         }

//         // Recursive Apporach for Checking Digits
//         // Handling oveflow cases
//         return recutsiveHelper(s, i, 0, sign);
//     }
// };

// // int myAtoi(string s) {
// //     int n = s.size();
// //     int i = 0;
// //     long long res = 0;
// //     int sign = 1;
// //     // Step 1: Skip leading spaces
// //     while (i < n && s[i] == ' ') {
// //         i++;
// //     }
// //     // Step 2: Handle optional sign
// //     if (i < n && (s[i] == '-' || s[i] == '+')) {
// //         if (s[i] == '-')
// //             sign = -1;
// //         i++;
// //     }
// //     // Step 3: Convert digits to number
// //     while (i < n && isdigit(s[i])) {
// //         int digit = s[i] - '0';
// //         // we want res * 10 + digit <= INT_MAX

// //         if (res > ((INT_MAX - digit) / 10)) {
// //             return (sign == 1) ? INT_MAX : INT_MIN;
// //         }
// //         res = res * 10 + digit;
// //         i++;
// //     }

// //     return int(res * sign);
// // }

#include <bits/stdc++.h>
using namespace std;

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

// Recursive helper
int helper(const string &s, int i, long long num, int sign) {
  // If we are out of bounds or at a non-digit, return
  if (i >= s.size() || !isdigit(s[i]))
    return (int)(sign * num);

  // Update num with current digit
  num = num * 10 + (s[i] - '0');

  // Clamp if overflow
  if (sign * num <= INT_MIN_VAL)
    return INT_MIN_VAL;
  if (sign * num >= INT_MAX_VAL)
    return INT_MAX_VAL;

  // Recurse for next character
  return helper(s, i + 1, num, sign);
}

int myAtoi(string s, int i = 0) {
  // Skip leading whitespaces
  while (i < s.size() && s[i] == ' ')
    i++;

  // Handle sign
  int sign = 1;
  if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  // Call recursive helper
  return helper(s, i, 0, sign);
}

int main() {
  cout << "24 Recursive Implementation of atoi";
  string s = "  -12345";
  cout << myAtoi(s) << endl; // Output: -12345
  return 0;
}