#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        priority_queue<int,vector<int>,greater<int>> pQ;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            pQ.push(x);
        }
        ll res =0;
        ll time =0;
        while (!pQ.empty())
        {
            res += time;
            time += pQ.top();
            pQ.pop();
        }
        printf("%lld\n",res);
    }
    
    return 0;
}