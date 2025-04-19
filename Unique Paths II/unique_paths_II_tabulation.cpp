// Problem: Unique Paths II
// Approach: Tabulation

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid.back().size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the obstacleGrid
// Space Complexity: O(n*m)