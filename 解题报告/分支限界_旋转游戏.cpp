#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;
int cent8[] = {6,7,8,11,12,15,16,17},G[24],findAns,maxDep;
char sol[maxn];
int op[][7] = {
    {0,2,6,11,15,20,22   }, //A
    {1,3,8,12,17,21,23   }, //B
    {10,9,8,7,6,5,4      }, //C
    {19,18,17,16,15,14,13}, //D
    {23,21,17,12,8,3,1   }, //E
    {22,20,15,11,6,2,0   }, //F
    {13,14,15,16,17,18,19}, //G
    {4,5,6,7,8,9,10      }  //H
};

int invOp[8] = {5,4,7,6,1,0,3,2};

void Grotate(int opNum){
    int tmp = G[op[opNum][0]];
    for(int i=0;i<=5;i++){
        G[op[opNum][i]] = G[op[opNum][i+1]];
    }
    G[op[opNum][6]] = tmp;
}

int H(){
    int cnt = 0;
    int nCnt[4]={0};
    for(int i=0;i<8;i++){
        cnt = max(cnt,++nCnt[G[cent8[i]]]);
    }
    return 8-cnt;
}

void dfs(int dep,int preOp){
    if(findAns||dep>maxDep||dep+H()>maxDep) return;
    if(!H()){
        sol[dep] = '\0';
        printf("%s\n%d\n",sol,G[cent8[0]]);
        findAns = 1;
        return ;
    }
    for(int i=0;i<8;i++){
        if(dep&&i==invOp[preOp]) continue;
        Grotate(i);
        sol[dep] = i+'A';
        dfs(dep+1,i);
        Grotate(invOp[i]);
    }
}

int main(){
    while(scanf("%d",&G[0])&&G[0]){
        for(int i =1;i<24;i++) scanf("%d",&G[i]);
        if(!H()){
            printf("No moves needed\n%d\n",G[cent8[0]]);
            continue;
        }
        findAns = 0;
        maxDep = 1;
        while (true){
            dfs(0,100);
            maxDep++;
            if(findAns) break;
        }
    }
    return 0;
}