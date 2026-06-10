#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, size;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i; // In Parent Initally everything is set as themselves
      size[i] = 1;   // In Size Initally everything is set as 1
    }
  }

  int findUPar(int node) { // Ultimate Parent
    if (node == parent[node]) {
      return node;
    }

    // return findUPar(parent[node]); // Normal Recursion

    return parent[node] = findUPar(parent[node]); // Path Compression
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      // Already belong to same component
      return;
    }

    if (size[ulp_u] < size[ulp_v]) {
      // Means u gets attached to v as v is greater
      parent[ulp_u] = ulp_v;
      // when we attach to v so size of V will be increased by U
      size[ulp_v] += size[ulp_u];
    } else {
      // rank[ulp_v] == rank[ulp_u] || rank[ulp_v] < rank[ulp_u]
      // We can attach v to u in both cases
      parent[ulp_v] = ulp_u;
      // when we attach to U so size of U will be increased by V
      size[ulp_u] += size[ulp_v];
    }
  }
};

vector<vector<string>> mergeDetails(vector<vector<string>> &details) {

  int n = details.size();
  unordered_map<string, int> mapMailNode;
  DisjointSet ds(n);
  // Step 1 First Map the Mails to the Node
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < details[i].size(); j++) {
      // j = 1 because j = 0 is name
      string mail = details[i][j];
      if (mapMailNode.find(mail) == mapMailNode.end()) {
        // means doesnt exist
        mapMailNode[mail] = i;
      } else {
        ds.unionBySize(i, mapMailNode[mail]);
      }
    }
  }

  // Step 2
  // Merge the Mails acc to List Ultimate Parents

  vector<vector<string>> mergedMail(n);
  for (auto it : mapMailNode) {
    string mail = it.first;
    int node = ds.findUPar(
        it.second); // This will give us Ultimate Parent of Mapped Node
    mergedMail[node].push_back(mail);
  }

  // Step 3 get the correct Answer as in Step 2 there can be Empty Indexes too
  // also we need to sort the mails
  vector<vector<string>> ans;

  for (int i = 0; i < n; i++) {
    if (mergedMail[i].size() == 0) {
      continue;
    }
    sort(mergedMail[i].begin(), mergedMail[i].end());
    vector<string> temp;
    temp.push_back(details[i][0]); // Names

    for (auto it : mergedMail[i]) {
      temp.push_back(it); // Already sorted Mails
    }
    ans.push_back(temp);
  }

  return ans;
}

int main() {

  cout << "47 G 50 Accounts Merge DSU" << endl;

  //   Merging Details
  // Bob, a teacher of St. Joseph School given a task by his principal to merge
  // the details of the students where each element details[i] is a list of
  // strings, where the first element details[i][0] is a name of the student,
  // and the rest of the elements are emails representing emails of the student.
  // Two details definitely belong to the same student if there is some common
  // email to both detail.  After merging the details, return the details of the
  // student in the following format: the first element of each detail is the
  // name of the student, and the rest of the elements are emails in sorted
  // order. Note: Two details have the same name, they may belong to different
  // people as people could have the same name. A person can have any number of
  // details initially, but all of their details definitely have the same name.
  // In case 2 or more same email belongs to 2 or more different names merge
  // with first name only. Return the 2D list in the order in a sorted way
  // according to the name of the details.

  vector<vector<string>> details = {
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"Mary", "mary@mail.com"},
      {"John", "johnnybravo@mail.com"}};

  vector<vector<string>> ans = mergeDetails(details);

  for (auto &account : ans) {
    for (auto &str : account) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}