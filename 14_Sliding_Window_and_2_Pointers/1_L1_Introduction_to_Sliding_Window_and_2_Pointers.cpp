

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "1 L1 Introduction to Sliding Window and 2 Pointers" << endl;

  // 4 Different Pattern of Problems

  // 1. Constant Window
  // Example arr = {-1,2,3,3,4,5,-1} and K = 4
  // We have to find maximum sum of K consecutive numbers
  // So here we have Constant window of K that is consecutive
  // Refer to 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_1

  // 2. Longest Subarray/Substring where <condition>
  // Most Common pattern and most asked one
  // Longest Subarray with sum <= 14 give consecutive portion of Subarray
  // Example arr = {2,5,1,7,17} and K = 14
  // Follow Brute Better Optimal Approach for these kind

  // Brute : Generate all Subarrays and then check with condition
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_2
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_3
  // TC O(N^2)
  // SC O(1)

  // Better : Generate all Subarrays and then check with condition
  // To implement the Two Pointer and Sliding Window in such cases
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_4
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_5
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_6
  // TC O(2N)
  // SC O(1)

  // Optimal
  // It comes in play when we are asked for maxLength
  // If we are asked Subarray then acc to condition Better might be the Optimal
  // Here basically when we have achived the maxRange we dont shrink below it
  // In Above Solution we were getting O(2N) because l was shrinking upto we get
  // sum in range But here we can make that window is minimum of that size that
  // is maxRange we are calculating
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_7
  // While loop turns to if
  // TC O(N)
  // SC O(1)

  // 3. Number of Subarray where <condition>
  // will be solved using pattern 2
  // Slightly Difficult ones
  // Ex Number of Subarrays with sum = k
  // 1_L1_Introduction_to_Sliding_Window_and_2_Pointers_7
  // we will get
  // X =  Number of Subarray with sum <= K
  // Y =  Number of Subarray with sum <= (K-1)

  // ANS = X - Y

  // 4. Shortest/Minimum window where <condition>
  // So in this we first get to a point where we get a valid window
  // then we shrink and check if thats a valid a window and loop until
  // shortest and valid one

  return 0;
}
