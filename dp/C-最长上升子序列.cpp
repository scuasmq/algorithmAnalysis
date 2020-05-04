#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e5+10;
int lis(int arr[],int n){
    int s[maxn];
    int lastPos = 0;
    for(int i=0;i<n;i++){
        int curPos = lower_bound(s,s+lastPos,arr[i])-s;
        s[curPos] = arr[i];
        lastPos = max(lastPos,curPos+1);
    }
    return lastPos;
}

int main(){
    double x = 0.29;
    int a = 0.29*100;
    cout<<a<<endl;
    int n;
    scanf("%d",&n);
    int arr[maxn];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",lis(arr,n));
    return 0;
}