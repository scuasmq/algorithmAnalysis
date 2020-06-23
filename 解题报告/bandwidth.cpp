#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> G[30];
int vis[30],res;
char prt[30];
char permu[30];
map<char,int> mp;
char num2ch[30];
int cnt = 0;

void PRT(int k){
    for(int i=0;i<cnt;i++){
        printf("%c ",prt[i]);
    }
    printf("-> %d\n",k);
}

void dfs(int dep,int maxWid){
    if(dep == cnt && res!=maxWid ){
        for(int i=0;i<cnt;i++) prt[i] = permu[i];
        res = maxWid;
        // PRT(res);
        return ;
    }
    for(int i=1;i<=cnt;i++){
        if(!vis[i]) vis[i] = 1;
        else continue;
        permu[dep] = num2ch[i];
        int tmpWid = 0;
        int unvisCnt = G[i].size();
        for(int j=0;j<G[i].size();j++){
            for(int k=0;k<dep;k++) if(G[i][j]==mp[permu[k]]) tmpWid = max(tmpWid,dep-k),unvisCnt--;
        }
        maxWid = max(tmpWid,maxWid);
        if(maxWid<res && unvisCnt<res ) dfs(dep+1,maxWid);
        vis[i] = 0;
    }
}
void init(){
    for(int i=0;i<30;i++) G[i].clear();
    mp.clear();
    cnt = 0;
    res = INF;
}
int main(){
    char s[1000];
    while (cin>>s&&s[0]!='#'){
        init();
        int len = strlen(s);
        for (char ch = 'A'; ch <= 'Z'; ch++)
			if (strchr(s, ch) != NULL) {
				mp[ch] = ++cnt;
				num2ch[cnt] = ch;
			}
        char u = s[0];
        for(int i=1;i<len;i++){
            char v = s[i];
            if(v==':') continue;
            if(v==';'){
                u = s[++i];
                continue;
            }
            auto it = find(G[mp[u]].begin(),G[mp[u]].end(),mp[v]);
            if(it!=G[mp[u]].end()) continue;
            G[mp[u]].push_back(mp[v]);
            G[mp[v]].push_back(mp[u]);
        }
        for(int i=0;i<30;i++) sort(G[i].begin(),G[i].end());
        dfs(0,0);
        PRT(res);
    }

    
    return 0;
}