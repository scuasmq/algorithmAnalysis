#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int w[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    int res = 0;
    int l = 1,r = n;
    sort(w+1,w+n+1);
    while (l<=r)
    {
        if(l==r){res++;break;}
        if(w[l]+w[r]<=m){res++;l++;r--;}
        else {res++;r--;}
    }
    printf("%d\n",res);
    return 0;
}