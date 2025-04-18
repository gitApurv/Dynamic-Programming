// Problem: Unique Paths II
// Approach: Memoization
int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = f(i, j - 1, obstacleGrid, dp) + f(i - 1, j, obstacleGrid, dp);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid.back().size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, obstacleGrid, dp);
}
// Time Complexity: O(N * M) where N is the number of rows and M is the number of columns in the obstacleGrid
// Space Complexity: O(N * M) + O(N + M) for recursion stack space