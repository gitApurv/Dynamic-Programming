// Problem: Unique Paths II
// Approach: Recursion
int f(int i, int j, vector<vector<int>> &obstacleGrid)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    return f(i, j - 1, obstacleGrid) + f(i - 1, j, obstacleGrid);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid.back().size();
    return f(n - 1, m - 1, obstacleGrid);
}
// Time Complexity: O(2^(n+m)) where n is the number of rows and m is the number of columns in the grid.
// Space Complexity: O(n+m) for the recursion stack