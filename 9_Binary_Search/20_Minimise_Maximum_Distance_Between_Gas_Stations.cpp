#include <bits/stdc++.h>
using namespace std;

// Max distance is to be minimised

// We place the gas station in between only to reduce the distance

// we find gap between two gas stations
// Ex arr= {1,7} k = 2
// The gap is 6 we need to place 2 gas stations between 1 and 7 that is gap 6 so
// we need three numbers between 1 and 7 means if we place 2 gas stations 1 __ |
// __ | __ 7 So we are having three numbers in between so we do gap / k+1 6/2+1
// = 2 so gap is 2 1 3 | 5 | 7
// | is the gas station placed so minimum distance comes 2
// Example
//               1  13 17 23 k = 5
// Distance is    12  4  6
// So we have 3 gaps/sections in start where we will place gas stations
//  0_0_0  // Gas stations Placed at each section
// so 12 is maximum we place First Gas station at 12
//               1  13 17 23 k = 5
// Distance is    12  4  6
//  1_0_0  // Gas stations Placed at each section
// so we do gap / k+1 =  12/1+1 = 6
//  1_0_0  // Gas stations Placed at each section
//               1  13 17 23 k = 1
// Distance is    6  4  6
// WE can place at now 1st 6 and thrd section that is also 6
// 1 7 13 17 13 // Max Distance is 6
// Assume we place at 3 Section
//  1_0_1  // Gas stations Placed at each section
// so we do gap/k+1 =  6/1+1 = 3 // TWO GAS STATION PLACED
//               1  13 17 23 k = 2
// Distance is    6  4   3
// Now max gap is 6 at section 1
//  2_0_1  // Gas stations Placed at each section
// so we do gap/k+1 =  6/2+1 = 2 // Third GAS STATION PLACED
//               1  13 17 23 k = 3
// Distance is    2  4   3
// Now max gap is 6 at section 1
//  2_0_1  // Gas stations Placed at each section
// so we do gap/k+1 =  12/2+1 = 4 // Third GAS STATION PLACED
//               1  13 17 23 k = 3
// Distance is    4  4   3
// Now max gap is 4 at section 2
//  2_1_1  // Gas stations Placed at each section
// so we do gap/k+1 =  4/1+1 = 2 // Fourth GAS STATION PLACED
//               1  13 17 23 k = 3
// Distance is    4   2   3
// Now max gap is 4 at section 1
//  3_1_1  // Gas stations Placed at each section
// so we do gap/k+1 =  12/3+1 = 3 // FIFTH GAS STATION PLACED
//               1  13 17 23 k = 3
// Distance is    3   2   3

// After Placing All 5 Gas Stations Max distance that is minimised is 3
// So Answer is 3

long double bruteGasStations(vector<int> arr, int size, int k) {
  // TC )(K*N) + N
  vector<int> howMany(size - 1, 0);
  for (int gasStations = 1; gasStations <= k; gasStations++) {
    long double maxSection = -1; // Max Gap
    int maxInd = -1;             // Maximum Gap Index

    for (int i = 0; i < size - 1; i++) {
      long double diff = arr[i + 1] - arr[i]; // Gap between all
      long double sectionLength = diff / (long double)(howMany[i] + 1);
      // This is gap/k+1;
      // If Gap > maxSection
      if (sectionLength > maxSection) {
        maxSection = sectionLength;
        maxInd = i;
      }
      // we will add a gas station there
    }
    howMany[maxInd]++;
  }
  // Before this we have dedided at each section
  // How many Gas stations
  long double maxAns = -1;
  for (int i = 0; i < size - 1; i++) {
    long double diff = arr[i + 1] - arr[i];
    // Calculating Gap after placing the gas Stations
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    // Max one is answer
    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}

long double optimalPQGasStations(vector<int> arr, int size, int k) {
  // TC (N logN + K logN)
  // SC O(N-1)
  vector<int> howMany(size - 1, 0);
  priority_queue<pair<long double, int>> pq;
  // Priority queue keeps maximum at top
  // We are pushing the Gaps in priority queue with there index like
  // like {12,0}  {4,1}  {6,2}
  for (int i = 0; i < size - 1; i++) {
    pq.push({arr[i + 1] - arr[i], i});
  }
  // For each Gas station
  for (int gasStations = 1; gasStations <= k; gasStations++) {
    // On top will be of maximum one only In first case that is 12
    auto tp = pq.top();
    pq.pop();
    // Section index is 0
    int secInd = tp.second;
    // We increase the placed at that index
    howMany[secInd]++;
    // So now At index 0 we are placing 1
    long double iniDiff = arr[secInd + 1] - arr[secInd];
    // The Diff at that index that is 12
    long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
    // The Diff at that index that is 12/1+1 = 6
    // Above we did pq.pop to remove 12,0
    pq.push({newSecLen, secInd});
    // Now we enterd 6,1 in place of it
  }

  // And in the end of the loop we will have maximum on top only that is {3,2}
  // so 3 will be answer
  return pq.top().first;
}

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
  int cnt = 0;
  for (int i = 1; i < arr.size(); i++) {
    // This gives how many number of gas stations we are placing in between of
    // differnece
    // Example if we take dist = 0.4 and its like 1 2
    // So between 1/0.4 we can place 2.5 gas stations
    // that is 2. something
    int numberInBetween = ((arr[i] - arr[i - 1]) / dist);

    // This check is done to check exact division cases like
    // Example if we take dist = 0.5 and its like 1 2
    // So between 1/0.5 we can place 1 gas stations but division
    // gives 2 so that is not possible so in exact division cases
    // we decrement that number
    if ((arr[i] - arr[i - 1]) / dist == numberInBetween * dist) {
      numberInBetween--;
    }
    cnt += numberInBetween;
  }
  // Return total of gas station required
  // To Slightly Optimize we can send K too and whenever k exceeds cnt
  // we can break out and save some operation
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
  // In start we have low= 0 and high = maximum of the gap between all the index
  // Because we want to reduce the gap as much as possible so it will liw
  // between this range
  // Here we can to like low<=high low = mid + 1 or high = mid - 1
  // Because we will lose so many cases in between
  // So we will have slightly differnet approach
  long double diff = 1e-6;
  // This is 10^-6 that is given range till we have to return answer
  // THis changes acc to question need that is if asked required till 10^-7 so
  // changes to that
  // Range shifts that if high - low is between 6 decimal places
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
