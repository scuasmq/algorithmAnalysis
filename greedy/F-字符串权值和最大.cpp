#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;
char s[maxn];
int findMax(int a[]){
    int m=0,cap = 0;
    for(int i=0;i<26;i++){
        if(m<a[i]){m=a[i];cap = i;}
    }
    return cap;
}
int main(){
    scanf("%s",s);
    int num[26]={0};
    int len = strlen(s);
    for(int i=0;i<len;i++) num[s[i]-'a']++;
    int res = 0;
    for(int i=26;i>=1;i--){
        int pos = findMax(num);
        res += i*num[pos];
        num[pos] = 0;
    }
    printf("%d\n",res);
    return 0;
}