## 问题描述

[题目链接](https://vjudge.net/problem/UVA-140)

输入一个图，节点数不超过8，有一个由所有节点组成的序列。定义带宽为一个节点与其在图中相邻的节点在序列中的最远距离，整个序列的带宽为所有节点的带宽的最大值。求出带宽最小的序列。



## 分析

这个问题的解状态空间树是一颗排列树。因此考虑用dfs的方法来求解问题。

显约束：每个字符只出现一次。

隐约束：由于是求的所有的最大值的最小值，因此在dfs过程中可以用启发函数进行剪枝，即：考虑当前获得的最终最小值和当前最大值比较，看是否能够有得到更优解的可能。

有两种方法剪枝：

- 如果当前的最大值小≥之前的最小值，剪枝。
- 如果未来的带宽最小值≥之前的最小值，剪枝。



同时这道题需要处理输入，需要把离散的字母映射为连续的数字，这样在搜索时可以提升速度。



##  证明

剪枝1：如果当前的最大值小≥之前的最小值，那么无论之后的最大值有多么小，都不可能得到更优的解，因此可以剪枝。

剪枝2：考虑未来的带宽，与当前节点相邻的但是还未出现的节点挨个排列在当前节点之后，即未来的最小带宽，如果此带宽已经≥之前的最小值，也就是说未来的最最优解都不比之前的最小值更优，那么就没有搜索的必要，因此可以剪枝。



## 代码

```c++
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
```



## 解释

先将出现的字母从小到大映射为1-cnt。从小到大的目的和对邻接表的排序是为了保证搜索时是按照字典序来排列的。

另外输入时，是会有重复的边出现，因此还要判重。

$vis$来表示显约束。

$tmpWid$表示遍历当前节点的邻点获得的最大值，$unvisCnt$是还未出现的邻点个数，表示了未来可能的最优带宽。

23行`res!=maxWid`是为了保证储存的是先访问到排列，使字典序最小。



## 复杂度分析

因为解空间树是一颗排序树，所以时间复杂度是$O(n)$。