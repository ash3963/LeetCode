#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void eraseIsland(vector<vector<char>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';
    eraseIsland(grid, i-1, j);
    eraseIsland(grid, i+1, j);
    eraseIsland(grid, i, j-1);
    eraseIsland(grid, i, j+1);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                islands++;
                eraseIsland(grid, i, j);
            }
        }
    }
    return islands;
}