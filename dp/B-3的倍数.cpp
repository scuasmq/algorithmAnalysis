#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn =5;
int div3[3];
long long dp[maxn][3];
void getDiv3(int l,int r){
    int num = r-l+1;
    if(num<=3){//B题测试数据会被hack,不加这个判断也能过
        while (l<=r)
        {
            div3[l%3]++;
            l++;
        }
        return;
    }
    while (l%3!=0)
    {
        div3[l%3]++;
        num--;
        l++;
    }
    while (r%3!=2)
    {
        div3[r%3]++;
        num--;
        r--;
    }
    div3[0] += num/3;
    div3[1] += num/3;
    div3[2] += num/3;   
}
void DP(int n,int l,int r){
    getDiv3(l,r);
    dp[1][0] = div3[0];
    dp[1][1] = div3[1];
    dp[1][2] = div3[2];
    for(int i=2;i<=n;i++){
        int pre = (i+1)%2;
        int now = i%2;
        dp[now][0] = (dp[pre][0]*div3[0]%mod + dp[pre][1]*div3[2]%mod + dp[pre][2]*div3[1]%mod)%mod;
        dp[now][1] = (dp[pre][0]*div3[1]%mod + dp[pre][1]*div3[0]%mod + dp[pre][2]*div3[2]%mod)%mod;
        dp[now][2] = (dp[pre][0]*div3[2]%mod + dp[pre][1]*div3[1]%mod + dp[pre][2]*div3[0]%mod)%mod;
    } 
}
int main(){
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    DP(n,l,r);
    printf("%lld\n",(dp[n%2][0]%mod+mod)%mod);
    return 0;
}