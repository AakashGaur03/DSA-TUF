#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
  while (start <= end) {
    if (s[start++] != s[end--]) {
      return false;
    }
  }
  return true;
}

/*
  Backtracking function to generate all palindrome partitions.

  index = current starting position in string
  s = input string
  path = current list of chosen substrings (palindromes)
  res = final answer (list of all valid palindrome partitions)
*/

void solvePalindrome(int index, string s, vector<string> &path,
                     vector<vector<string>> &res) {

  if (index == s.size()) {
    res.push_back(path);
    return;
  }

  // Try every possible substring s[index...i]:
  // - If it's a palindrome, include it in the path
  // - Recurse for the remaining part of the string (i+1)
  // - Backtrack: remove the added substring

  for (int i = index; i < s.size(); i++) {
    if (isPalindrome(s, index, i)) {
      path.push_back(s.substr(index, i - index + 1));
      solvePalindrome(i + 1, s, path, res);
      path.pop_back();
    }
  }
}

int main() {
  cout << "20 L17 Palindrome Partitioning" << endl;
  string s = "aabb";
  vector<vector<string>> res;
  vector<string> path;
  solvePalindrome(0, s, path, res);

  for (auto &vec : res) {
    for (auto &str : vec) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}