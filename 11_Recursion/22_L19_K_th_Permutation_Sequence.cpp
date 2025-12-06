#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k) {
  // TC O(N * N)
  // SC O(N)
  int fact = 1;
  vector<int> numbers;

  for (int i = 1; i < n; i++) {
    fact = fact * i;
    numbers.push_back(i);
  }
  numbers.push_back(n);
  string ans = "";
  k = k - 1;
  while (true) {
    ans = ans + to_string(numbers[k / fact]);
    numbers.erase(numbers.begin() + k / fact);
    if (numbers.size() == 0) {
      break;
    }
    k = k % fact;
    fact = fact / numbers.size();
  }
  return ans;
}

int main() {
  cout << "22 L19 K-th Permutation Sequence" << endl;
  // we will be given N and K
  //   so n is the number that is 3
  // so 3 number permutation 123 132 213 231 312 321
  // k =4 so we have to tell the 4th permutaiton in Lexicographical order that
  // will be 231

  // Brute force
  // will be using recursion we will genereate all the permutaitons will do deep
  // copy of them and store in a data structure then after sorting it will
  // return ds[k-1];

  // TC O(n! * n)
  //  n! for generating permutations n for storing them
  // SC O(n! * n!log(n!))
  // n! for stoing and n!log(n!) for sorting

  int n = 4;
  int k = 17;

  string ans = getPermutation(n, k);
  cout << ans;
  return 0;
}

// COMMENTED VERSION
// string getPermutation(int n, int k) {
//   // TC: O(N * N) because of vector erase operations
//   // SC: O(N)

//   int fact = 1;        // factorial of (n-1) will be stored here
//   vector<int> numbers; // list of available digits (1 to n)

//   // Step 1: Build the numbers list and compute (n-1)!
//   for (int i = 1; i < n; i++) {
//     fact = fact * i;      // factorial grows: 1 → 1 → 2 → 6 → ...
//     numbers.push_back(i); // store digits: 1,2,...,n-1
//   }
//   numbers.push_back(n); // now numbers = {1,2,3,...,n}

//   string ans = "";
//   k = k - 1; // convert k to 0-indexed so calculations work

//   // Step 2: Build the permutation
//   while (true) {

//     // Choose index of next number:
//     // (k / fact) gives the group where the k-th permutation falls.
//     ans += to_string(numbers[k / fact]);

//     // Remove the used number from the list
//     numbers.erase(numbers.begin() + k / fact);

//     // If no numbers left, we are done
//     if (numbers.size() == 0) {
//       break;
//     }

//     // Step 3: Reduce k for the next smaller block
//     k = k % fact; // remaining index inside the block

//     // Step 4: Update factorial for remaining digits
//     fact = fact / numbers.size();
//   }

//   return ans;
// }
