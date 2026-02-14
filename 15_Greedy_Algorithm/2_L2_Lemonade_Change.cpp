#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> bills) {
  // TC: O(N)
  // SC: O(1)

  int bills5 = 0;
  int bills10 = 0;
  int size = bills.size();
  for (int i = 0; i < size; i++) {
    if (bills[i] == 5) {
      bills5++;
    } else if (bills[i] == 10) {
      if (bills5) {
        bills5--;
      } else {
        return false;
      }
      bills10++;
    } else {
      if (bills5 && bills10) {
        bills5--;
        bills10--;
      } else if (bills5 >= 3) {
        bills5 -= 3;
      } else {
        return false;
      }
    }
  }

  return true;
}
int main() {
  cout << "2 L2 Lemonade Change" << endl;

  vector<int> bills = {5, 5, 5, 10, 20};
  // We have a lemonade stand and every lemonade will cost us 5$
  // In market 5$ 10$ and 20$
  // WE have N customers and we have 0 money
  // Will be able to sell Lemonade to N customers
  bool res = lemonadeChange(bills);
  cout << res << endl;

  return 0;
}
