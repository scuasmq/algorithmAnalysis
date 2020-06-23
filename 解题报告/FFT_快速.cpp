#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const int maxn = (1 << 20) + 10 << 1;

int rev[maxn], len,lim = 1;

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


void FFT(Complex *a, int opt){
    for(int i=0;i<lim;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(int dep =1;dep<=log2(lim);dep++){
        int m = 1<<dep;
        Complex wn = Complex(cos(2*PI/m),opt*sin(2*PI/m));
        for(int k=0;k<lim;k+=m){
            Complex w = Complex(1,0);
            for(int j=0;j<m/2;j++){
                Complex t = w*a[k+j+m/2];
                Complex u = a[k+j];
                a[k+j] = u+t;
                a[k+j+m/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(opt==-1) for(int i=0;i<lim;i++) a[i].r/=lim;
}


Complex A[maxn],B[maxn];
int main(){
    int n,m;
    n=read();m=read();while(lim<=n+m) lim<<=1,len++;
    for(int i=0;i<lim;i++) {
        rev[i] = (rev[i>>1]>>1) | ((i&1)<<(len-1));
        cout<<bitset<sizeof(rev[i])*8>(rev[i])<<endl;//int占4字节，一个字节8位，最终输出的是32个0或1
    }
    for(int i=0;i<=n;i++) A[i].r=read();
    for(int i=0;i<=m;i++) B[i].r=read();
    

    

    FFT(A,1);
    FFT(B,1);
    for(int i=0;i<=lim;i++) A[i] = A[i]*B[i];
    FFT(A,-1);
    for(int i=0;i<=n+m;i++) printf("%d ",(int)(A[i].r+0.5));
    return 0;
}