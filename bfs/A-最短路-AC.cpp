#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
int n,m,s,t,res;

struct Edge{
    int v,next;
}e[maxn<<1];
int dis[maxn];
int head[maxn],ecnt;

void init(){
    memset(head,-1,sizeof head);
    memset(dis,INF,sizeof dis);
    ecnt = 0;
}
void addEdge(int u,int v){
    e[ecnt].v = v;
    e[ecnt].next = head[u];
    head[u] = ecnt++;
}

queue<int> Q;
void bfs(){
    Q.push(s);
    dis[s] = 0;
    while (true)
    {
        int u = Q.front();
        Q.pop();
        if(u==t){
            res = dis[u];
            return;
        }
        for(int i = head[u];~i;i = e[i].next){
            int v = e[i].v;
            if(dis[v]==INF){
                dis[v] = dis[u]+1;
                Q.push(v);
            }
        }
    }
}

int main(){
    init();
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
        addEdge(y,x);
    }
    bfs();
    printf("%d\n",res);

    return 0;
}