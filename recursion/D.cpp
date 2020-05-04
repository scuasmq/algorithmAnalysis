#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt = 1;
void move(int n,char a,char b){
    printf("step %d: %d From %c To %c\n",cnt++,n,a,b);
}

void Hanoi(int n, char a,char b,char c){
    if(n==0) {
        return;
    }
    Hanoi(n-1,a,c,b);
    move(n,a,c);
    Hanoi(n-1,b,a,c);
}

int main(){
    int n;
    while (~scanf("%d",&n))
    {
        cnt = 1;
        printf("%d\n",(int)pow(2,n)-1);
        Hanoi(n,'A','B','C');
    }
    
    return 0;
}