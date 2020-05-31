#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+10;

int n,m,s,t,res;
bool vis[maxn];
struct node{
    int v,dis;
    node(){}
    node(int _v,int _dis){
        v = _v;
        dis = _dis;
    }
};

struct Edge{
    int v,next;
}e[maxn<<1];

int head[maxn],ecnt;

void init(){
    memset(head,-1,sizeof head);
    ecnt = 0;
}
void addEdge(int u,int v){
    e[ecnt].v = v;
    e[ecnt].next = head[u];
    head[u] = ecnt++;
}

queue<node> Q;
void bfs(){
    Q.push(node(s,0));
    while (true)
    {
        int u = Q.front().v; 
        int dis = Q.front().dis;
        Q.pop();
        vis[u] = 1;
        if(u==t){
            res = dis;
            return;
        }
        for(int i = head[u];~i;i = e[i].next){
            int v = e[i].v;
            if(!vis[v]){
                Q.push(node(v,dis+1));
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