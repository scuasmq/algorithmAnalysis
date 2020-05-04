#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
int merge(int a[],int l ,int mid,int r,int b[]){
    int res = 0;
    int i=l,j=mid+1;
    int cnt = l;
    int pre = INF;
    while (i<=mid&&j<=r)
    {
        if(a[i]>a[j]){
            while (a[i]>a[j]&&j<=r)
            {
                b[cnt++] = a[j++];
            }
            res+=j-(mid+1);
            pre = a[i];
            // printf("i:%d 1111 %d\n",a[i],j-(mid+1));
        } 
        else if(a[i]<=a[j]){
            int tmp = j;

            while (a[i]<a[tmp]&&tmp>=mid+1)
            {
                tmp--;
            }
            // printf("i:%d 44444 %d\n",a[i],j-(mid+1));
            if(pre!=a[i])res+= j-(mid+1);
            pre = a[j];
            b[cnt++] = a[i++];
        }
    }
    if(i<=mid){
        while(i<=mid){
            b[cnt++] = a[i++];
            if(a[i]>a[r]) {
                res+=r-mid;
                // printf("2222\n");
            }
        }
    }
    if(j<=r){
        while(j<=r){
            if(a[mid]>a[j]) {
                res++;
                // printf("3333\n");
            }
            b[cnt++] = a[j++];
        }
    }
    // printf("l:%d r:%d mid:%d res:%d\n",l,r,mid,res);
    // for(int i=l;i<=r;i++) printf("%d ",a[i]);
    // puts("\n");
    return res;
}

void cp(int a[],int b[],int l,int r){
    for(int i=l;i<=r;i++) a[i] = b[i];
}

int mergeSort(int a[],int l,int r){
    if(l==r) return 0;
    int mid = (l+r)/2;
    int left = mergeSort(a,l,mid);
    int rig = mergeSort(a,mid+1,r);

    int b[maxn];
    int now = merge(a,l,mid,r,b);
    cp(a,b,l,r);

    return left+rig+now;
}

int main(){
    int n;
    while (~scanf("%d",&n))
    {
        int arr[maxn];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        printf("%d\n",mergeSort(arr,0,n-1));
        // for(int i=0;i<n;i++) printf("%d ",arr[i]);
        // puts("");

    }
    return 0;
}