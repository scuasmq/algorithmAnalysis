#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e5+10;

void merge(int a[],int l,int m,int r,int b[]){
    int i=l,j = m;
    int cnt = l;
    while (i<m&&j<r)
    {
        if(a[i]<=a[j]){
            b[cnt++] = a[i++];
        }else b[cnt++] = a[j++];
    }
    if(l<m){
        while(i<m) b[cnt++] = a[i++];
    }
    if(j<r){
        while(j<r) b[cnt++] = a[j++];
    }
}

void copy(int a[],int b[],int l,int r){
    for(int i=l;i<r;i++) a[i] = b[i];
}
void mergesort(int a[],int l,int r){
    if(l==r-1) return;
    int m = (l+r)/2;

    mergesort(a,l,m);
    mergesort(a,m,r);


    int b[maxn];
    merge(a,l,m,r,b);
    copy(a,b,l,r);
}

int main(){
    int n;
    while (~scanf("%d",&n))
    {
        int arr[maxn];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        mergesort(arr,0,n);
        for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
        printf("%d\n",arr[n-1]);
    }
    return 0;
}