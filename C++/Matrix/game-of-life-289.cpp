// In Place Solution with Matrix Manipulation - [Leetcode 289](https://leetcode.com/problems/game-of-life/)

using namespace std;

#include <vector>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // In-place solution using values -1 and 2
        // -1: cell was 1 (live) and is now 0 (dead)
        // 2: cell was 0 (dead) and is now 1 (live)

        vector<int> neighbors = {0, 1, -1};
        int ROWS = board.size();
        int COLS = board[0].size();

        // Iterate through every cell on the board
        for (int ro = 0; ro < ROWS; ro++) {
            for (int co = 0; co < COLS; co++) {
                int liveNeighbors = 0;

                // Count live neighbors
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = ro + neighbors[i];
                            int c = co + neighbors[j];

                            // Check if the neighboring cell is valid and was originally live (1 or -1)
                            if ((r >= 0 && r < ROWS) && (c >= 0 && c < COLS) && abs(board[r][c]) == 1) {
                                liveNeighbors++;
                            }
                        }
                    }
                }

                // Apply Game of Life rules:
                // Rule 1 or 3: Any live cell with fewer than 2 or more than 3 live neighbors dies.
                if (board[ro][co] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[ro][co] = -1;
                }

                // Rule 4: Any dead cell with exactly 3 live neighbors becomes a live cell.
                if (board[ro][co] == 0 && liveNeighbors == 3) {
                    board[ro][co] = 2;
                }
            }
        }

        // Update the board to final state
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
