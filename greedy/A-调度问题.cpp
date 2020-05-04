#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;


struct node{
    int r,o;
    bool operator<(const node a)const{
        return r-o>a.r-a.o;
    }
}job[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&job[i].r,&job[i].o);
    }
    sort(job,job+n);
    long long res = 0;
    long long mem = 0;
    for(int i=0;i<n;i++){
        res = max(res,mem+job[i].r);
        mem += job[i].o;
    }
    printf("%lld\n",res);
    return 0;
}