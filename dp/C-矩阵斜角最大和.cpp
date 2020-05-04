#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int mat[maxn][maxn];
long long dp[maxn][maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&mat[i][j]);
    for(int i=1;i<=m;i++) dp[1][i] = dp[1][i-1]+mat[1][i];
    for(int i=1;i<=n;i++) dp[i][1] = dp[i-1][1]+mat[i][1];
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j])+mat[i][j];
        }
    }
    
    printf("%lld\n",dp[n][m]);
    return 0;
}