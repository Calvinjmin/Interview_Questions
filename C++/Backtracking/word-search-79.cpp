// DFS Backtracking on a Grid - [Leetcode 79](https://leetcode.com/problems/word-search/description/)

using namespace std;

#include <vector>

class Solution {
private:
    vector<vector<char>> board;
    int ROWS;
    int COLS;
public:
    bool backtrack( int r, int c, int index, string word ) {

        if ( index >= word.size() ) {
            return true;
        }

        if ( r < 0 ||  r == ROWS || c < 0 || c == COLS || board[r][c] != word[index]) {
            return false;
        }

        vector<int> xDir = {0,0,1,-1};
        vector<int> yDir = {1,-1,0,0};

        // try all directions
        // backtrack
        board[r][c] = '#';    
        for ( int i = 0; i < 4; i++ ) {
            if ( backtrack(r + xDir[i], c + yDir[i], index + 1, word ) ) {
                return true;
            }
        }
        board[r][c] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        ROWS = board.size();
        COLS = board[0].size();
        for ( int i = 0; i < ROWS; i++  ) {
            for ( int j = 0; j < COLS; j++ ) {
                if (backtrack(i,j,0,word)) {
                    return true;
                }
            }
        }
        return false;
        
    }
};