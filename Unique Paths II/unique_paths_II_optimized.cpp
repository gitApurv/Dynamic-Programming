// Problem: Unique Paths II
// Approach: Space Optimized DP
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid.back().size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                curr[j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
                curr[j] = 1;

            if (i > 0)
                curr[j] += prev[j];
            if (j > 0)
                curr[j] += curr[j - 1];
        }
        prev = curr;
    }
    return prev[m - 1];
}
// Time Complexity: O(n * m)
// Space Complexity: O(m)