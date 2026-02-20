#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfTrainsRequiredBrute(vector<int> &arr, vector<int> &dep) {
  // TC O(N^2)
  // SC O(1)
  int maxCnt = 0;
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    int cnt = 1;
    for (int j = i + 1; j < size; j++) {

      // Check if there is overlap between train i and j
      if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
          (arr[j] >= arr[i] && arr[j] <= dep[i])) {
        cnt++;
      }
      maxCnt = max(maxCnt, cnt);
    }
  }
  return maxCnt;
}
int minimumNumberOfTrainsRequiredOptimal(vector<int> &arr, vector<int> &dep) {
  // TC O(2N logN + 2N)
  // SC O(1)
  int maxCnt = 0;
  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());
  int size = arr.size();

  int i = 0;
  int j = 0;

  int cnt = 0;
  while (i < size && j < size) {

    if (arr[i] < dep[j]) {
      cnt++;
      i = i + 1;
    } else {
      cnt--;
      j = j + 1;
    }
    maxCnt = max(maxCnt, cnt);
  }

  return maxCnt;
}

int main() {
  cout << "8 L10 Minimum number of platforms required in a railway station"
       << endl;
  vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
  vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};

  // arr is arrival time
  // dep is departure time

  // Minimum Number of platform so all trains that can arrive and depart on time
  // Refer 8_L10_Minimum_number_of_platforms_required_in_a_railway_station_1 and
  // 8_L10_Minimum_number_of_platforms_required_in_a_railway_station_2

  cout << minimumNumberOfTrainsRequiredBrute(arr, dep) << endl;
  ;
  cout << minimumNumberOfTrainsRequiredOptimal(arr, dep) << endl;
  ;
  return 0;
}
