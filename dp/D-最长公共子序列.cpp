#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn =1e3+10;
int lcs(int x[],int y[],int n){
    int c[maxn][maxn];
    for(int i=0;i<n;i++){
        c[i][0] = 0;
        c[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i]==y[j]) c[i][j] = c[i-1][j-1]+1;
            else c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    }
    return c[n][n];
}
int main(){
    int n;
    int a[maxn];
    int b[maxn];
    int z[maxn];
    int c[maxn];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i+1);
    for(int i=0;i<n;i++) scanf("%d",b+i+1);
    printf("%d\n",lcs(a,b,n));
    return 0;
}


/* 
//2M,int数组大小256K,256e3,1000*256,所以开二维数组是不行的
#include <bits/stdc++.h>
using namespace std;

char a[1010],b[1010];
int dp[2][1010];
int lcs(int aLen,int bLen){
    int res = 0;
    memset(dp,0,sizeof dp);
    for(int i=1;i<=aLen;i++){
        for(int j=1;j<=bLen;j++){
            int curRow = i%2;
            int preRow = (i+1)%2;
            if(a[i-1]==b[j-1]) dp[curRow][j] = dp[preRow][j-1]+1;
            else dp[curRow][j] = max(dp[preRow][j],dp[curRow][j-1]);
            res = max(res,dp[curRow][j]);
        }
    }
    return res;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    scanf("%s%s",a,b);
    int aLen = strlen(a);
    int bLen = strlen(b); 
    int res = max(aLen,bLen);
    printf("%d\n",lcs(x,y));
    return 0;
} */