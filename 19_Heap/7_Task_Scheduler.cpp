#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n) {
  // TC: O(N)
  // Building the frequency array takes O(N).
  // The priority queue has at most 26 elements, so each push/pop is O(log 26) =
  // O(1).

  // SC: O(26) = O(1)
  vector<int> mpp(26, 0);

  for (char ch : tasks) {
    mpp[ch - 'A']++;
  }

  int time = 0;

  priority_queue<int> pq;
  for (int i = 0; i < 26; i++) {
    if (mpp[i] > 0) {
      pq.push(mpp[i]);
    }
  }

  while (!pq.empty()) {
    vector<int> temp;
    for (int i = 0; i < n + 1; i++) {
      if (!pq.empty()) {
        int freq = pq.top();
        pq.pop();
        freq--;
        temp.push_back(freq);
      }
    }

    for (int eachFreq : temp) {
      if (eachFreq > 0) {
        pq.push(eachFreq);
      }
    }

    if (pq.empty()) {
      time += temp.size();
    } else {
      time += n + 1;
    }
  }

  return time;
}

int main() {
  cout << "7 Task Scheduler" << endl;

  // Task Scheduler

  // You are given an array of CPU tasks, each labeled with a letter from A
  // to Z, and a number n. Each CPU interval can be idle or allow the
  // completion of one task. Tasks can be completed in any order, but
  // there's a constraint: there has to be a gap of at least n intervals
  // between two tasks with the same label.

  // Return the minimum number of CPU intervals required to complete all
  // tasks.

  // tasks = ["A","A","A","B","B","B"], n = 2

  // Output: 8

  // Explanation:
  // A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

  // Intution
  // Greedy
  // We can take Frequency and acc to that First start filling the Max Frequency
  // one then acc to gaps fill rest one by one
  // Or Put one by one acc to Frequency and Gaps and reduce the frequency

  // We will create a PQ acc to frequency so that remains always sorted so we
  // know which one we need to put in our answer accordingly

  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;

  cout << "Tasks: ";
  for (char ch : tasks) {
    cout << ch << " ";
  }
  cout << endl;

  cout << "Cooldown (n): " << n << endl;

  int ans = leastInterval(tasks, n);

  cout << "Minimum CPU intervals required: " << ans << endl;
  return 0;
}
