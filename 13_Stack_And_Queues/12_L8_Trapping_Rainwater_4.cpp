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

int trappingRainWaterOptimized(vector<int> building) {
  // TC O(N)
  // SC O(1)

  int n = building.size();
  int left = 0, right = n - 1;
  int leftMax = 0, rightMax = 0;
  int total = 0;
  while (left < right) {
    if (building[left] <= building[right]) {
      if (leftMax > building[left]) {
        total += leftMax - building[left];
      } else {
        leftMax = building[left];
      }
      left++;
    } else {
      if (rightMax > building[right]) {
        total += rightMax - building[right];
      } else {
        rightMax = building[right];
      }
      right--;
    }
  }
  return total;
}

int main() {
  cout << "12 L8 Trapping Rainwater" << endl;
  vector<int> building = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int res = trappingRainWaterBrute(building);
  cout << "Trapped Rain Water is: " << res << endl;

  int res2 = trappingRainWaterOptimized(building);
  cout << "Trapped Rain Water is: " << res2 << endl;
  return 0;
}

// EXPLAINAITON
// int trappingRainWaterOptimized(vector<int> building) {
//   // TC O(N)  → We traverse the array only once
//   // SC O(1)  → No extra arrays are used

//   int n = building.size();

//   // Two pointers: one from the left, one from the right
//   int left = 0, right = n - 1;

//   // leftMax  → maximum height encountered so far from the left
//   // rightMax → maximum height encountered so far from the right
//   int leftMax = 0, rightMax = 0;

//   // Variable to store total trapped rain water
//   int total = 0;

//   // Continue until both pointers meet
//   while (left < right) {

//     // If left building is smaller or equal,
//     // water trapped depends on leftMax
//     if (building[left] <= building[right]) {

//       // If current building is smaller than leftMax,
//       // water can be trapped
//       if (leftMax > building[left]) {
//         total += leftMax - building[left];
//       }
//       // Otherwise, update leftMax
//       else {
//         leftMax = building[left];
//       }

//       // Move left pointer forward
//       left++;
//     }

//     // If right building is smaller,
//     // water trapped depends on rightMax
//     else {

//       // If current building is smaller than rightMax,
//       // water can be trapped
//       if (rightMax > building[right]) {
//         total += rightMax - building[right];
//       }
//       // Otherwise, update rightMax
//       else {
//         rightMax = building[right];
//       }

//       // Move right pointer backward
//       right--;
//     }
//   }

//   // Return total trapped water
//   return total;
// }
