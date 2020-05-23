#include <bits/stdc++.h>

using namespace std;
const int maxn = 30;
int n,m;
int vis[maxn][maxn];
int flag;
struct Dirct{
    int x,y;
}drt[8];

vector<char> pth;

void drtInit(){
    drt[0].x=-2;drt[0].y=-1;
    drt[1].x=-2;drt[1].y=1;

    drt[2].x=-1;drt[2].y=-2;
    drt[3].x=-1;drt[3].y=2;

    drt[4].x=1;drt[4].y=-2;
    drt[5].x=1;drt[5].y=2;

    drt[6].x=2;drt[6].y=-1;
    drt[7].x=2;drt[7].y=1;
}

void Print(){
    for(int i=0;i<n*m*2;i++){
        printf("%c",pth[i]);
    }
    puts("");
}

int inBound(int x,int y){
    if(x<0||x>=n) return 0;
    if(y<0||y>=m) return 0;
    return 1;
}

int toChar(int x){
    return x+'A';
}

void dfs(int x,int y,int cnt){
    if(flag) return;
    if(cnt==n*m){
        flag = 1;
        Print();
        return;
    }
    for(int i=0;i<8;i++){
        int xx = x+drt[i].x;
        int yy = y+drt[i].y;
        if(inBound(yy,xx)&&!vis[xx][yy]){
            vis[xx][yy] = true;
            pth.push_back(toChar(xx));  
            pth.push_back(yy+'0'+1);
            dfs(xx,yy,cnt+1);
            pth.pop_back();
            pth.pop_back();
            vis[xx][yy]=false;
        }
    }
    
}
int main(){
    drtInit();
    scanf("%d%d",&n,&m);
    pth.push_back(toChar(0));
    pth.push_back('1');
    vis[0][0] = true;
    dfs(0,0,1);
    if(!flag)printf("impossible\n");
    return 0;
}