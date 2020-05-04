#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e4+10;
typedef long long ll;
int change[13] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[maxn];
//dp[i][j]前i张票 j金额
void DP(int n){
    dp[0] = 1;
    for(int i=0;i<13;i++){
        for(int j=change[i];j<=n;j++)
            dp[j] = (dp[j]+dp[j-change[i]])%mod;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    DP(n);
    printf("%lld\n",(dp[n]%mod+mod)%mod);
    return 0;
}