#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
struct Edge{
    int w,u,v;
}e[maxn];

int fa[maxn];
int n,m;
void init(){
    for(int i=0;i<maxn;i++) fa[i] = i;
}
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}

int Find(int i){
    if(fa[i]!=i) return fa[i] = Find(fa[i]);
    else return i;
}

int Union(int u,int v){
    int ru = Find(u);
    int rv = Find(v);
    if(ru!=rv){
        fa[rv] = ru;
        return true;
    }
    return false;
}

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i].u = u; e[i].v=v; e[i].w=w;
    }
    sort(e,e+m,cmp);
    int cnt = 0;
    ll res = 0;
    for(int i=0;i<m&&cnt<n-1;i++){
        if(Union(e[i].u,e[i].v)) cnt++,res+=e[i].w;
    }
    // for(int i=1;i<=n;i++) printf("%d ",fa[i]);
    // printf("\n%d",cnt);
    // puts("");
    
    printf("%lld\n",cnt==n-1?res:-1);
    return 0;
}