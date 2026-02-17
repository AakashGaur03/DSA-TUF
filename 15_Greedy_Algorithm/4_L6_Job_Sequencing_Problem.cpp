#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
  return a[2] > b[2]; // Sort by profit descending
  // If values are correct a[2] > b[2] then OK otherwise SWAP
}

pair<int, int> jobSequencingProblem(vector<vector<int>> jobs) {
  // TC O(N log N * (N*maxDeadline))
  // SC O(maxDeadline)
  // Delay the Job to the end Days
  // Perfrom Max profit Job for the day

  // Sort acc to Profit
  // We will create an hashArray with -1 values
  // Then put values in hashArray if values is -1
  // otherwise we will put that in day that is available before that
  // Refer 4_L6_Job_Sequencing_Problem_2

  sort(jobs.begin(), jobs.end(), comp); // N log N
  int cnt = 0;
  int totalProfit = 0;
  int maxDeadline = -1;
  int size = jobs.size();
  for (int i = 0; i < size; i++) { // N
    maxDeadline = max(maxDeadline, jobs[i][1]);
  }
  vector<int> arrhash(maxDeadline + 1, -1);

  for (int i = 0; i < size; i++) { // maxDeadline
    for (int j = jobs[i][1]; j > 0; j--) {
      if (arrhash[j] == -1) {
        arrhash[j] = jobs[i][0];
        cnt++;
        totalProfit += jobs[i][2];
        break;
      }
    }
  }
  return {cnt, totalProfit};
}
int main() {
  cout << "4 L6 Job Sequencing Problem" << endl;
  // Every Job will have its job_id its deadline and its profit
  // Every Job requires 1 day
  // Deadline means that the job can be done upto that day
  // Maximise the profit
  // Refer the 4_L6_Job_Sequencing_Problem_1
  vector<vector<int>> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
  pair<int, int> res = jobSequencingProblem(jobs);
  cout << res.first << endl;
  cout << res.second << endl;
  return 0;
}

// REVISITED