#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int maxn = 3e3+10;
// inline char int2char(int a){
//     return a+'0';
// }

// inline char char2int(char a){
//     return a-'0';
// }


// string bigAdd(string x, string y,int op){
//     string res;
//     if(op==0){
//         int xLen = x.length(),yLen = y.length();
//         vector<int> num;
//         int carry=0,cnt=0;
//         int i=xLen-1,j=yLen-1;
//         for(;i>=0&&j>=0;i--,j--){
//             int r = char2int(x[i])+char2int(y[j])+carry;
//             carry = r/10;
//             r = r%10;
//             num.push_back(r);
//         }
//         if(i>=0){
//             while(i>=0){

//                 int r = char2int(x[i])+carry;
//                 carry = r/10;
//                 r = r%10;
//                 num.push_back(r);
//                 i--;
//             }
//         }
//         else if(j>=0){
//             while (j>=0)
//             {
//                 int r = char2int(y[j])+carry;
//                 carry = r/10;
//                 r = r%10;
//                 num.push_back(r);
//                 j--;
//             }
//         }
//         if(carry) num.push_back(carry);
//         for(int i=num.size()-1;i>=0;i--){
//             res += int2char(num[i]);
//         }
//     }//减法
//     else{
//         printf("minus\n");
//         int xLen = x.length(),yLen = y.length();
//         vector<int> num;
//         if(xLen<yLen||(xLen==yLen&&x<y)) {swap(x,y);swap(xLen,yLen);res +='-';}
//         int carry=0,cnt=0;
//         int i=xLen-1,j=yLen-1;
//         string t;
//         for(int k=0;k<i-j;k++) t+='0';
//         string c = y;
//         y = t+c;
//         for(;i>=0;i--){
//             int r = char2int(x[i])-char2int(y[i])+carry;
//             if(r<0){
//                 r+=10;
//                 carry = -1;
//             }
//             else carry = 0;
//             num.push_back(r);
//         }
//         int flag = 0;
//         for(int k=num.size()-1;k>=0;k--){
//             if(flag) res+=int2char(num[k]);
//             if(!num[k]) flag=1;
//             cout<<num[k]<<endl;
//         }
//     }
//     return res;
// }

// // string bigMulti(string x,string y){
// //     string a,b,c,d;
// //     int highX = x.length()/2;
// //     int highY = y.length()/2;
    
// //     for(int i=0;i<highX;i++) a+=x[i];
// //     for(int i=0;i<highX;i++) a+='0';

// //     for(int i=0;i<highY;i++) c+=y[i];
// //     for(int i=0;i<highY;i++) c+='0';

// //     for(int i=highX;i<x.length();i++) b+=x[i];
// //     for(int i=highY;i<y.length();i++) d+=y[i];
    
// //     string z1 = bigMulti(a,c);
// //     string z2 = bigMulti(bigAdd(a,b,0),bigAdd(d,c,0));
// //     string z3 = bigMulti(b,d);
    
// //     z2 = bigAdd(z2,z1,1);
// //     z2 = bigAdd(z2,z3,1);
    
// //     return a;
    
// // }


// int main(){
//     string x,y,res;
//     while (cin>>x>>y)
//     {
//         // cout<<bigMultiVert(x,y)<<endl;
//         // cout<<bigAdd(x,y,0)<<endl;
//         stringstream ss1;
//         stringstream ss2;
//         ss1.str(x);
//         int a,b;
//         ss1>>a;
//         ss2.str(y);
//         ss2>>b;
//         cout<<a<<' '<<b<<endl;
        
//     }
    

//     printf("I love Python.\n");
//     return 0;
// }

int a[maxn],b[maxn],c[maxn];
int main(){
    string x,y;
    while (cin>>x>>y)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        int alen=x.length();
        int blen=y.length();
        for(int i=1;i<=alen;i++) a[i] = x[alen-i]-'0';
        for(int i=1;i<=blen;i++) b[i] = y[blen-i]-'0';
        for(int i=1;i<=alen;i++)
            for(int j=1;j<=blen;j++)
                c[i+j-1] += a[i]*b[j];
        int maxlen = alen+blen;
        // for(int i=1;i<=maxlen;i++)
        //     printf("c[%d]:%d\n",i,c[i]);
        for(int i=1;i<=maxlen;i++)
        {
            // printf("c[%d]:%d\n",i,c[i]);
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
        while (c[maxlen]==0&&maxlen>0)
        {
            maxlen--;
        }
        for(int i=maxlen;i>=1;i--) printf("%d",c[i]);
        puts("");
    }
    printf("I love Python.\n");
    return 0;
    
}