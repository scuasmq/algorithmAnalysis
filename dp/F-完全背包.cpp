#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 52;
const int maxm = 50020;
int c[maxn][maxm];
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,W;
        scanf("%d%d",&N,&W);
        W*=100;
        int w[maxn], v[maxn];
        double t;
        fill(c[0],c[0]+maxn*maxm,0);
        for(int i=1;i<=N;i++) scanf("%d",&v[i]);
        for(int i=1;i<=N;i++) {scanf("%lf",&t);w[i] =((long long)(t*1000))/10;}
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(j-w[i]>=0)c[i][j] = max(c[i-1][j],c[i][j-w[i]]+v[i]);
                else c[i][j] = c[i-1][j];
            }
        }
        int res = 0;
        for(int i=1;i<=N;i++) res = max(res,c[i][W]);
        printf("%d\n",res);
    }

    return 0;
}