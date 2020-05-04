#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1e3+30;

void merge(int l,int r,int t[][maxn]){
    int m = (r-l+1)/2;
    int len = r-l+1;
    for(int i=l;i<=r;i++){
        for(int j=1;j<=len/2;j++){
            int k = i+len/2;
            if(k>r) k = k%len+l-1;
            t[i][m+j] = t[k][j];
        }
    }
}

void setCalender(int l,int r,int t[][maxn]){
    if(l+1==r){
        t[l][1] = l; t[l][2] = r;
        t[r][1] = r; t[r][2] = l;
        return;
    }
    int m = (l+r)/2;
    setCalender(l,m,t);
    setCalender(m+1,r,t);
    int len = r-l+1;
    merge(l,r,t);
}
int main(){
    int n;
    int table[maxn][maxn];
    setCalender(1,1024,table);
    while (~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++){
                printf("%d ",table[i][j]);
            }
            printf("%d\n",table[i][n]);
        }
    }
    
    return 0;
}