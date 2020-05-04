#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5010;
struct Sec{
    int l,r;
    bool operator<(const Sec a)const{
        return l==a.l? r>a.r: l<a.l;
    }
}sec[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        for(int i=0;i<n;i++){
            scanf("%d%d",&sec[i].l,&sec[i].r);
        }
        sort(sec,sec+n);
        int flag = 0;
        int res = 1;
        int lastR = sec[0].r;
        int maxR = sec[0].r;
        if(sec[0].l!=1) {printf("-1\n");continue;}
        
        for(int i=1;i<n;i++){
            if(sec[i].l>lastR+1){//更新最大
                if(sec[i].l>maxR){//如果不连续了
                    flag = 1;
                    break;
                }
                lastR = maxR;
                res++;
            }
            if(sec[i].l<=lastR+1){//+1保证是lastR内和下一个区间的最大
                if(sec[i].r>maxR) maxR = sec[i].r;
                if(sec[i].r>=r){
                    maxR = r;
                    res++;
                    break;
                }
            }
        }
        if(flag||maxR<r) printf("-1\n");
        else printf("%d\n",res);
    }
    
    return 0;
}
        // for(int i=1;i<n;i++){
        //     if(sec[i].l>lastR){//此时更新最大覆盖
        //         if(sec[i].l>maxR+1){//如果不连续，退出
        //             flag = 1;
        //             break;
        //         }
        //         if(maxR==lastR){//没有延伸
        //             lastR = maxR = sec[i].r;
        //             res++;
        //         }//有延伸
        //         else{
        //             res++;
        //             if(sec[i].l==lastR+1&&sec[i].r>=maxR){
        //                 res--;
        //             }
        //             lastR = max(maxR,sec[i].r);
        //             maxR = lastR;
        //             res++;
        //         }
        //     }
        //     else{
        //         maxR = max(maxR,sec[i].r);
        //     }
        // }

        // for(int i=1;i<n;i++){
        //     //更新已覆盖区间
        //     if(sec[i].l>lastR){
        //         if(lastR==maxR){//区间内没有往外扩展
        //             if(sec[i].l==lastR+1){//如果新的区间邻接
        //                 lastR = sec[i].r;
        //                 maxR = sec[i].r;
        //                 res++;
        //             }
        //             else{//否则不连续，退出
        //                 flag = 1;
        //                 break;
        //             }
        //         }
        //         else{//有扩展，更新
        //             lastR = maxR;
        //             res++;
        //         }
        //         if(lastR>=r) break;
        //     }
        //     else{
        //         if(sec[i].r>maxR) maxR = sec[i].r;
        //     }
        // }