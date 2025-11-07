#include <bits/stdc++.h>
using namespace std;
void printSubsequence(int index, vector<int> &ds, int arr[], int n) {
  // TC O(2^n * n)
  // 2^n for recursion calls
  // n for printing
  // SC O(n) auxiliary stack space
  if (index == n) {
    for (auto it : ds) {
      cout << it << " ";
    }
    if (ds.size() == 0) {
      cout << "{}";
    }
    cout << endl;
    return;
  }
  // Take the particular index into subsequence
  ds.push_back(arr[index]);
  printSubsequence(index + 1, ds, arr, n);
  // Not Take the particular index into subsequence
  ds.pop_back();
  printSubsequence(index + 1, ds, arr, n);
}

int main() {
  cout << "6 L6 Recursion on Subsequences" << endl;
  // Subsequence means
  // a contigious/non contigious sequence which follows the order

  // Ex arr=[3,1,2]
  // {} Subsequence
  // 3 contigious Subsequence
  // 1 contigious Subsequence
  // 2 contigious Subsequence
  // 3 1 contigious Subsequence
  // 1 2 contigious Subsequence
  // 3 2 non - contigious Subsequence
  // 3 1 2 contigious Subsequence

  // We will use the approach of taking and not taking
  //
  //                              {}
  //                              |
  //                              3
  //                   -----------------------
  //                   |                     |
  //                take                   not take
  //                [3]                      []
  //                 |                        |
  //                 1                        1
  //         ------------------       ------------------
  //         |                |       |                |
  //       take          not take   take          not take
  //      [3,1]             [3]      [1]              []
  //         |                |       |                |
  //         2                2       2                2
  //     --------       --------   --------       --------
  //     |      |       |      |   |      |       |      |
  //   take  not take take  not   take  not     take  not
  //  [3,1,2]  [3,1]  [3,2]  [3]  [1,2]  [1]     [2]    []

  // Algo

  // f(index,[])
  // {
  //   if(index>=n){
  //     print([])
  //     return;
  //   }
  //   [].add(arr[i]);
  //   f(index+1,[]); // TAKE
  //   [].remove(arr[i]);
  //   f(index+1,[]); // NOT TAKE

  // }
  int arr[] = {3, 1, 2};
  int n = 3;
  vector<int> ds;
  printSubsequence(0, ds, arr, n);
  return 0;
}