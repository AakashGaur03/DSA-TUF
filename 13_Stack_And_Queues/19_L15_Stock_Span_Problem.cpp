#include <bits/stdc++.h>
using namespace std;

class StockSpannerBrurte {
public:
  vector<int> arr;
  StockSpannerBrurte() {}

  int next(int price) {
    // TC O(Number of days till today)
    // SC O(Total Number of Next call till now)
    arr.push_back(price);
    int cnt = 1;
    for (int i = arr.size() - 2; i >= 0; i--) {
      if (arr[i] <= price) {
        cnt++;
      } else {
        break;
      }
    }
    return cnt;
  }
};

class StockSpanner {
public:
  stack<pair<int, int>> st;
  int index;
  // value and index
  StockSpanner() { index = -1; }

  int next(int price) {
    // TC O(2N)
    // SC O(N)
    // Basically we need Previous Greater Element
    // then we can simple do index of PGE - current Index
    index = index + 1;
    while (!st.empty() && st.top().first <= price) {
      st.pop();
    }
    int ans = index - (st.empty() ? -1 : st.top().second);
    st.push({price, index});
    return ans;
  }
};

int main() {
  cout << "19 L15 Stock Span Problem" << endl;

  // INPUT
  // ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
  // [[], [100], [80], [60], [70], [60], [75], [85]]

  // Output
  // [null, 1, 1, 1, 2, 1, 4, 6]

  // next will return maximum consecutive days that price is equal to or less
  // than current day's price
  // Always count today as 1
  // For concept Refer 19_L15_Stock_Span_Problem_1
  return 0;
}
