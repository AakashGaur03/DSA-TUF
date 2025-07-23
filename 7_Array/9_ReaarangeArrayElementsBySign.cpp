#include <bits/stdc++.h>
using namespace std;
// Rearrange by Sign + - + - + - ...
// Equal Positive and negative Number

int bruteReaarangeArrayElementsBySign(vector<int> &arr, int size) {
  // TC O(2N)
  // SC O(N)
  // Get Two Array Postitves and Negatives and then fill them in answer
  vector<int> positives;
  vector<int> negatives;

  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      positives.push_back(arr[i]);
    } else {
      negatives.push_back(arr[i]);
    }
  }

  for (int i = 0; i < negatives.size(); i++) {
    arr[2 * i + 1] = negatives[i];
  }
  for (int i = 0; i < positives.size(); i++) {
    arr[2 * i] = positives[i];
  }

  return 0;
}
vector<int> optimalReaarangeArrayElementsBySign(vector<int> &arr, int size) {

  // TC O(N)
  // SC O(N)

  vector<int> ans(size, 0);
  int posIndex = 0;
  int negIndex = 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] < 0) {
      ans[negIndex] = arr[i];
      negIndex += 2;
    } else {
      ans[posIndex] = arr[i];
      posIndex += 2;
    }
  }

  return ans;
}

// Alternate Numbers
// There are postives and negatives place in order + - + - but they are not in
// equal number so left one either positives or negatives place them in last WE
// Fall back to Brute Force Get Two Array Postitves and Negatives and then fill
// them in answer one by one which one is greater is filled at the back

vector<int> alternateNumbers(vector<int> &arr, int size) {
  // TC O(N) + O(min(pos,neg)) + O(leftovers) that will be
  // TC O(N) + O(N)
  // SC O(N)

  // Get Two Array Postitves and Negatives and then fill them in answer and in
  // last fill remaining ones
  vector<int> positives;
  vector<int> negatives;

  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      positives.push_back(arr[i]);
    } else {
      negatives.push_back(arr[i]);
    }
  }

  // Step 2: Start filling elements alternatively into the original array
  // If there are more positives than negatives
  if (positives.size() > negatives.size()) {
    // This complates equal number of elements
    // Fill alternatively till negatives are exhausted
    for (int i = 0; i < negatives.size(); i++) {
      arr[2 * i] = positives[i];     // Place positive at even index
      arr[2 * i + 1] = negatives[i]; // Place negative at odd index
    }

    // Step 3: Fill remaining positives at the end
    int idx = negatives.size() * 2; // Start placing from after the last pair
    for (int i = negatives.size(); i < positives.size(); i++) {
      arr[idx] = positives[i];
      idx++;
    }

  } else {
    for (int i = 0; i < positives.size(); i++) {
      arr[2 * i] = positives[i];
      arr[2 * i + 1] = negatives[i];
    }

    int idx = positives.size() * 2;
    for (int i = positives.size(); i < negatives.size(); i++) {
      arr[idx] = negatives[i];
      idx++;
    }
  }

  return arr;
}

int main() {
  cout << "Array 8" << endl;
  ;
  vector<int> arr = {-2, 2, -3, -5, 4, 3};

  // Create two Array of n/2 one with positive and one with negative then place
  // in original Array
  // int res = bruteReaarangeArrayElementsBySign(arr, arr.size());
  // cout << endl << res;
  // for (auto it : arr) {
  //   cout << it << " ";
  // }
  vector<int> res2 = optimalReaarangeArrayElementsBySign(arr, arr.size());

  for (auto it : res2) {
    cout << it << " ";
  }
  return 0;
}
