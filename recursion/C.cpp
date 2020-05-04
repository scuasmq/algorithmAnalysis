#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;



void swap(int a[],int i,int j,int n){
    int t = a[j];
    a[j] = a[i];
    a[i] = t;
    sort(a+i+1,a+n);
}

void cpy(int a[],int c[],int n){
    for(int i=0;i<n;i++) a[i] = c[i];
}

void perm(int a[],int from,int n)
{
    if(from==n) 
    {
        for(int i=0;i<n;i++) printf("%d",a[i]);
        puts("");
        return;
    }
    for(int i=from;i<n;i++){
        int c[11];
        cpy(c,a,n);
        swap(a,from,i,n);
        perm(a,from+1,n);
        // swap(a,from,i,n);
        cpy(a,c,n);
    }
}
int main(){

    int n;
    int a[11];
    scanf("%d",&n);
    for(int i=0;i<n;i++) a[i] = i+1;
    perm(a,0,n);
    
    return 0;
}