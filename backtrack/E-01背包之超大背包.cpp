#include <bits/stdc++.h>

using namespace std;
int N,V;
struct Obj{
    int w,v;
}o[90];
long long res = 0;

long long cut(int ith){
    long long ret = 0;
    for(int i=ith;i<N;i++) ret+=o[i].v;
    return ret;
}
void dfs(int ith, int reV,long long tmpValue){
    if(ith>=N){res = max(res,tmpValue); return;}
    if(o[ith].w<=reV){
        dfs(ith+1,reV-o[ith].w,tmpValue+o[ith].v);
    }
    if(tmpValue+cut(ith)>res){
        dfs(ith+1,reV,tmpValue);
    }
}

int main(){
    scanf("%d%d",&N,&V);
    for(int i=0;i<N;i++) scanf("%d%d",&o[i].w,&o[i].v);
    dfs(0,V,0);
    printf("%lld\n",res);
    return 0;
}