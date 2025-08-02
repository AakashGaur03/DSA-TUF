#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForceApproach(vector<int> nums, int size) {
  // TC O(N^2)
  // SC O(1)
  vector<int> ls;

  for (int i = 0; i < size; i++) {
    if (find(ls.begin(), ls.end(), nums[i]) != ls.end()) {
      continue;
    }
    int cnt = 0;
    for (int j = 0; j < size; j++) {
      if (nums[j] == nums[i]) {
        cnt++;
      }
    }
    if (cnt > size / 3) {
      ls.push_back(nums[i]);
    }

    if (ls.size() == 2)
      break;
  }

  return ls;
}
vector<int> betterApproachMajorityElem(vector<int> nums, int size) {
  // TC O(N) O(log n) for map
  // SC O(N)
  vector<int> ls;

  map<int, int> hashMap;

  for (int i = 0; i < size; i++) {
    hashMap[nums[i]]++;
    if (hashMap[nums[i]] > (size / 3) &&
        find(ls.begin(), ls.end(), nums[i]) == ls.end()) {
      ls.push_back(nums[i]);
    }
  }

  return ls;
}
vector<int> optimalhMajorityElem(vector<int> nums, int size) {
  // TC O(2N)
  // SC O(1)
  // Similar as Majority Element approach here we take two cnt and elems to keep
  // track

  int cnt1 = 0, cnt2 = 0;
  int el1 = INT_MIN;
  int el2 = INT_MIN;

  for (int i = 0; i < size; i++) {
    if (cnt1 == 0 && el2 != nums[i]) {
      cnt1 = 1;
      el1 = nums[i];
    } else if (cnt2 == 0 && el1 != nums[i]) {
      cnt2 = 1;
      el2 = nums[i];
    } else if (nums[i] == el1) {
      cnt1++;
    } else if (nums[i] == el2) {
      cnt2++;
    } else {
      cnt1--;
      cnt2--;
    }
  }
  vector<int> ls;
  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < size; i++) {
    if (el1 == nums[i])
      cnt1++;
    if (el2 == nums[i])
      cnt2++;
  }

  int mini = (int)(size / 3) + 1;
  if (cnt1 >= mini)
    ls.push_back(el1);
  if (cnt2 >= mini)
    ls.push_back(el2);

  return ls;
}

int main() {
  cout << "Array 2";
  // Return number of integers that appears more that n/3 times
  // At Max we can get 2 integers that appear more that n/3 times

  vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

  vector<int> ans = bruteForceApproach(nums, nums.size());

  cout << " ";
  for (auto it : ans) {
    cout << it << " ";
  }
  vector<int> ans2 = betterApproachMajorityElem(nums, nums.size());

  cout << " ";
  for (auto it2 : ans2) {
    cout << it2 << " ";
  }
  vector<int> ans3 = optimalhMajorityElem(nums, nums.size());

  cout << " ";
  for (auto it3 : ans3) {
    cout << it3 << " ";
  }

  return 0;
}