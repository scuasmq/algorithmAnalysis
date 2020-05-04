// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// int divideApple(int sumdivi,int maxfactor,int remainPlate){
//     if(remainPlate==1&&sumdivi>maxfactor) return 0;
//     if(remainPlate==0) return 0;
//     if(sumdivi==1||maxfactor==1) return 1;
//     if(sumdivi<maxfactor) return divideApple(sumdivi,sumdivi,remainPlate);
//     if(sumdivi==maxfactor)
//     {
//         int res = divideApple(sumdivi,maxfactor-1,remainPlate);
//         return res+1;
//     }
//     return divideApple(sumdivi,maxfactor-1,remainPlate) + divideApple(sumdivi-maxfactor,maxfactor,remainPlate-1);

// }

// int main(){
//     int n,m;
//     while (~scanf("%d%d",&m,&n)){
//         printf("%d\n",divideApple(m,m,n));
//     }
    
//     return 0;
// }





// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// int dfs(int m,int n, int MX){
//     // printf("11111\n");
//     if(n<0) return 0;
//     if(m==0) return 1;
//     int res = 0;
//     for(int i=m;i>0;i--){
//         if(i<=MX)
//           res += dfs(m-i,n-1,i);
//     }
//     return res;
// }

// int main(){
//     int n,m;
//     while (~scanf("%d%d",&m,&n))
//     {
//         if(m<n){
//             puts("0");
//             continue;
//         }
//         m-=n;
//         printf("%d\n",dfs(m,n,m));
//     }
    
//     return 0;
// }


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){

    return 0;
}