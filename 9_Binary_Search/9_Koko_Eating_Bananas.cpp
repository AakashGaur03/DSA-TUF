#include <bits/stdc++.h>
using namespace std;

int functionHourly(vector<int> piles, int eatBanana) {
  int totalHoursToEat = 0;
  for (int i = 0; i < piles.size(); i++) {
    // totalHoursToEat += ceil((double)piles[i] / eatBanana);
    totalHoursToEat += (piles[i] + eatBanana - 1) / eatBanana;
  }
  return totalHoursToEat;
}

int bruteKokoEatBanana(vector<int> piles, int hours) {
  // TC O(size of piles + (maxElem in piles  * size of piles))
  int size = piles.size();
  int maxElem = -1;
  for (int i = 0; i < size; i++) {
    maxElem = max(piles[i], maxElem);
  }

  for (int i = 1; i <= maxElem; i++) {
    int totalHours = functionHourly(piles, i);
    if (totalHours <= hours) {
      return i;
    }
  }

  return -1;
}

int optimalKokoEatBanana(vector<int> piles, int hours) {
  // TC O(size of piles + (log base 2 of maxElem of piles  * size of piles))
  int low = 1;
  int size = piles.size();
  int maxElem = -1;
  int ans = INT_MAX;
  for (int i = 0; i < size; i++) {
    maxElem = max(piles[i], maxElem);
  }

  int high = maxElem;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int totalHours = functionHourly(piles, mid);
    if (totalHours <= hours) {
      ans = min(mid, ans);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;

  // We can also return low as we can see that low and high starts at
  // opposite polarity that is at low it is not possible at high it is possible
  // so when starting low and high with opposite polarity we can see that if
  // answer exist then either high or low will be our answer in the end.

  //   In binary search, if we start with low = 1 (impossible) and
  //  high = maxElem (always possible), then after the loop ends:

  // low will be the smallest feasible speed
  // high will be the largest infeasible speed

  // So we can safely return low instead of tracking ans.
}
int main() {
  cout << "9 Koko Eating Bananas" << endl;
  // There will be N piles with number of bananas
  //   piles = [ 3,6,7,11]
  // at max hours = 8
  // k = koko can eat k amount of bananas per hour
  // we need to find this k
  // we need to find minimum number of banana that koko eats per hour that is
  // within the max hour limit and finish all piles

  //   You are given an array piles[], where piles[i] represents the number of
  //   bananas in the i-th pile.
  // Example: piles = [3, 6, 7, 11]

  // Koko can eat at most k bananas per hour (this is what we need to find).

  // If a pile has fewer than k bananas, she just eats the whole pile and stops
  // for that hour.

  // If a pile has more than k bananas, she eats exactly k and the next hour she
  // continues.

  // You are also given a number h = maximum hours allowed.
  // Example: h = 8.

  // Goal: Find the minimum integer k such that Koko can finish all bananas
  // within h hours.

  //   Example Walkthrough

  // piles = [3, 6, 7, 11]
  // h = 8

  // Let’s test different values of k:

  // Case 1: k = 4

  // Pile 3 → needs 1 hour (because 3 <= 4)

  // Pile 6 → needs ceil(6/4) = 2 hours

  // Pile 7 → needs ceil(7/4) = 2 hours

  // Pile 11 → needs ceil(11/4) = 3 hours
  // Total = 1 + 2 + 2 + 3 = 8 hours (within limit)

  // So k = 4 works.

  // Case 2: k = 3

  // Pile 3 → 1 hour

  // Pile 6 → ceil(6/3) = 2 hours

  // Pile 7 → ceil(7/3) = 3 hours

  // Pile 11 → ceil(11/3) = 4 hours
  // Total = 10 hours (exceeds 8)

  // So k = 3 doesn’t work.

  vector<int> piles = {3, 6, 7, 11};
  int hours = 8;
  int resBrute = bruteKokoEatBanana(piles, hours);
  int resOptimal = optimalKokoEatBanana(piles, hours);

  cout << "Brute Force Result: " << resBrute << endl;
  cout << "Optimal Result: " << resOptimal << endl;
  return 0;
}