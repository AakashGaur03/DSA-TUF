#include <bits/stdc++.h>
using namespace std;

int assignCookie(vector<int> greed, vector<int> s) {
  // TC O(N + NlogN + MlogM)
  // SC O(1)
  // we will be greedy means try to give each child minimum number of value
  // so to keep higher size for more greed

  // We will sort both the arrays
  int sSize = s.size();
  int greedSize = greed.size();
  int left = 0;
  int right = 0;
  int cookieAssigned = 0;
  sort(greed.begin(), greed.end());
  sort(s.begin(), s.end());

  while (left < sSize && right < greedSize) {
    if (greed[right] <= s[left]) {
      cookieAssigned++;
      right++;
    }
    left++;
  }

  return cookieAssigned;
  return right;
  // we can simply return right too without need of cookieAssigned
  // as right = number of satisfied children
}

int main() {
  cout << "1 L1 Assign Cookies" << endl;
  // Greedy Algorithm

  //   Assume you are an awesome parent and want to give your children some
  //   cookies. But, you should give each child at most one cookie.

  // Each child i has a greed factor g[i], which is the minimum size of a cookie
  // that the child will be content with; and each cookie j has a size s[j]. If
  // s[j] >= g[i], we can assign the cookie j to the child i, and the child i
  // will be content. Your goal is to maximize the number of your content
  // children and output the maximum number.

  // greed has N childrens and each number represent greed of that children
  // s is the cookies with there size that a parent have
  // so to satisfy a child with greed i parent should him cookie with size
  // greater or equal to i
  // One cookie can only be give to one children
  vector<int> greed = {1, 5, 3, 3, 4};
  vector<int> s = {4, 2, 1, 2, 1, 3};

  int res = assignCookie(greed, s);
  cout << res << endl;

  return 0;
}
