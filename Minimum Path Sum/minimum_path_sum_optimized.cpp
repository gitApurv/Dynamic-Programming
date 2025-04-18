// Minimum Path Sum
// Approach: Space Optimized Tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.back().size();
    vector<int> prev(m, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, INT_MAX);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 0;

            if (i > 0)
                curr[j] = min(curr[j], prev[j]);

            if (j > 0)
                curr[j] = min(curr[j], curr[j - 1]);

            curr[j] += grid[i][j];
        }
        prev = curr;
    }
    return prev[m - 1];
}
// Time Complexity: O(n * m)
// Space Complexity: O(m) where m is the number of columns in the grid
