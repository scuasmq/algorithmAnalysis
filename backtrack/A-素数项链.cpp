#include <bits/stdc++.h>
using namespace std;

int n;
int a[22];
int vis[22];
int isprime(int n){
    int res = 1;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n%i==0){
            res = 0;
            break;
        }
    }
    return res;
}

void Print(){
    for(int i=0;i<n;i++){
        printf("%d%c",a[i],i==n-1?'\n':' ');
    }

}
void dfs(int dep){
    if(dep>=n-1&&isprime(a[0]+a[n-1])){
        Print();
        return;
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]&&isprime(a[dep]+i)){
            vis[i] = 1;
            a[dep+1] = i;
            dfs(dep+1);
            vis[i] = 0;
        }
    }

}

int main(){
    scanf("%d",&n);
    if(n&1) {
        return 0;
    }
    a[0] = 1;
    dfs(0);
    return 0;
} 




// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>

// using namespace std;
// int cnt = 0;
// int n;
// int num[20];
// int vis[20];
// int notPrim[300];
// int prim[300];
// void euler_prime()
// {
//     int tot = 0;
//     for(int i =2;i<300;i++)
//     {
//         if(!notPrim[i])
//         {
//             prim[tot++] = i;
//         }
//         for(int j=0;j<tot&&i*prim[j]<300;j++)
//         {
//             notPrim[i*prim[j]] = 1; //prim[j]是最小素因子
//             if(i%prim[j]==0) break;
//         }
//     }
// }

// void print()
// {
//     for(int i=1;i<=n;i++)
//         if(i!=n) printf("%d ",num[i]);
//         else printf("%d\n",num[i]);

// }
// void search(int dep)
// {
//     //printf("%d\n",dep);
//     if(dep == n && !notPrim[num[n]+num[1]]) {
//         print();
//         cnt ++;
//         return;
//     }
//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i]&& !notPrim[num[dep]+i])
//         {
//             vis[i] = 1;
//             num[dep+1] = i;
//             search(dep+1);
//             vis[i] = 0;
//         }
//     }
// }
// int main()
// {
//     euler_prime();
//     scanf("%d",&n);
//     num[1] = 1;
//     if(n==17||n==19) return 0;
//     search(1);
//     printf("%d\n",cnt);
//     return 0;
// }