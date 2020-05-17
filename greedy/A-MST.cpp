//用链式前向星，TLE，以后再改8...
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3+10;
const int maxm = 1e6+10;
const int INF = 0x3f3f3f3f;
struct node
{
    int v,w;
    node(int _v,int _w){
        v = _v;
        w = _w;
    }
    bool operator<(const node t) const{
        return w>t.w;
    }
};
int head[maxn],ecnt;
struct Edge{
    int v,w,nxt;
}e[maxm<<1];
void init(){
    memset(head,-1,sizeof head);
    ecnt = 0;
}
void addEdge(int u, int v,int w){
    e[ecnt].v = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt++;
}


int n,m;
int vis[maxn];
long long res = 0;
void Prim(){
    priority_queue<node> pQ;
    for(int i=head[1];~i;i=e[i].nxt) pQ.push(node(e[i].v,e[i].w));
    vis[1] = true;
    int cnt = n-1;
    while (!pQ.empty()&&cnt)
    {
        node t = pQ.top();pQ.pop();
        if(vis[t.v]) continue;
        res += t.w; cnt--; vis[t.v] = 1;
        for(int i=head[t.v];~i;i=e[i].nxt)
            if(!vis[e[i].v])   pQ.push(node(e[i].v,e[i].w));
    }
}
int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==y) continue;
        addEdge(x,y,z);
        addEdge(y,x,z);
    }
    Prim();
    printf("%lld\n",res);
    return 0;
}