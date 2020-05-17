#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}


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

vector<node> G[maxn];
int n,m;
int vis[maxn],minDis[maxn];
long long res = 0;
void Prim(){
    priority_queue<node> pQ;
    memset(minDis,INF,sizeof minDis);
    minDis[1] = 0;
    while (true)
    {
        int u = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(u==0||minDis[i]<minDis[u]))
                u = i;
        }
        if(u==0) break;
        vis[u] = true;res += minDis[u];
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].v;
            int w = G[u][i].w;
            minDis[v] = min(minDis[v],w);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        x = read(); y =read();z=read();
        // printf("\n%d%d%d\n",x,y,z);
        if(x==y) continue;
        G[x].push_back(node(y,z));
        G[y].push_back(node(x,z));
    }
    // printf("\n%d %d\n",G[1][0].v,G[1][0].w);
    Prim();
    printf("%lld\n",res);
    return 0;
}