#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef pair<char,int> P;
char s[maxn];
struct node{
    char ch;
    int v;
    node *lch,*rch;
    node(){};
    node(char _c,int _v,node *l,node* r){
        ch = _c;
        v= _v;
        lch = l;
        rch = r;
    }
    bool operator<(const node a)const{
        return v>a.v;
    }
};
priority_queue<node> pQ;

node *buildHuffTree(){//vector<char> ch,map<char,int> mp
    node *root;
    while (pQ.size()!=1)
    {
        node a =pQ.top();pQ.pop();
        node b =pQ.top();pQ.pop();
        node *newA = new node(a.ch,a.v,a.lch,a.rch);
        node *newB = new node(b.ch,b.v,b.lch,b.rch);
        node *newC = new node('\0',a.v+b.v,newA,newB);
        root = newC;
        pQ.push(*newC);
    }
    return root;
}

vector<P> caps;
vector<P> lens;
void dfs(node *a,int dep){
    if(a->ch!='\0'){
        lens.push_back(P(a->ch,dep));
        return;
    }
    else{
        dfs(a->lch,dep+1);
        dfs(a->rch,dep+1);
    }
}

void init(){
    while (pQ.size()) pQ.pop();
    while (caps.size()) caps.clear();
    while (lens.size()) lens.clear();
}

int main(){
    while (~scanf("%s",s))
    {

        init();
        map<char,int> mp;
        int cnt = 0;
        int len = strlen(s);
        for(int i=0;i<len;i++) mp[s[i]] = -1;
        for(int i=0;i<len;i++){
            if(mp[s[i]]==-1){
                caps.push_back(P(s[i],1));
                mp[s[i]] = cnt++;
            }
            else{
                caps[mp[s[i]]].second ++;
            }
        }
        
        for(int i=0;i<cnt;i++){
            pQ.push(node(caps[i].first,caps[i].second,NULL,NULL));
        }

        dfs(buildHuffTree(),0);
        int res = 0;
        for(int i=0;i<cnt;i++){
            char ch = lens[i].first;
            int chLen = lens[i].second;
            int num = caps[mp[ch]].second;
            res += num*chLen;
        }
        printf("%d %d %.1lf\n",len*8,res,(1.0)*len*8/res);
    }
    return 0;
}