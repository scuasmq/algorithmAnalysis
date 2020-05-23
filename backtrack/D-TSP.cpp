    //Traveling Salesman Problem
    #include <bits/stdc++.h>

    using namespace std;
    const int maxn = 22;
    int vis[maxn];
    vector<int> G[maxn];
    vector<int> pth;
    int m,cnt;

    void Print(){
        printf("%d: ",++cnt);
        for(int i=0;i<pth.size();i++){
            printf(" %d",pth[i]);
        }
        printf(" %d",m);
        puts("");
    }

    void TSP(int u,int steps){
        if(u==m&&steps==20){
            Print();
            return ;
        }
        if(!vis[u]){
            vis[u] = true;
            pth.push_back(u);
            for(int i=0;i<G[u].size();i++){
                TSP(G[u][i],steps+1);
            }
            vis[u] = false;
            pth.pop_back();
        }
    }
    int main(){
        for(int i=1;i<=20;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            G[i].push_back(x);
            G[i].push_back(y);
            G[i].push_back(z);
        }
        scanf("%d",&m);
        for(int i=1;i<=20;i++) sort(G[i].begin(),G[i].end());
        TSP(m,0);
        return 0;
    }