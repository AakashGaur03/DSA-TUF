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

void brureLeftRotateArrayByDPlace(vector<int> &arr, int d, int size) {
  // TC O(d) + O(n-d) + O(d) => O(d+n)
  // SC (d)
  d = d % size;

  vector<int> temp(d);
  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }

  for (int i = d; i < size; i++) {
    arr[i - d] = arr[i];
  }

  for (int i = 0; i < d; i++) {
    arr[size - d + i] = temp[i];
  }
}
void optimalLeftRotateArrayByDPlace(vector<int> &arr, int d, int size) {
  // Reverse (a,a+d)  O(d)
  // Reverse (a+d,a+n) O(n-d)
  // Reverse (a,a+n) O(n)
  // TC O(2n)
  // SC O(1)

  // void reverseArray(vector<int> &arr, int start, int end) {
  //   while (start < end) {
  //     swap(arr[start], arr[end]);
  //     start++;
  //     end--;
  //   }
  // }
  d = d % size;
  reverse(arr.begin(), arr.begin() + d);
  reverse(arr.begin() + d, arr.begin() + size);
  reverse(arr.begin(), arr.begin() + size);
}

void bruteMoveZeroesToEnd(vector<int> &arr, int size) {
  // TC O(2N)
  // SC O(X) X is number of 0
  // SC O(N) worst case all are zero
  vector<int> temp;
  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }
  for (int i = 0; i < temp.size(); i++) {
    arr[i] = temp[i];
  }
  for (int i = temp.size(); i < size; i++) {
    arr[i] = 0;
  }
}
void optimalMoveZeroesToEnd(vector<int> &arr, int size) {
  // Two Pointer Approach
  // swap coming 0 with non zero number
  // TC O(N)
  // SC O(1)
  int j = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
  // Use Above Approach for cleaner code unless swap optimization is
  // specifically required.

  // Use Below Approach if interviewer asks for early exit when no zero, or
  // minimum swaps. Optinal Approach

  // int j = -1;
  // for (int i = 0; i < size; i++)
  // {
  //   if (arr[i] == 0) {
  //     j = i;
  //     break;
  //   }
  // }
  // if (j == -1)
  //   return;
  // for (int i = j + 1; i < size; i++) {
  //   if (arr[i] != 0) {
  //     swap(arr[i], arr[j]);
  //     j++;
  //   }
  // }
}

int linearSearch(vector<int> arr, int size, int numSearch) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == numSearch) {
      return i;
    }
  }

  return -1;
}

vector<int> bruteUnionOfSortedArrays(vector<int> arr1, vector<int> arr2) {
  // TC O(n1 logn) O(n1 logn) + O(n1+n2)
  // SC O(n1 +n2) for set + O(n1 +n2) for uniqueArr
  set<int> st;
  vector<int> unionArr;
  // O(n1 logn)
  for (int i = 0; i < arr1.size(); i++) {
    st.insert(arr1[i]);
  }
  // O(n2 logn)
  for (int i = 0; i < arr2.size(); i++) {
    st.insert(arr2[i]);
  }
  for (auto it : st) {
    unionArr.push_back(it);
  }
  cout << endl;
  return unionArr;
}
vector<int> optimalUnionOfSortedArrays(vector<int> arr1, vector<int> arr2) {
  // TC O(n1+n2)
  // SC O(n1+n2) only for uniqueArr
  int n1 = arr1.size();
  int n2 = arr2.size();
  int i = 0;
  int j = 0;
  vector<int> unionArr;

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
        unionArr.push_back(arr1[i]);
      }
      i++;
    } else {
      if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
        unionArr.push_back(arr2[j]);
      }
      j++;
    }
  }

  while (j < n2) {
    if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
      unionArr.push_back(arr2[j]);
    }
    j++;
  }
  while (i < n1) {
    if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
      unionArr.push_back(arr1[i]);
    }
    i++;
  }
  return unionArr;
}

vector<int> bruteIntersectionArr(vector<int> arr1, vector<int> arr2) {
  // TC O(n1 X n2)
  // SC O(n2)
  vector<int> intersectedArr;
  vector<int> visi(arr2.size(), 0);
  for (int i = 0; i < arr1.size(); i++) {
    for (int j = 0; j < arr2.size(); j++) {
      if (arr1[i] == arr2[j] && visi[j] == 0) {
        intersectedArr.push_back(arr1[i]);
        visi[j] = 1;
        break;
      }
      if (arr2[j] > arr1[i])
        break;
    }
  }
  return intersectedArr;
}

vector<int> optimalIntersectionArr(vector<int> arr1, vector<int> arr2) {
  // TC O(n1+n2)
  // SC O(min(n1+n2))
  vector<int> intersectedArr;
  int i = 0;
  int j = 0;
  int n1 = arr1.size();
  int n2 = arr2.size();
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      i++;
    } else if (arr2[j] < arr1[i]) {
      j++;
    } else
    // (arr1[i] == arr2[j])
    {
      intersectedArr.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  return intersectedArr;
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
  // vector<int> arr = {1, 1, 2, 3, 3, 3, 5, 12, 12};
  vector<int> arr = {0, 1, 0, 1, 2, 0, 3, 3, 3, 5, 12, 0, 0, 12, 0, 0};
  vector<int> arr1 = {1, 2, 2, 3, 4, 4, 5};
  vector<int> arr2 = {2, 2, 3, 5, 5, 8};

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
  // leftRotateArrayByOnePlace(arr, arr.size());
  int d = 4;
  // brureLeftRotateArrayByDPlace(arr, d, arr.size());
  // optimalLeftRotateArrayByDPlace(arr, d, arr.size());

  // bruteMoveZeroesToEnd(arr, arr.size());
  // optimalMoveZeroesToEnd(arr, arr.size());
  // for (auto it : arr) {
  //   cout << it << " ";
  // }
  // cout << endl;
  // cout << "Index is :" << linearSearch(arr, arr.size(), 1);

  // Union of two sorted Array
  // vector<int> res = bruteUnionOfSortedArrays(arr1, arr2);

  // for (auto it : res) {
  //   cout << it << " ";
  // }
  // vector<int> res = optimalUnionOfSortedArrays(arr1, arr2);
  // cout << "Optimal :";
  // for (auto it : res) {
  //   cout << it << " ";
  // }
  // vector<int> res = bruteIntersectionArr(arr1, arr2);
  // for (auto it : res) {
  //   cout << it << " ";
  // }
  vector<int> res = optimalIntersectionArr(arr1, arr2);
  for (auto it : res) {
    cout << it << " ";
  }
  return 0;
}