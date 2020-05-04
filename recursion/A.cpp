#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

void findDep(int son[][2], int root, int dep, int n, int &maxdep)
{
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++)
            if (son[root][j] == i)
                findDep(son, i, dep + 1, n, maxdep);
            else
                maxdep = max(maxdep, dep);
}

int main()
{
    int n;
    int son[25][2];
    memset(son, 0, sizeof son);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!son[x][0])
            son[x][0] = y;
        else
            son[x][1] = y;
    }
    int maxdep = 0;
    findDep(son, 1, 1, n, maxdep);
    printf("%d\n", maxdep);
    return 0;
}