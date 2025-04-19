int f(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0)
        return f(m, n - 1, dp);

    else if (n == 0)
        return f(m - 1, n, dp);

    return dp[m][n] = f(m, n - 1, dp) + f(m - 1, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}