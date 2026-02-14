#include <bits/stdc++.h>
using namespace std;

int shortestJobFirst(vector<int> processes) {
  // TC O(N)+( NlogN)
  // SC O(1)
  int timeout = 0;
  int waitingTime = 0;
  // We need to start from smallest
  sort(processes.begin(), processes.end());
  int size = processes.size();

  for (int i = 0; i < size; i++) {
    waitingTime += timeout;
    timeout += processes[i];
  }
  return waitingTime / size;
}

int main() {
  cout << "2 L3 Shortest Job First" << endl;

  vector<int> processes = {4, 3, 7, 1, 2};
  // we need to compute average waiting time for all the process following
  // shortest job first Algo

  // Shortest Job First Algo: Scheduling policy that selects the waiting process
  // with the smallest execution time to execute first

  // We will be finding average waiting time as in 2_L3_Shortest_Job_First_1 and
  // then averageing it
  int res = shortestJobFirst(processes);
  cout << res << endl;

  return 0;
}
