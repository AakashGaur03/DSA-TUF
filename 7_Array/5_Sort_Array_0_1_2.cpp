#include <bits/stdc++.h>
using namespace std;

int getPartitionIdx(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  // 3 2 1 1 5 4
  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSortPrac(vector<int> &arr, int low, int high) {
  if (low >= high)
    return;

  int partitionInx = getPartitionIdx(arr, low, high);
  quickSortPrac(arr, low, partitionInx - 1);
  quickSortPrac(arr, partitionInx + 1, high);
}

void betterSortArray012(vector<int> &arr, int size) {
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      count0++;
    else if (arr[i] == 1)
      count1++;
    else
      count2++;
  }

  int idx = 0;
  while (count0 > 0) {
    arr[idx] = 0;
    idx++;
    count0--;
  }
  while (count1 > 0) {
    arr[idx] = 1;
    idx++;
    count1--;
  }
  while (count2 > 0) {
    arr[idx] = 2;
    idx++;
    count2--;
  }
}

void optimalSortArray012(vector<int> &arr, int size) {
  // TC O(N)
  // SC O(1)
  int low = 0;
  int mid = 0;
  int high = size - 1;
  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++; // because zero is going to correct place
      mid++; // after swap we are taking 1 from low and placing at mid so also
             // at correct position thats why ++
    } else if (arr[mid] == 1) {
      mid++;
    }
    // arr[mid] == 2
    else {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
  //    0    low-1  low  mid-1  mid      high   high+1     n-1
  //    0000000      1111111     0120121210        2222222222
}
int main() {
  cout << " Array 5" << endl;
  vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 1, 2, 1, 2, 0};

  // brute force
  // Merge Sort or Quick Sort
  // TC O(N LogN)
  quickSortPrac(arr, 0, arr.size() - 1);
  // better
  betterSortArray012(arr, arr.size() - 1);
  // Count1,Count2,Count3 variables in first loop count numbers
  // then one more loop update the values till counts
  // O(2N)

  // optimal
  // Dutch National Flag Algorithm
  // Three pointer
  // low mid high
  // [0 ... low-1]  0
  // [low... mid-1]  1
  // [mid .... high]   random can be 0 1 2
  // [high+1... n-1]  2

  optimalSortArray012(arr, arr.size());
  for (auto it : arr) {
    cout << it;
  }

  //    0    low-1  low  mid-1  mid      high   high+1     n-1
  //    0000000      1111111     0120121210        2222222222
  return 0;
}