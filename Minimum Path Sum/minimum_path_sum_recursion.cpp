// Minimium Path Sum
// Approach: Recursion
int f(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0)
        return INT_MAX;

    if (i == 0 && j == 0)
        return grid[i][j];

    return grid[i][j] + min(f(i - 1, j, grid), f(i, j - 1, grid));
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.back().size();
    return f(n - 1, m - 1, grid);
}
// Time Complexity: O(2^(n+m)), where n is the number of rows and m is the number of columns in the grid. This is because we are exploring all possible paths from the top-left to the bottom-right corner of the grid, which can be represented as a binary tree with 2^(n+m) nodes.
// Space Complexity: O(n+m), where n is the number of rows and m is the number of columns in the grid. This is because we are using a recursive function that can go as deep as n+m levels in the call stack, which requires O(n+m) space for the function call stack.