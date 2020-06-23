#include <bits/stdc++.h>

const double PI = acos(-1);
const int maxn = 3e6+10;

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while (ch<'0'||ch>'9')
    {
        if(ch=='-') f= -1;
        ch = getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        x = (x<<1)+(x<<3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}

struct Complex{
    double r,i;
    Complex(double _r=0, double _i=0): r(_r), i(_i){}
};
Complex operator+(Complex a, Complex b){
    return Complex(a.r+b.r, a.i+b.i);       
}
Complex operator-(Complex a, Complex b){
    return Complex(a.r-b.r,a.i-b.i);
}
Complex operator*(Complex a, Complex b){
    return Complex(a.r*b.r - a.i*b.i , a.r*b.i + b.r*a.i);
}


void FFT(Complex *a, int powLim,int op){
    if(powLim==1) return;
    Complex a0[powLim>>1],a1[powLim>>1];
    for(int i=0; i<powLim;i+=2){
        a0[i>>1] = a[i];
        a1[i>>1] = a[i+1];
    }
    FFT(a0,powLim>>1,op);
    FFT(a1,powLim>>1,op);
    Complex wn = Complex(cos(2*PI/powLim),op*sin(2*PI/powLim));
    Complex w = Complex(1,0);
    for(int k=0;k<(powLim>>1);k++){
        Complex t = w*a1[k];//蝴蝶操作
        a[k] = a0[k] + t;
        a[k+(powLim>>1)] = a0[k] - t;
        w = w*wn;
    }
}
Complex A[maxn],B[maxn];
int main(){
    int n,m;
    n=read();m=read();
    for(int i=0;i<=n;i++) A[i].r = read();
    for(int i=0;i<=m;i++) B[i].r = read();
    int limit = 1;
    while(limit<=n+m) {
        limit<<=1; 
    }
    FFT(A,limit,1);
    FFT(B,limit,1);
    for(int i=0;i<=limit;i++) A[i] = A[i]*B[i];
    FFT(A,limit,-1);
    for(int i=0;i<=n+m;i++) printf("%d ",(int)(A[i].r/limit+0.5));
    return 0;
}