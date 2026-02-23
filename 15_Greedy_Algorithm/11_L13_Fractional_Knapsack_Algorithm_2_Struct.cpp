#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value;
  int weight;
};

bool comp(Item &a, Item &b) {
  return (long long)a.value * b.weight > (long long)b.value * a.weight;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
  int n = val.size();

  vector<Item> items(n);

  for (int i = 0; i < n; i++) {
    items[i] = {val[i], wt[i]};
  }

  sort(items.begin(), items.end(), comp);

  double totalValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (items[i].weight <= capacity) {
      totalValue += items[i].value;
      capacity -= items[i].weight;
    } else {
      totalValue += ((double)items[i].value / items[i].weight) * capacity;
      break;
    }
  }

  return totalValue;
}

int main() {
  vector<int> val = {100, 60, 100, 200};
  vector<int> wt = {20, 10, 50, 50};
  int capacity = 90;

  cout << fractionalKnapsack(val, wt, capacity);
}