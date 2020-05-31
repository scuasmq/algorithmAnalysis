#include <bits/stdc++.h>

using namespace std;
const int maxn = 25;
int n,m,res;
char mat[maxn][maxn];
int vis[maxn][maxn];
int dis[maxn];
int drt[4][2]={
    -1,0,
    0,1,
    1,0,
    0,-1
};

struct node{
    int x,y;
    node (int _x=-1,int _y=-1){x=_x;y=_y;}
};

//访问过为false，没有访问过为true
int visTestAndSet(node a){
    return vis[a.x][a.y]?false:vis[a.x][a.y]=1;
}

//in boundary is true
int inBoundary(node a){
    return a.x>=0&&a.x<n&&a.y>=0&&a.y<m;
}

void bfs(){
    memset(vis,0,sizeof vis);
    res = 0;
    node s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(mat[i][j]=='@') s.x=i,s.y=j;
    }
    queue<node> Q;
    Q.push(s);
    visTestAndSet(s); res++;
    while (!Q.empty())
    {
        node u = Q.front();Q.pop();
        for(int i=0;i<4;i++){
            node t = node(u.x+drt[i][0],u.y+drt[i][1]);
            if(!inBoundary(t)) continue;
            if(mat[t.x][t.y]=='#') continue;
            if(visTestAndSet(t)){
                res++;
                Q.push(t);
            }
        }   
    }
}


int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",mat[i]);
        bfs();
        printf("%d\n",res);

    }
    

    return 0;
}