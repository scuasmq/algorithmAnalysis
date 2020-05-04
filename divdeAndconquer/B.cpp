#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1e6+10;

int Partition(int a[],int l,int r){
    int x = a[l];
    int i=l,j=r;
    while (true)
    {
        // printf("11111\n");
        while(x<=a[j]&&i<j) j--;
        while(a[i]<=x&&i<j) i++;
        if(i==j) break;
        swap(a[i],a[j]);
    }
    a[l] = a[i];
    a[i] = x;
    return i;
}

// int qucickSort(int a[],int l,int r,int k){
//     if(l>=r) return a[l];
//     int p = Partition(a,l,r);
//     int curK = p-l+1;
//     if(curK<k) return qucickSort(a,p+1,r,k-curK);
//     else return qucickSort(a,l,p,k);
// }



int qucickSort(int a[],int l,int r,int k){
    // printf("l:%d r:%d k:%d\n",l,r,k);
    if(l>=r) return a[l];
    int p = Partition(a,l,r);
    int curK = r-p+1;
    // printf("p:%d curK:%d\n",p,curK);
    if(curK>k) return qucickSort(a,p+1,r,k);
    else return qucickSort(a,l,p,k-curK+1);
}


int main(){
    srand((int)time(0));
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[maxn];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int p = qucickSort(arr,0,n-1,k);
    printf("%d\n",p);
    // for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}