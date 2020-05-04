//2M,int数组大小256K,256e3,1000*256,所以开二维数组是不行的
#include <bits/stdc++.h>
using namespace std;

char a[1010],b[1010];
int dp[2][1010];
const int INF = 0x3f3f3f3f;
int lcs(int aLen,int bLen){
    int res = 0;
    memset(dp,INF,sizeof dp);
    dp[0][0] = 0;
    for(int j=1;j<=bLen;j++) dp[0][j] = j;
    for(int i=1;i<=aLen;i++){
        for(int j=1;j<=bLen;j++){
            int curRow = i%2;
            int preRow = (i+1)%2;
            //dp[i-1][j-1]+01修改当前的 or dp[i-1][j]+1删除a最后一个 or dp[i][j-1]删除b最后一个
            if(j-1!=0)
                dp[curRow][j] = min(dp[preRow][j-1]+(a[i-1]!=b[j-1]),min(dp[preRow][j]+1,dp[curRow][j-1]+1));
            else
                dp[curRow][j] = min(i-1+(a[i-1]!=b[j-1]),min(dp[preRow][j]+1,i+1));
        }
    }
    return dp[aLen%2][bLen];
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a,b);
        int aLen = strlen(a);
        int bLen = strlen(b); 
        int res = max(aLen,bLen);
        printf("%d\n",lcs(aLen,bLen));
    }
    return 0;
}