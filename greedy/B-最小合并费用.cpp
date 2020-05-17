#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,w[maxn];
long long res = 0;

priority_queue<int,vector<int>,greater<int> > pQ;
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        res = 0;
        while (!pQ.empty()) pQ.pop();
        
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&w[i]),pQ.push(w[i]);
        while (pQ.size()>1)
        {
            int x = pQ.top(); pQ.pop();
            x += pQ.top(); pQ.pop();
            pQ.push(x);
            res += x;
        }
        printf("%lld\n",res);
    }
    
    return 0;
}