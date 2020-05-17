#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int L,n,pos[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&L,&n);
        int resMax = 0,resMin = 0;
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&pos[i]);
            int opst = L+1-pos[i];
            resMax = max(resMax,max(opst,pos[i]));
            resMin = max(resMin,min(opst,pos[i]));
        }
        printf("%d %d\n",resMin,resMax);
    }
    

    return 0;
}