#include <bits/stdc++.h>
using namespace std;
int funcnCr(int n, int r) {
  // TC O(r)
  // SC O(1)

  int res = 1;
  // Ex 10C3
  // 1 * (10 -0)
  // res = 10/ 1

  // 10 * (10 -1)
  // res =  10 * 9/(1*2)

  // (10*9)/2 * (10 -2)
  // res = (10*9*8)/1*2*3

  for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
  }

  return res;
}

vector<int> optimizedSecondApproach(int n) {
  // TC O(N)
  // SC O(1)
  int ans = 1;
  vector<int> ansRow;
  ansRow.push_back(ans);
  for (int i = 1; i < n; i++) {
    ans = ans * (n - i);
    ans = ans / (i);
    ansRow.push_back(ans);
  }

  return ansRow;
}

vector<vector<int>> printFullPascalTriangle(int numRows) {
  // TC: O(N*N) * O(r) ~ O(N^3)
  vector<vector<int>> ans;

  for (int row = 1; row <= numRows; row++) {
    vector<int> tempList;
    for (int col = 1; col <= row; col++) {
      tempList.push_back(funcnCr(row - 1, col - 1));
    }
    ans.push_back(tempList);
  }

  return ans;
}

vector<vector<int>> optimalPascaltriangle(int N) {
  // TC O(N*N)
  vector<vector<int>> ans;

  for (int i = 1; i <= N; i++) {
    ans.push_back(optimizedSecondApproach(i));
  }

  return ans;
}
int main() {
  cout << "Array 1";

  int n = 6;
  int r = 3;
  int res = funcnCr(n, r);
  cout << res;

  // Pascal Triangle
  //         1
  //       1   1
  //     1   2   1
  //   1   3   3   1
  // 1   4   6   4   1

  // Three type of Questions

  // 1) Given Row Number and Col number Give element at that index
  // we do it by NcR formula that is n! / r! * (n-r)!

  // 2) Print nth row of pascal triangle

  // 3) Given N, Print entire Triangle

  // SO for first type
  int resultAtIndx = funcnCr(n - 1, r - 1);
  cout << endl
       << "Result at Pascal Triangle Index " << n << " and " << r
       << " is :" << resultAtIndx;

  // Second type of Problem
  // Print nth row
  cout << endl;
  // So what we can do is simply for brute force we need to print row
  // So in nth row we notice that there are n elements so loop till n and then
  // use above function
  // TC O(N * r)
  for (int i = 1; i <= n; i++) {
    cout << funcnCr(n - 1, i - 1) << " ";
  }

  cout << endl;
  // Print nth row of Pascal Triangle
  vector<int> secdApprRow = optimizedSecondApproach(n);
  for (auto it : secdApprRow) {
    cout << it << " ";
  }
  cout << endl;
  // Problem type 3
  // Print Full triangle
  // Brute will be
  vector<vector<int>> triangle = printFullPascalTriangle(n);

  for (auto row : triangle) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  cout << endl;
  vector<vector<int>> optimizedTriangle = optimalPascaltriangle(n);

  for (auto row : optimizedTriangle) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}