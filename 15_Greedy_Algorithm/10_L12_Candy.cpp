#include <bits/stdc++.h>
using namespace std;

int candyBrute(vector<int> rating) {
  // TC O(3N)
  // SC O(2N)

  // We will be taking left neighbours and right neighbours then taking max from
  // them and adding that
  // Refer 10_L12_Candy_1 & 10_L12_Candy_2
  int size = rating.size();
  vector<int> left(size);
  vector<int> right(size);
  left[0] = 1;
  right[size - 1] = 1;

  for (int i = 1; i < size; i++) {
    if (rating[i] > rating[i - 1]) {
      left[i] = left[i - 1] + 1;
    } else {
      left[i] = 1;
    }
  }
  for (int i = size - 2; i >= 0; i--) {
    if (rating[i] > rating[i + 1]) {
      right[i] = right[i + 1] + 1;
    } else {
      right[i] = 1;
    }
  }
  int res = 0;
  for (int i = 0; i < size; i++) {
    res += max(left[i], right[i]);
  }

  return res;
}

int candyBetter(vector<int> rating) {
  // TC O(2N)
  // SC O(N)

  // Same approach will be removing Right array
  //  and computing it on the fly
  int size = rating.size();
  vector<int> left(size);
  left[0] = 1;

  for (int i = 1; i < size; i++) {
    if (rating[i] > rating[i - 1]) {
      left[i] = left[i - 1] + 1;
    } else {
      left[i] = 1;
    }
  }
  int right = 1;
  int res = max(1, left[size - 1]);

  for (int i = size - 2; i >= 0; i--) {
    if (rating[i] > rating[i + 1]) {
      right++;
    } else {
      right = 1;
    }
    res += max(left[i], right);
  }

  return res;
}

int candyOptimal(vector<int> rating) {
  // TC O(N)
  // SC O(1)
  // We will be using the concept of slope
  // Refer 10_L12_Candy_3, 10_L12_Candy_4, 10_L12_Candy_5 & 10_L12_Candy_6

  int size = rating.size();
  if (size == 0)
    return 0;

  int sum = 1;
  int i = 1;

  while (i < size) {
    if (rating[i] == rating[i - 1]) {
      sum++; // add ones
      i++;
      continue;
    }
    // increasing slope
    int peak = 1;
    while (i < size && rating[i] > rating[i - 1]) {
      peak++;
      sum += peak;
      i++;
    }

    // decreasing slope
    int down = 1;
    while (i < size && rating[i] < rating[i - 1]) {
      sum += down;
      down++;
      i++;
    }
    if (down > peak) {
      sum += down - peak;
    }
  }
  return sum;
}

int main() {
  cout << "10 L12 Candy" << endl;

  //   There are n children standing in a line. Each child is assigned a rating
  //   value given in the integer array ratings.

  // You are giving candies to these children subjected to the following
  // requirements:

  // Each child must have at least one candy.
  // Children with a higher rating get more candies than their neighbors.
  // Return the minimum number of candies you need to have to distribute the
  // candies to the children.
  // Refer 10_L12_Candy_1
  vector<int> rating = {1, 2, 3};
  int res = candyBrute(rating);
  cout << res << endl;

  return 0;
}
