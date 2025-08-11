#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForceMissingAndRepeating(vector<int> arr, int size) {
  // TC O(N^2)

  // Loop from 1 to 6 find the number appearing twice that is repeating find
  // number appearing 0 times that is missing
  vector<int> res;
  int repeating = -1;
  int missing = -1;

  // First loop from 1 to <= size because traversing from 1 to n
  for (int i = 1; i <= size; i++) {
    int cnt = 0;
    // Second loop from 0 to < size because traversing in array
    for (int j = 0; j < size; j++) {
      if (i == arr[j]) {
        cnt++;
      }
    }
    if (cnt == 2) {
      repeating = i;
    } else if (cnt == 0) {
      missing = i;
    }
    if (repeating != -1 && missing != -1) {
      break;
    }
  }
  res.push_back(repeating);
  res.push_back(missing);

  cout << "repeating : " << repeating << endl;
  cout << "missing : " << missing << endl;
  return res;
}

vector<int> bettereMissingAndRepeating(vector<int> arr, int size) {
  // HASHING
  // TC:  O(N) for Hashing + O(N) for comparasion
  // SC : O(N)

  vector<int> hashArr(size + 1, 0);
  int repeating = -1;
  int missing = -1;

  for (int i = 0; i < size; i++) {
    hashArr[arr[i]]++;
  }

  for (int i = 1; i <= size; i++) {
    if (hashArr[i] == 0) {
      missing = i;
    } else if (hashArr[i] == 2) {
      repeating = i;
    }
    if (repeating != -1 && missing != -1) {
      break;
    }
  }
  cout << "repeating : " << repeating << endl;
  cout << "missing : " << missing << endl;

  return {repeating, missing};
}

vector<int> optimal1MissingAndRepeating(vector<int> arr, int n) {
  // TC: O(N) → One pass to compute sum and sum of squares
  // SC: O(1) → Only variables, no extra data structures

  // Formula for sum of first N natural numbers: SN = n*(n+1)/2
  long long SN = (n * (n + 1)) / 2;

  // Formula for sum of squares of first N natural numbers: S2N =
  // n*(n+1)*(2n+1)/6
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

  // Variables to store sum and sum of squares of given array
  long long S = 0, S2 = 0;

  // Calculate actual sum (S) and sum of squares (S2) of the array elements
  for (int i = 0; i < n; i++) {
    S += arr[i];
    S2 += (long long)arr[i] * (long long)arr[i];
  }

  // Difference between actual sum and expected sum: val1 = x - y
  // x = repeating number, y = missing number
  long long val1 = S - SN;

  // Difference between actual sum of squares and expected sum of squares: val2
  // = x² - y²
  long long val2 = S2 - S2N;

  // Since x² - y² = (x - y)(x + y), we can find (x + y):
  val2 = val2 / val1; // Now val2 = x + y

  // Solve two equations:
  // 1) x - y = val1
  // 2) x + y = val2
  long long x = (val1 + val2) / 2; // Repeating number
  long long y = x - val1;          // Missing number

  // Return as {repeating, missing}
  return {(int)x, (int)y};
}

vector<int> optimal2XORMissingAndRepeating(vector<int> arr, int n) {
  // TC O(3N)
  // Step 1: XOR of all elements in array and numbers from 1 to n
  // This will give us XOR of (missing ^ repeating)
  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= arr[i];  // XOR all array elements
    xr ^= (i + 1); // XOR with 1, 2, ..., n
  }

  // Step 2: Find the rightmost set bit in xr
  // This bit will help us separate the two numbers into two groups
  int rightmostSetBit = xr & ~(xr - 1);

  int bucket1 = 0; // Will store XOR of one group
  int bucket2 = 0; // Will store XOR of the other group

  // Step 3: Divide numbers into two buckets based on the rightmost set bit
  for (int i = 0; i < n; i++) {
    // Check the array elements
    if (arr[i] & rightmostSetBit)
      bucket1 ^= arr[i];
    else
      bucket2 ^= arr[i];

    // Check the numbers from 1 to n
    if ((i + 1) & rightmostSetBit)
      bucket1 ^= (i + 1);
    else
      bucket2 ^= (i + 1);
  }

  // Step 4: Identify which bucket has the repeating number
  // Count occurrences of bucket1 in the array
  int countBucket1 = count(arr.begin(), arr.end(), bucket1);

  if (countBucket1 == 2)
    return {bucket1, bucket2}; // {repeating, missing}
  else
    return {bucket2, bucket1}; // {repeating, missing}
}
int main() {
  cout << "8 Find Missing and Repeated Number" << endl;
  vector<int> arr = {4, 3, 6, 2, 1, 1};
  // We will be given List of integers from 1 to N we have to find out the
  // missing number and repeated number

  // vector<int> res = bruteForceMissingAndRepeating(arr, arr.size());
  vector<int> res = bettereMissingAndRepeating(arr, arr.size());
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}