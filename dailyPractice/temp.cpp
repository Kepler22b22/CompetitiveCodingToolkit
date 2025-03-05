#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int dir) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '.')
            return;
        
        board[i][j] = '.';  // Mark as visited

        // If moving vertically
        if (dir == 1) {
             dfs(board, i + 1, j, 1); // Move down
        }
        // If moving horizontally
        else {
             dfs(board, i, j + 1, 0); // Move right
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') {
                    count++;  // Found a new ship
                    if (i + 1 < m && board[i + 1][j] == 'X') dfs(board, i, j, 1); // Explore downwards
                    else if (j + 1 < n && board[i][j + 1] == 'X') dfs(board, i, j, 0); // Explore rightwards
                    else board[i][j] = '.'; // Single-cell battleship, mark visited
                }
            }
        }
        return count;
    }
};

// Example usage
int main() {
    vector<vector<char>> board = {
        {'X', 'X', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'X', '.', 'X', 'X'}
    };

    Solution sol;
    cout << "Number of battleships: " << sol.countBattleships(board) << endl;
    return 0;
}
