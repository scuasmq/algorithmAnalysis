#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
struct Sec{
    int l,r;
    bool operator <(const Sec a)const{
        return r==a.r?l<a.l:r<a.r;
    }
}sec[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&sec[i].l,&sec[i].r);
        sort(sec+1,sec+n+1);
        int lastMoment = 0;
        int res = 0;
        int cnt = 1;
        while (cnt<=n)
        {
            if(lastMoment<=sec[cnt].l) res++,lastMoment = sec[cnt++].r;
            else cnt++;
        }
        printf("%d\n",res);
    }
    return 0;
}