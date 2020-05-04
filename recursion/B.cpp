#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
void chooseSum(int a[],int p,ll k,int sum,int n, int &f,int chosed){
    if(k==sum&&chosed){
        f = 1;
        return;
    }
    if(p==n||f==1) return;
    chooseSum(a,p+1,k,sum,n,f,0);
    chooseSum(a,p+1,k+a[p],sum,n,f,1);
}


int main(){
    int a[22];
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int f = 0;
    chooseSum(a,0,0,k,n,f,0);
    if(f) puts("YE5");
    else puts("N0");
    return 0;
}