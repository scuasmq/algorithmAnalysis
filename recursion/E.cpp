#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int p(int n,int m){

    if(n==0||m==1) return 1;
    if(n<m) return p(n,n);
    return p(n,m-1)+p(n-m,m);

}
int main(){
    int n,k;
    while (~scanf("%d%d",&n,&k))
    {
        if(n<k){
            puts("0");
            continue;
        }
        printf("%d\n",p(n,k));
    }
    
    return 0;
}