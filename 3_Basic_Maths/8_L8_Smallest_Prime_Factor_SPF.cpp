
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int num) {
  vector<int> arr;

  for (int i = 2; i * i <= num; i++) {
    while (num % i == 0) {
      arr.push_back(i);
      num /= i;
    }
  }

  if (num > 1) {
    arr.push_back(num);
  }

  return arr;
}

vector<vector<int>> PrimeFactorisationQueriesBrute(vector<int> &queries) {
  vector<vector<int>> ans;

  for (int num : queries) {
    ans.push_back(getPrimeFactors(num));
  }

  return ans;
}

vector<vector<int>> PrimeFactorisationQueriesOptimized(vector<int> &queries) {
  int N = 1e5;
  vector<int> spf(N + 1);

  // Initialize SPF for every number.
  for (int i = 1; i <= N; i++) {
    spf[i] = i;
  }

  // Build the Smallest Prime Factor array.
  for (int i = 2; i * i <= N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= N; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }

  vector<vector<int>> ans;

  for (int num : queries) {
    vector<int> factors;

    while (num > 1) {
      factors.push_back(spf[num]);
      num /= spf[num];
    }

    ans.push_back(factors);
  }

  return ans;
}

// Brute Force
// TC: O(q * sqrt(N) + F)
// Auxiliary SC: O(log N) per factorization
// Output SC: O(F)

// SPF Optimized
// TC: O(N * log(log(N)) + F)
// Auxiliary SC: O(N)
// Output SC: O(F)

int main() {
  cout << "8 L8 Smallest Prime Factor (SPF) Queries\n";

  vector<int> queries = {12, 18, 25, 100, 97};

  vector<vector<int>> bruteAns = PrimeFactorisationQueriesBrute(queries);

  vector<vector<int>> optimizedAns =
      PrimeFactorisationQueriesOptimized(queries);

  cout << "\nBrute Force:\n";
  for (int i = 0; i < queries.size(); i++) {
    cout << queries[i] << ": ";
    for (int factor : bruteAns[i]) {
      cout << factor << " ";
    }
    cout << endl;
  }

  cout << "\nSPF Optimized:\n";
  for (int i = 0; i < queries.size(); i++) {
    cout << queries[i] << ": ";
    for (int factor : optimizedAns[i]) {
      cout << factor << " ";
    }
    cout << endl;
  }

  return 0;
}
