#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& grid, int i, int j) {

    if (i >= grid.size() || j >= grid[0].size()) {
        return 0;
    }

    int right = solve(grid, i, j + 1);
    int diagonal = solve(grid, i + 1, j + 1);
    int down = solve(grid, i + 1, j);

    if (grid[i][j] == 1) {
        return 1 + min(right, min(diagonal, down));
    }

    return 0;
}

int countSquares(vector<vector<int>>& grid) {

    int total = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            total += solve(grid, i, j);
        }
    }

    return total;
}

int main() {

    vector<vector<int>> grid = {
        {1, 1},
        {1, 1}
    };

    cout << countSquares(grid);

    return 0;
}