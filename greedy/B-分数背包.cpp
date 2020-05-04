#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long ll;

struct node
{
    int w,v;
    double costPer;
    bool operator <(const node a)const{
        return costPer > a.costPer;
    }
}obj[maxn];

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        node &t = obj[i];
        scanf("%d%d",&t.v,&t.w);
        t.costPer = (1.0)*t.v/t.w;
    }
    sort(obj+1,obj+1+n);
    // for(int i=1;i<=n;i++)
    //     printf("%lf\n",obj[i].costPer);
    double res = 0;
    double remain = m;
    int cnt = 1;
    while (remain>0)
    {
        if(remain>obj[cnt].w){
            remain -= obj[cnt].w;
            res += obj[cnt++].v;
        }
        else{
            res += remain*obj[cnt].costPer;
            break;
        }
    }
    printf("%.3lf\n",res);
    return 0;
}