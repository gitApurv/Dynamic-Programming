int f(int m, int n)
{
    if (m == 0 && n == 0)
        return 1;

    if (m == 0)
        return f(m, n - 1);

    else if (n == 0)
        return f(m - 1, n);

    return f(m, n - 1) + f(m - 1, n);
}

int uniquePaths(int m, int n)
{
    return f(m - 1, n - 1);
}