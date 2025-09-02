#include <bits/stdc++.h>
using namespace std;

double bruteMedian(vector<int> &a, vector<int> &b) {
  // TC O(N1+N2)
  // SC O(N1+N2)
  vector<int> arr3;

  int n1 = a.size();
  int n2 = b.size();

  int i = 0;
  int j = 0;

  while (i < n1 && j < n2) {
    if (a[i] < b[j]) {
      arr3.push_back(a[i++]);
    } else {
      arr3.push_back(b[j++]);
    }
  }
  while (i < n1)
    arr3.push_back(a[i++]);
  while (j < n2)
    arr3.push_back(b[j++]);

  int n = n1 + n2;
  if (n % 2 == 1) {
    return arr3[n / 2];
  } else {
    return (arr3[n / 2] + arr3[n / 2 - 1]) / 2.0;
  }
}

double betterMedian(vector<int> &a, vector<int> &b) {
  // TC O(N1+N2)
  // SC O()
  int n1 = a.size();
  int n2 = b.size();

  int i = 0;
  int j = 0;
  int n = n1 + n2;
  int ind2 = n / 2;
  int ind1 = ind2 - 1;

  int tracker = 0;
  int ind1El = -1;
  int ind2El = -1;

  while (i < n1 && j < n2) {

    if (a[i] < b[j]) {
      if (tracker == ind1) {
        ind1El = a[i];
      }
      if (tracker == ind2) {
        ind2El = a[i];
      }
      tracker++;
      i++;
    } else {
      if (tracker == ind1) {
        ind1El = b[j];
      }
      if (tracker == ind2) {
        ind2El = b[j];
      }
      tracker++;
      j++;
    }
  }

  while (i < n1) {
    if (tracker == ind1) {
      ind1El = a[i];
    }
    if (tracker == ind2) {
      ind2El = a[i];
    }
    tracker++;
    i++;
  }
  while (j < n2) {
    if (tracker == ind1) {
      ind1El = b[j];
    }
    if (tracker == ind2) {
      ind2El = b[j];
    }
    tracker++;
    j++;
  }
  if (n % 2 == 1) {
    return ind2El;
  } else {
    return (ind1El + ind2El) / 2.0;
  }
}
int main() {
  cout << "21 Median Of Two Sorted Arrays Different Size" << endl;
  // EX arr1 = {1,3,4,7,10,12} arr2={2,3,6,15}
  //   1,2,3,3,4,6,7,10,12,15
  // median = 4+6/2 = 5 (Because Even number of elements)

  // EX arr1 = {2,3,4} arr2={1,3}
  // so 1 2 3 3 4
  // Median = 3 middle element
  vector<int> arr1 = {1, 3, 4, 7, 10, 12};
  vector<int> arr2 = {2, 3, 6, 15};
  double ans1 = bruteMedian(arr1, arr2);
  cout << "Median = " << ans1 << endl;
  double ans2 = betterMedian(arr1, arr2);
  cout << "Median = " << ans2 << endl;
  return 0;
}