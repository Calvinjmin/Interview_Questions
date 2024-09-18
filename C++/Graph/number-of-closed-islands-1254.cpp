// BFS on 2D Matrix with a Twist - [Leetcode 1254](https://leetcode.com/problems/number-of-closed-islands/)

using namespace std;

#include <vector>
#include <queue>

class Solution {
public:
    // BFS and if you reach an edge return false
    bool bfs( int r, int c, int ROW, int COL, vector<vector<int>>&grid ) {
        grid[r][c] = 2;
        queue<pair<int, int>> q;
        q.push({r,c});

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        bool closed = true;
        while ( !q.empty() ) {
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for ( int i = 0; i < 4; i++ ) {
                int x = r + dirx[i];
                int y = c + diry[i];

                if ( x < 0 || x >= ROW || y < 0 || y >= COL ) {
                    closed = false;
                }
                else if ( grid[x][y] == 0 ) {
                    q.push({x,y});
                    grid[x][y] = 2;
                }
            }
        }
        return closed;


    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for ( int i = 0; i < rows; i++ ) {
            for ( int j = 0; j < cols; j++ ) {
                if ( grid[i][j] == 0 && bfs(i,j,rows,cols, grid) ) {
                    ans += 1;
                }
            }
        }

        return ans;
        
    }
};