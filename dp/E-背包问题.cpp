/* #include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e3+10;
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,W;
        int w[maxn],v[maxn];
        int c[maxn][maxn];
        scanf("%d%d",&N,&W);
        for(int i=1;i<=N;i++) scanf("%d",&v[i]);
        for(int i=1;i<=N;i++) scanf("%d",&w[i]);
        fill(c[0],c[0]+maxn*maxn,0);
        //dp
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(w[i]<=j)c[i][j] = max(c[i-1][j-w[i]]+v[i],c[i-1][j]); 
                else c[i][j] = c[i-1][j];
            }
        }
        printf("%d\n",c[N][W]);
    }
    return 0;
}
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1000+10;
int main(){

        int N,W;
        int w[maxn],v[maxn];
        int c[maxn][maxn];
        int dp[maxn];
        scanf("%d%d",&N,&W);
        for(int i=1;i<=N;i++) scanf("%d%d",&w[i],&v[i]);
        fill(c[0],c[0]+maxn*maxn,0);
        memset(dp,0,sizeof dp);
        //dp
        for(int i=1;i<=N;i++){
            for(int j=W;j>=1;j--){
                if(w[i]<=j) dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
                continue;
            }
        }
        printf("%d\n",dp[W]);
    
    return 0;
}