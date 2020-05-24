#include <bits/stdc++.h>

using namespace std;
const int maxn = 30;
int n;
int vis[maxn],flag;
vector<int> G[maxn];
int toNum(char c){
    return c-'a';
}

void dfs(int u){
    //如果找到了m,那么就返回
    if(u==toNum('m')){
        printf("Yes.\n");
        flag = 1;
        return;
    }
    //遍历u能转换的物质
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        //剪枝,前面已经转换过了,就不用转换了
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
            vis[v] = false;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(vis,0,sizeof vis);
        //是否能够转换
        flag = 0;
        for(int i=0;i<maxn;i++) G[i].clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char s[60];
            scanf("%s",s);
            int len = strlen(s);
            //把字母a-z映射为0-25的数字
            int x = toNum(s[0]),y = toNum(s[len-1]);
            G[x].push_back(y);
        }
        //从b开始转换
        dfs(toNum('b'));
        if(!flag) printf("No.\n");
    }
    return 0;
}