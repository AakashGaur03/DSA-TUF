#include <bits/stdc++.h>
using namespace std;
int bruteLargestElement(vector<int> &arr, int size) {
  sort(arr.begin(), arr.end());
  return arr[arr.size() - 1];
}
int optimalLargestElement(vector<int> &arr, int size) {
  int largest = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

int bruteSecondLargestElement(vector<int> &arr, int size) {
  // TC O(nlogn + n)
  // nlogn for sorting
  // n in worst case if arr is something like [1,4,4,4,4,4]
  sort(arr.begin(), arr.end());
  int largest = arr[arr.size() - 1];
  for (int i = size - 2; i >= 0; i--) {
    if (arr[i] != largest) {
      return arr[i];
    }
  }
  return -1;
}

int betterSecondLargestElement(vector<int> &arr, int size) {
  // TC O(n + n)

  int largest = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  int secLar = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] > secLar && arr[i] != largest) {
      secLar = arr[i];
    }
  }
  return secLar;
}
int optimalSecondLargestElement(vector<int> &arr, int size) {
  // TC O(n)
  int largest = arr[0];
  int secLar = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] > largest) {
      secLar = largest;
      largest = arr[i];
    } else if (arr[i] > secLar && arr[i] < largest) {
      secLar = arr[i];
    }
  }

  return secLar;
}

bool checkArraySorted(vector<int> &arr, int size) {
  // here till size -1 because we are checking for arr[i+1] so if we do it for
  // size then for last index will go overflow
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

int bruteRemoveDuplicateElements(vector<int> &arr, int size) {
  // TC (N logn + N)
  // SC (N) set
  set<int> st;

  // N Log n
  for (int i = 0; i < size; i++) {
    st.insert(arr[i]);
  }

  for (auto it : st) {
    cout << it << " ";
  }
  int index = 0;

  // N
  for (auto it2 : st) {
    arr[index] = it2;
    index++;
  }
  arr.resize(index);
  return index;
}
int optimizedRemoveDuplicateElements(vector<int> &arr, int size) {
  // TC O(N)
  // SC O(1)
  int j = 1;
  int i = 0;
  while (j < size) {
    if (arr[i] != arr[j]) {
      arr[i + 1] = arr[j];
      i++;
    }
    j++;
  }
  arr.resize(i + 1);
  for (auto it : arr) {
    cout << it << " ";
  }
  return i + 1;
}

void leftRotateArrayByOnePlace(vector<int> &arr, int size) {
  // TC O(N)
  // SC O(1) extra space
  // But in algo we need to mention that we are using O(N) that is existing arr
  // only
  int temp = arr[0];
  for (int i = 1; i < size; i++) {
    arr[i - 1] = arr[i];
  }
  arr[size - 1] = temp;
  for (auto it : arr) {
    cout << it << " ";
  }
}
int main() {
  cout << "Array" << endl;
  // Data Structure that contains similar data type
  // can be integer, char, string, pair<int,int>,etc
  // When declared in main
  // int arr[6];
  // defined with size 6 with garbage values
  // int arr[10^6] max size in main
  // When declared outside main that is globally
  // int arr[6];
  // defined with size 6 with 0 value at each index
  // int arr[10^7] max size outside main(globally)

  // Largest Element in array
  // arr[] = [ 3, 2, 1, 5, 2 ]
  // vector<int> arr = {3, 2, 1, 5, 2, 12, 12};
  // vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr = {1, 1, 2, 3, 3, 3, 5, 12, 12};

  // int res = bruteLargestElement(arr, arr.size());
  // cout << "Largest Elem is :" << res << endl;
  // int res2 = optimalLargestElement(arr, arr.size());
  // cout << "Largest Elem is :" << res2;
  // int res = bruteSecondLargestElement(arr, arr.size());
  // cout << "Brute Second Largest Elem is :" << res << endl;
  // int res2 = betterSecondLargestElement(arr, arr.size());
  // cout << "Better Second Largest Elem is :" << res2 << endl;
  // int res3 = optimalSecondLargestElement(arr, arr.size());
  // cout << "Optimal Second Largest Elem is :" << res3 << endl;
  // bool res3 = checkArraySorted(arr, arr.size());
  // cout << "Sorted Or Not :" << res3 << endl;

  // remove in place from sorted array and return number of unique elements
  // int result = bruteRemoveDuplicateElements(arr, arr.size());
  // cout << endl;
  // for (auto it : arr) {
  //   cout << it << " ";
  // }
  // cout << endl;
  // cout << "Final Result That is Total Elements :" << result;

  // int optimizedRes = optimizedRemoveDuplicateElements(arr, arr.size());
  // cout << endl;
  // cout << "Final Result That is Total Elements Optimized :" << optimizedRes;

  // Left Rotate Array by One Place in place
  leftRotateArrayByOnePlace(arr, arr.size());
  return 0;
}