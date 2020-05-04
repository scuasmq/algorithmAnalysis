#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;
int main(){
    int a[maxn],n;
    int dp=0,res=-INF;
    scanf("%d",&n);
    fill(a,a+n,0);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp = max(dp+a[i],a[i]);
        res = max(res,dp);
    }
    printf("%d\n",res);
    return 0;
}