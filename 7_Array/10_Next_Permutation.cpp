#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all permutations of the array
void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
  // Base case: if we have placed all elements
  if (index == nums.size()) {
    ans.push_back(nums); // store current permutation
    return;
  }

  // Try placing each unused element at current position
  for (int i = index; i < nums.size(); i++) {
    swap(nums[index], nums[i]);         // swap current index with i
    recurPermute(index + 1, nums, ans); // recurse for the next index
    swap(nums[index], nums[i]);         // backtrack to restore original state
  }
}

// Wrapper function to initiate permutation generation
vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> ans;
  recurPermute(0, nums, ans);
  return ans;
}

// Function to find and return next permutation
vector<int> bruteNextPermutation(vector<int> &nums) {
  vector<vector<int>> allPermutations;

  // Step 1: Generate all permutations
  recurPermute(0, nums, allPermutations);

  // Step 2: Sort all permutations lexicographically
  sort(allPermutations.begin(), allPermutations.end());

  // Step 3: Find current permutation
  for (int i = 0; i < allPermutations.size(); i++) {
    if (allPermutations[i] == nums) {
      // Step 4: Return the next permutation if exists
      if (i + 1 < allPermutations.size()) {
        return allPermutations[i + 1];
      } else {
        // If current is the last permutation, return the first (wrap around)
        return allPermutations[0];
      }
    }
  }

  // Just in case not found (shouldn't happen)
  return nums;
}

int main() {
  vector<int> arr = {3, 1, 2};
  // 1) Generate All Permutation Sorted Order
  // 2) Linear Search the current permution
  // 3) Return next permutation

  // TO DO Watch Recusrion Playlist LEC 12 13
  // O(N! N)
  vector<int> nextPerm = bruteNextPermutation(arr);

  cout << "Next Permutation: ";
  for (int num : nextPerm) {
    cout << num << " ";
  }
  cout << endl;

  // better Solution
  next_permutation(arr.begin(), arr.end());
  return 0;
}

/*
Dry Run for recurPermute() — Generate All Permutations Using Backtracking

Let’s say input: nums = {1, 2, 3}
Call: recurPermute(0, nums, ans)

-----------------------------
Initial: index = 0
→ Swap nums[0] with nums[0] → {1,2,3}
   → recurPermute(1, nums)
     → Swap nums[1] with nums[1] → {1,2,3}
        → recurPermute(2, nums)
           → Swap nums[2] with nums[2] → {1,2,3}
              → index == 3 → store [1,2,3]
           ← backtrack (swap back)
     ← backtrack
     → Swap nums[1] with nums[2] → {1,3,2}
        → recurPermute(2, nums)
           → Swap nums[2] with nums[2] → {1,3,2}
              → index == 3 → store [1,3,2]
           ← backtrack
     ← backtrack
← backtrack

→ Swap nums[0] with nums[1] → {2,1,3}
   → recurPermute(1, nums)
     → Swap nums[1] with nums[1] → {2,1,3}
        → recurPermute(2, nums)
           → index == 3 → store [2,1,3]
     ← backtrack
     → Swap nums[1] with nums[2] → {2,3,1}
        → recurPermute(2, nums)
           → index == 3 → store [2,3,1]
     ← backtrack
← backtrack

→ Swap nums[0] with nums[2] → {3,2,1}
   → recurPermute(1, nums)
     → Swap nums[1] with nums[1] → {3,2,1}
        → recurPermute(2, nums)
           → index == 3 → store [3,2,1]
     ← backtrack
     → Swap nums[1] with nums[2] → {3,1,2}
        → recurPermute(2, nums)
           → index == 3 → store [3,1,2]
     ← backtrack
← backtrack

Final ans:
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 2, 1]
[3, 1, 2]

Time Complexity: O(N! × N)
- N! permutations
- Each permutation copied takes O(N)
*/
