#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int dp[maxn],cnt[1010],v[1010],w[1010];
int newW[1010],newV[1010],newCnt;

void init(int n){
    newCnt = 0;
    for(int i=1;i<=n;i++){
        int base = 1;
        while (cnt[i]>0)
        {
            if(cnt[i]>=base*2){
                newW[++newCnt] = base*w[i];
                newV[newCnt] = base*v[i];
                cnt[i] -= base;
                base*=2;
            }
            else{
                int rem = cnt[i];
                newW[++newCnt] = rem*w[i];
                newV[newCnt] = rem*v[i];
                cnt[i] = 0;
            }
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,W;
        scanf("%d%d",&N,&W);
        for(int i=1;i<=N;i++) scanf("%d",&v[i]);
        for(int i=1;i<=N;i++) scanf("%d",&w[i]);
        for(int i=1;i<=N;i++) scanf("%d",&cnt[i]);
        init(N);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=newCnt;i++){
            for(int j=W;j>=newW[i];j--){
                dp[j] = max(dp[j-newW[i]]+newV[i],dp[j]);
            }
        }
        int res = 0;
        for(int i=1;i<=W;i++) res = max(res,dp[i]);
        printf("%d\n",res);
    }
    return 0;
}


//xty
/* 
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int N, V, t;
const int maxn = 1e5+10;
int magic[1010], summon[1010], cnt[1010], v[maxn], m[maxn], dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> N >> V;
        for (int i = 1; i <= N; i++) cin >> magic[i];
        for (int i = 1; i <= N; i++) cin >> summon[i];
        for (int i = 1; i <= N; i++) cin >> cnt[i];
        for (int i = 0; i <= N * 1000; i++) dp[i] = 0;
        // memset(dp,0,sizeof dp);

        //二进制分解
        int tot = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int k = 1; k <= cnt[i]; k = k<< 1)
            {
                v[tot] = k * summon[i];
                m[tot++] = k * magic[i];
                cnt[i] -= k;
            }
            if (cnt[i] > 0)
            {
                v[tot] = cnt[i] * summon[i];
                m[tot++] = cnt[i] * magic[i];
            }
        }


        for (int i = 1; i <= tot; i++)
        {
            for (int j = V; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + m[i]);
            }
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}
 */
