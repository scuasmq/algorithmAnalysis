#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e4+10;
int n,m;
int w[maxn];
int fa[maxn];
ll sumW[maxn];
vector<int> G[maxn];

ll dfs(int u){
    if(sumW[u]) return sumW[u];
    ll res = w[u];
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i], val = w[v];
        if(v!=fa[u]){
            res += dfs(v);
        }
    }
    return sumW[u]=res;
}

void findFa(int u,int pa){
    if(!G[u].size()) return;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(v!=pa){
            fa[v] = u;
            findFa(v,u);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    findFa(1,0);
    for(int i=0;i<m;i++){
        int x = 0;
        scanf("%d",&x);
        ll res = dfs(x);
        printf("%lld\n",res);
    }
    return 0;
}