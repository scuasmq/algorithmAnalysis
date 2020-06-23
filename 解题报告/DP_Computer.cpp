#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 1e4+10;
struct edge{
    int to;
    int next;
    int w;
    edge(int t=-1,int n=-1,int _w=0){
        to = t;
        next = n;
        w = _w;
    }
}e[maxn<<1];
int cnt,head[maxn];

void addEdge(int u,int v,int w){
    e[cnt] = edge(v,head[u],w);
    head[u] = cnt++;
}
int maxSon[maxn],upMax[maxn],downMax[maxn],downSec[maxn];
int n;

void init(){
        cnt = 0;
        memset(maxSon,-1,sizeof maxSon);
        memset(upMax,-1,sizeof upMax);
        memset(downMax,-1, sizeof downMax);
        memset(downSec,-1 ,sizeof downSec);
        memset(head,-1,sizeof head);
}

int dfs1(int u,int fa){
    if(downMax[u]>=0) return downMax[u];
    downMax[u] = upMax[u] = downSec[u] = maxSon[u] = 0;
    
    for(int i = head[u];~i;i = e[i].next){
        int v = e[i].to;
        if(v==fa) continue;
        if(downMax[u]<dfs1(v,u)+e[i].w){
            maxSon[u] = v;
            downSec[u] = max(downSec[u],downMax[u]);
            downMax[u] = dfs1(v,u) + e[i].w;
        }
        else if(downSec[u]<dfs1(v,u)+e[i].w)
            downSec[u] = max(downSec[u],dfs1(v,u)+e[i].w);
    }
    return downMax[u];
}
void dfs2(int u,int fa){
    for(int i=head[u];~i;i=e[i].next){
        int v = e[i].to;
        if(v==fa) continue;
        if(v==maxSon[u]) upMax[v] = e[i].w+max(upMax[u],downSec[u]);
        else upMax[v] = e[i].w+max(upMax[u],downMax[u]);
        dfs2(v,u);
    }
}

int main(){
    while (~scanf("%d",&n))
    {
        init();
        for(int i=2;i<=n;i++){
            int v,w;
            scanf("%d%d",&v,&w);
            addEdge(i,v,w);
            addEdge(v,i,w);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i = 1;i<=n;i++)
            printf("%d\n",max(upMax[i],downMax[i]));
    }
    return 0;
}