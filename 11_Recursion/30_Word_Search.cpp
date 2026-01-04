// SUBMITTED ON LEETCODE
// // Word Search
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an m x n grid of characters board and a string word, return true if
// // word exists in the grid.

// // The word can be constructed from letters of sequentially adjacent cells,
// // where adjacent cells are horizontally or vertically neighboring. The same
// // letter cell may not be used more than once.

// // Example 1:

// // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
// word
// // = "ABCCED" Output: true Example 2:

// // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
// word
// // = "SEE" Output: true Example 3:

// // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
// word
// // = "ABCB" Output: false

// // Constraints:

// // m == board.length
// // n = board[i].length
// // 1 <= m, n <= 6
// // 1 <= word.length <= 15
// // board and word consists of only lowercase and uppercase English letters.

// class Solution {
// public:
//     vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     bool find(vector<vector<char>>& board, int i, int j, int m, int n, int
//     idx,
//               string& word) {

//         if (idx == word.size()) {
//             return true;
//         }
//         if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
//             // If Overflow Underflow or Already Visited
//             return false;
//         }
//         if (board[i][j] != word[idx]) {
//             return false;
//         }
//         // Store Temp so that When backtracking we can reapply same value
//         char temp = board[i][j];
//         board[i][j] = '$';

//         // Backtracking
//         // We use &dir (reference) to avoid unnecessary copying of each
//         // direction vector.
//         for (auto& dir : directions) {
//             int new_i = i + dir[0];
//             int new_j = j + dir[1];

//             if (find(board, new_i, new_j, m, n, idx + 1, word)) {
//                 return true;
//             }
//         }
//         // Backtracking
//         board[i][j] = temp;

//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();
//         int n = board[0].size();

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // Visit Each Character
//                 // If First Character matches then perform backtracking to
//                 check
//                 // others
//                 if (board[i][j] == word[0] &&
//                     find(board, i, j, m, n, 0, word)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// EXIST FUNCTION WITH EARLY PRUNING

// bool exist(vector<vector<char>> &board, string word) {
//   int m = board.size();
//   int n = board[0].size();

//   // PRUNING THE BACKTRACKING BY CHECKING THE COUNTS
//   // If the board doesn’t contain enough characters required by word,
//   // don’t even start DFS.

//   unordered_map<char, int> boardCnt;
//   unordered_map<char, int> wordCnt;

//   // Counts Each Word Frequency in Board
//   for (auto &row : board) {
//     for (char c : row) {
//       boardCnt[c]++;
//     }
//   }
//   // Counts Each Word Frequency in Word
//   for (char c : word) {
//     wordCnt[c]++;
//   }

//   for (auto &[c, cnt] : wordCnt) {
//     if (boardCnt[c] < cnt) {
//       return false;
//     }
//   }

//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       // Visit Each Character
//       // If First Character matches then perform backtracking to check
//       // others
//       if (board[i][j] == word[0] && find(board, i, j, m, n, 0, word)) {
//         return true;
//       }
//     }
//   }
//   return false;
// }
