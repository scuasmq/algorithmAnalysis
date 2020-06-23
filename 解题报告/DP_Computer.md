## 问题描述

[link](http://acm.hdu.edu.cn/showproblem.php?pid=2196)

给定一棵树，树边有制定的长度，求其他所有点到`i`点的距离的最大值，`i`： for i in tree。

tree的大小: 1e4。



## 分析

其他所有点到i点的距离的最大值，也是i点到其他所有点距离的最大值。

一个很朴素的想法是对每个点dfs一下，统计出i能到达的最大距离，但是n个点都要访问n次，时间复杂度到达$O(n^2)$，肯定会超时。用bfs也是同理。

由于我们在求出一个点到其他点的最大距离的时候，可能对另外的点的求解有帮助，所以尝试使用动态规划的方法。

由于树是有“方向”的，为了讨论的有序性，把树看作是有根的。假设节点 `fa[i]` 到不经过`i`的节点和 `i`到`i`所有子树的节点的最大距离已经知道，那么很显然$maxDis[i] = max(upMax[i],downMax[i])$。在树上的转移方向有向上和向下，因此要用两个dfs。

首先第一个dfs求出节点 `i`  在其子树中能到达的最大距离，这很好求，直接累加就行了。

第二个dfs求出节点 `i` 往上走能到达的最大距离，到父亲后有可能一直向上走，也可能向上走几步之后向下走反而经过了节点`i`(因为事先并不知道不经过`i`)。那么如何求这个向上走能到达的最大距离呢？

设`i` 的父亲为`j` ，`upMax[i]`可以由`downMax[j]`和`upMax[j]`转移而来。

$upMax[i] = dis[i][j]+max(upMax[j],downMax[j]) $ 。

但是呢，如果`downMax[j]`经过了节点`i`，那么以上式子就不成立。显然就要走第二大的边。因此需要一个$maxSon[j]$来标示$fa[i]=j$ 的子树最大值要经过哪个儿子。

考虑以上两点，有状态转移方程：
$$
upMax[i] = \begin{cases} 
dis[i][j] + max(upMax[j],downMax[j])\quad,maxSon[j]\neq i\\
dis[i][j] + max(upMax[j],downSec[j])\quad,maxSon[j]=i\\
\end{cases}
$$



##  证明

最优子结构性质

$maxDis[i] = max(upMax[i],downMax[i])$，

反证法：

若$downMax[i] ≠ max\{Dis[i][j] | j \in sonTree(i) \}$，那么存在$Dis[i][k]>downMax[i]$，使得$maxDis[i]' = Dis[i][k] > maxDis[i]=downMax[i]$。与$maxDis[i]$为最远距离矛盾，因此最优子结构性质得证。

对于其他情况同理。



## 代码

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 1e4+10;
struct edge{
    int to;
    int next;
    int w;
    edge(int t=-1,int n=-1,int _w=0){
        to = t;
        next = n;
        w = _w;
    }
}e[maxn<<1];
int cnt,head[maxn];

void addEdge(int u,int v,int w){
    e[cnt] = edge(v,head[u],w);
    head[u] = cnt++;
}
int maxSon[maxn],upMax[maxn],downMax[maxn],downSec[maxn];
int n;

void init(){
        cnt = 0;
        memset(maxSon,-1,sizeof maxSon);
        memset(upMax,-1,sizeof upMax);
        memset(downMax,-1, sizeof downMax);
        memset(downSec,-1 ,sizeof downSec);
        memset(head,-1,sizeof head);
}

int dfs1(int u,int fa){
    if(downMax[u]>=0) return downMax[u];
    downMax[u] = upMax[u] = downSec[u] = maxSon[u] = 0;
    
    for(int i = head[u];~i;i = e[i].next){
        int v = e[i].to;
        if(v==fa) continue;
        if(downMax[u]<dfs1(v,u)+e[i].w){
            maxSon[u] = v;
            downSec[u] = max(downSec[u],downMax[u]);
            downMax[u] = dfs1(v,u) + e[i].w;
        }
        else if(downSec[u]<dfs1(v,u)+e[i].w)
            downSec[u] = max(downSec[u],dfs1(v,u)+e[i].w);
    }
    return downMax[u];
}
void dfs2(int u,int fa){
    for(int i=head[u];~i;i=e[i].next){
        int v = e[i].to;
        if(v==fa) continue;
        if(v==maxSon[u]) upMax[v] = e[i].w+max(upMax[u],downSec[u]);
        else upMax[v] = e[i].w+max(upMax[u],downMax[u]);
        dfs2(v,u);
    }
}

int main(){
    while (~scanf("%d",&n))
    {
        init();
        for(int i=2;i<=n;i++){
            int v,w;
            scanf("%d%d",&v,&w);
            addEdge(i,v,w);
            addEdge(v,i,w);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i = 1;i<=n;i++)
            printf("%d\n",max(upMax[i],downMax[i]));
    }
    return 0;
}
```



## 解释

采用链式前向星的数据结构存图，可以节省空间，加快速度。

对于$downSec$，即向下走的第二远距离，可以在求向下走的最远距离的时候求出来，当`i`到`i`的子树的距离小于之前的最大值的时候，与次大值比较一下，如果大于次大值的时候更新一下就好了。

对于dfs2则是实现了上面的状态转移方程。



## 复杂度分析

由于每个节点都只访问了一遍，因此时间复杂度是$O(n)$的。

