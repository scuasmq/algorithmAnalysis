#include <bits/stdc++.h>
using namespace std;

int N;
long long res = 0;
int x[11];
int insert(int ith){
    for(int i=1;i<ith;i++){
        if(x[i]==x[ith]||abs(x[i]-x[ith])==abs(i-ith)) return false;
    }
    return true;
}
void dfs(int ith){
    if(ith>N) {res++;return;}
    for(int i=1;i<=N;i++){
        x[ith] = i; 
        if(insert(ith)) dfs(ith+1);
    }
}
int main(){
    while (~scanf("%d",&N))
    {
        res = 0;
        dfs(1);
        printf("%lld\n",res);
    }
    
    return 0;
}