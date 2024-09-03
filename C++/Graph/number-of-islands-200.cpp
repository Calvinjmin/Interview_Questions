/*
    LeetCode Question 200
    Number of Islands
*/


#include <vector>

using namespace std;

void removeIsland(vector<vector<char>> &grid, int x, int y) {
  if (x >= grid.size() or x < 0 or y < 0 or y >= grid[0].size() or
      grid[x][y] != '1') {
    return;
  }
  // directions
  grid[x][y] = '0';
  removeIsland(grid, x + 1, y);
  removeIsland(grid, x - 1, y);
  removeIsland(grid, x, y + 1);
  removeIsland(grid, x, y - 1);
}
int numIslands(vector<vector<char>> &grid) {
  int ROW = grid.size();
  int COL = grid[0].size();
  int ans = 0;

  // Loop through the grid and find a 1
  // Send all directions to removeIsland
  //  to change the reference of touching 1's to 0's

  for (int x = 0; x < ROW; x++) {
    for (int y = 0; y < COL; y++) {
      if (grid[x][y] == '1') {
        removeIsland(grid, x, y);
        ans += 1;
      }
    }
  }

  return ans;
}