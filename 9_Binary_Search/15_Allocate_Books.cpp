#include <bits/stdc++.h>
using namespace std;

int maximumArr(vector<int> arr, int size) {
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++) {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}
int sumOfAllinArr(vector<int> arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}
bool studentsAllotedBooks(vector<int> arr, int size, int students,
                          int pageAlloted) {
  int count = 1;
  int pages = 0;
  for (int i = 0; i < size; i++) {
    if (pages + arr[i] > pageAlloted) {
      count++;
      pages = arr[i];
    } else {
      pages = pages + arr[i];
    }
  }
  if (count > students)
    return false;
  else {
    return true;
  }
}
int bruteAllocateBooks(vector<int> bookArr, int size, int students) {
  // TC O(max - sum of all) * N
  int res = maximumArr(bookArr, size);
  if (students > size)
    return -1;

  for (int i = maximumArr(bookArr, size); i <= sumOfAllinArr(bookArr, size);
       i++) {
    if (studentsAllotedBooks(bookArr, size, students, i)) {
      res = i;
      break;
    }
  }

  return res;
}
int optimalBSAllocateBooks(vector<int> bookArr, int size, int students) {
  // TC O(log(max - sum of all)) * N
  if (students > size)
    return -1;

  int low = maximumArr(bookArr, size);
  int high = sumOfAllinArr(bookArr, size);

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (studentsAllotedBooks(bookArr, size, students, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  // Acc to Opposite Polarity
  // At start
  // Low is Not possible
  // High is  possible
  //   When the loop ends,
  // low is the first possible answer (minimum maximum pages).
  // high is the last impossible answer.
  return low;
}

int main() {
  cout << "15 BS" << endl;
  // Allocate Minimum Number of Pages Problem:
  // Given 'n' books with pages[] and 'm' students,
  // we need to allocate books in order such that each student gets
  // at least one book and the maximum number of pages assigned
  // to any student is minimized.

  vector<int> bookArr = {25, 46, 28, 49, 24};
  int students = 4;
  int res = bruteAllocateBooks(bookArr, bookArr.size(), students);
  cout << res << endl;
  int res2 = optimalBSAllocateBooks(bookArr, bookArr.size(), students);
  cout << res2 << endl;
  return 0;
}