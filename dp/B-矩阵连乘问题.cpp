#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e2+10;
const int INF = 0x3f3f3f3f;
void getMinMatrix(int dp[][maxn],int a[],int l,int r){
    if(l==r||dp[l][r]!=INF) return;
    if(l+1==r){
        dp[l][r] = a[l]*a[r]*a[r+1];
        return ;
    }
    for(int i=l;i<=r-1;i++){
        getMinMatrix(dp,a,l,i);
        getMinMatrix(dp,a,i+1,r);
        dp[l][r] = min(dp[l][r],dp[l][i]+dp[i+1][r]+a[l]*a[i+1]*a[r+1]);
    }
}

int main(){
    int n;
    int a[maxn];
    int dp[maxn][maxn];
    fill(dp[0],dp[0]+maxn*maxn,INF);
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++){
        scanf("%d",&a[i]);
        dp[i][i] = 0;
    }
    getMinMatrix(dp,a,1,n);
    printf("%d\n",dp[1][n]);
    return 0;
}