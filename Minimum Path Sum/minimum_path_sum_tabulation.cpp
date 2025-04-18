// Minimum Path Sum
// Approach: Tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.back().size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;

            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);

            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);

            dp[i][j] += grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)