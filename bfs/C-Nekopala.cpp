#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e5+10;
int n,k,res;
int vis[maxn];
int dis[maxn];
int visTestAndSet(int t){
    return vis[t]?false:vis[t]=true;
}
int inBoundary(int t){
    return t>=0&&t<maxn;
}
    

void bfs(){
    res  = 0;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    queue<int> Q;
    Q.push(n);
    vis[n] = true;
    while (!Q.empty())
    {
       int t = Q.front();Q.pop();
        int t1 = t - 1;
        int t2 = t + 1;
        int t3 = t<<1;
        if(inBoundary(t1)&&visTestAndSet(t1)) Q.push(t1),dis[t1]=dis[t]+1;
        if(inBoundary(t2)&&visTestAndSet(t2)) Q.push(t2),dis[t2]=dis[t]+1;
        if(inBoundary(t3)&&visTestAndSet(t3)) Q.push(t3),dis[t3]=dis[t]+1;
        if(t1==k||t2==k||t3==k) return;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&k);
        if(n>=k){   
            printf("%d\n",n-k);
            continue;
        }
        bfs();
        printf("%d\n",dis[k]);
    }
        

    return 0;
}