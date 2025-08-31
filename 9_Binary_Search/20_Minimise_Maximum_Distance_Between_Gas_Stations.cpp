#include <bits/stdc++.h>
using namespace std;

long double bruteGasStations(vector<int> arr, int size, int k) {
  // TC )(K*N) + N
  vector<int> howMany(size - 1, 0);
  for (int gasStations = 1; gasStations <= k; gasStations++) {
    long double maxSection = -1;
    int maxInd = -1;

    for (int i = 0; i < size - 1; i++) {
      long double diff = arr[i + 1] - arr[i];
      long double sectionLength = diff / (long double)(howMany[i] + 1);

      if (sectionLength > maxSection) {
        maxSection = sectionLength;
        maxInd = i;
      }
    }
    howMany[maxInd]++;
  }

  long double maxAns = -1;
  for (int i = 0; i < size - 1; i++) {
    long double diff = arr[i + 1] - arr[i];
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}

long double optimalPQGasStations(vector<int> arr, int size, int k) {
  // TC (N logN + K logN)
  // SC O(N-1)
  vector<int> howMany(size - 1, 0);
  priority_queue<pair<long double, int>> pq;

  for (int i = 0; i < size - 1; i++) {
    pq.push({arr[i + 1] - arr[i], i});
  }

  for (int gasStations = 1; gasStations <= k; gasStations++) {
    auto tp = pq.top();
    pq.pop();
    int secInd = tp.second;
    howMany[secInd]++;
    long double iniDiff = arr[secInd + 1] - arr[secInd];
    long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
    pq.push({newSecLen, secInd});
  }

  return pq.top().first;
}

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
  int cnt = 0;
  for (int i = 1; i < arr.size(); i++) {
    int numberInBetween = ((arr[i] - arr[i - 1]) / dist);

    if ((arr[i] - arr[i - 1]) / dist == numberInBetween * dist) {
      numberInBetween--;
    }
    cnt += numberInBetween;
  }

  return cnt;
}

long double optimalBSGasStations(vector<int> arr, int size, int k) {
  // TC (N logN + N)
  // SC O(1)

  long double low = 0;
  long double high = 0;

  for (int i = 0; i < size - 1; i++) {
    high = max(high, (long double)(arr[i + 1] - arr[i]));
  }
  long double diff = 1e-6;
  while (high - low > diff) {
    long double mid = (low + high) / (2.0);
    int cnt = numberOfGasStationsRequired(mid, arr);
    if (cnt > k) {
      low = mid;
    } else {
      high = mid;
    }
  }

  return high;
}

int main() {
  cout << "20 BS" << endl;
  // Minimise Maximum Distance Between Gas Stations
  // Binary Search on Doubles
  vector<int> arr = {1, 2, 3, 4, 5};
  //   vector<int> arr = {1, 12, 17, 31};
  int k = 4;
  // we have to place k gas stations in interval so that the distance between
  // each gas station is minimum and we have to return maximum of that value We
  // can place at decomal positions too
  long double res = bruteGasStations(arr, arr.size(), k);
  cout << res << endl;
  long double res2 = optimalPQGasStations(arr, arr.size(), k);
  cout << res2 << endl;
  long double res3 = optimalBSGasStations(arr, arr.size(), k);
  cout << res3 << endl;
  return 0;
}

// You are given an array arr representing the positions of existing gas
// stations on a number line (sorted in increasing order). You are also given an
// integer k, representing the number of additional gas stations you can build
// anywhere along the road (even at decimal positions).

//  Your goal is to minimize the maximum distance between adjacent gas stations
//  after placing the new ones.
// Return that minimized maximum distance (as a floating point / double).