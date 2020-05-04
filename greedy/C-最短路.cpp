#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e4+10;
int n,m;

struct Edge{
    int v,next,w;
}e[maxn];
int head[maxn],ecnt,vis[maxn],dis[maxn];
void init(){
    memset(head,-1,sizeof head);
    ecnt = 0;
}
void addEdge(int  u,int v,int w){ 
    e[ecnt].next = head[u];
    e[ecnt].v = v;
    e[ecnt].w = w;
    head[u] = ecnt++;
}

struct heapNode{
    int u,d;
    heapNode(){}
    heapNode(int _u,int _d){u=_u;d=_d;}
    bool operator< (const heapNode a) const{
        return d>a.d;
    }
};

void Dijstra(){
    priority_queue<heapNode> pQ;
    memset(vis,0,sizeof vis);
    memset(dis,INF,sizeof dis);
    pQ.push(heapNode(1,dis[1] = 0));
    while (!pQ.empty())
    {
        int u = pQ.top().u; pQ.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=head[u];~i;i= e[i].next){
            int v = e[i].v,w = e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pQ.push(heapNode(v,dis[v]));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addEdge(x,y,z);
        addEdge(y,x,z);
    }
    Dijstra();
    printf("%d\n",dis[n]==INF?-1:dis[n]);
    return 0;
}