#include <bits/stdc++.h>
using namespace std;

vector<int> prefixMax(vector<int> building) {
  // TC O(N)
  // SC O(N)
  // means maximum of all the elements till that index
  // Refer to 12_L8_Trapping_Rainwater_3
  int size = building.size();
  vector<int> prefix(size);

  prefix[0] = building[0];
  for (int i = 1; i < size; i++) {
    prefix[i] = max(prefix[i - 1], building[i]);
  }
  return prefix;
}

vector<int> suffixMax(vector<int> building) {
  // TC O(N)
  // SC O(N)
  // means maximum of all the elements till that index from back
  // Refer to 12_L8_Trapping_Rainwater_4
  int size = building.size();
  vector<int> suffix(size);

  suffix[size - 1] = building[size - 1];
  for (int i = size - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], building[i]);
  }
  return suffix;
}

int trappingRainWaterBrute(vector<int> building) {
  // TC O(3N)
  // TC O(2N)
  // Refer to 12_L8_Trapping_Rainwater_1 12_L8_Trapping_Rainwater_2
  int total = 0;
  int size = building.size();
  vector<int> allPrefix = prefixMax(building); // TC O(N) SC O(N)
  vector<int> allSuffix = suffixMax(building); // TC O(N) SC O(N)
  for (int i = 0; i < size; i++) {             // TC O(N)
    int leftMax = allPrefix[i];
    // This can be done without Prefix Max if we just simple define it at top
    // with 0 (outside loop) take LeftMax simply
    //  leftMax = max(leftMax, building[i]);
    int rightMax = allSuffix[i];
    if (building[i] < leftMax && building[i] < rightMax) {
      total += min(rightMax, leftMax) - building[i];
    }
  }

  return total;
}

int main() {
  cout << "12 L8 Trapping Rainwater" << endl;
  vector<int> building = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int res = trappingRainWaterBrute(building);
  cout << "Trapped Rail Water is: " << res << endl;
  return 0;
}
