#include <bits/stdc++.h>
using namespace std;
//由于max(n)==200,所以不可能是dfs搜索,肯定是通过dp来算

const int maxn = 210;
const int maxm = 110;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    double p[210];
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    double dp[maxn][maxm];//前i个种子,j个发芽的概率
    fill(dp[0],dp[0]+maxn*maxm,0);
    for(int j=1;j<=k;j++) dp[0][k]=0;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) dp[i][0] = dp[i-1][0]*(1-p[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }
    // printf("%lf\n",dp[1][1]);
    printf("%.4lf\n",dp[n][k]);
    return 0;
}

/* 
3 2
0.5 0.25 0.75 
0.4062
*/