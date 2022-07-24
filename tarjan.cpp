1.tarjan
const int N = 1e5 + 5;
int dfn[N],low[N],tnt,s[N],in_st[N],tp;
int col[N],co;
int sz[N];

// O(n + m)

// 接下来假如要缩点  SPFA 不需要去重

void tarjan(int u){
    low[u] = dfn[u] = ++tnt;
    s[++tp] = u;
    in_st[u] = 1;
    for(int i = fst[u]; i; i = nxt[i]){
        int v = side[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if(vis[v])low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u]){
        ++sc;
        while(s[tp] != u){
            scc[s[tp]] = sc;
            sz[sc]++;
            vis[s[tp]] = 0;
            --tp;
        }
        scc[s[tp]] = sc;
            sz[sc]++;
            vis[s[tp]] = 0;
            --tp;
    }
}

两次dfs求强连通分量
void dfs1(int u){
    vis[u] = 1;
    for(int i = )
        if(!vis[v])dfs1(v);
    s.push_back(u);
}

void dfs2(int u){
    color[u] = sccCnt;
    for(int i = ){
        if(!color[v])dfs2(v);
    }
}
void kosaraju(){
    sccCnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i])dfs1(i);
    }
    for(Int i = 1; i >= 1; --i){
        if(!color[s[i]]){
            ++sccCnt;
            dfs2(s[i]);
        }
    }
}

2.割点和桥
void tarjan(int u,int fa){
    vis[u] = 1;
    low[u] = num[u] = ++cnt;
    int tnt = 0;
    for(int i = ){
        if(!vis[u]){
            tnt++;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(fa != u && low[v] >= num[u] && !flag[u])
        }
    }
}
void tarjan(int u,int fa){
    low[u] = dfn[u] = ++cnt;
    int tot = 0;
    for(int ){
        int v = side[i].v;
        if(!dfn[v]){
            tarjan(v,,0);//0 ????
            low[u] = min(low[v],low[u]);
            tot += (low[v] >= dfn[u]);
        } else low[u] = min(low[u],dfn[v]);
    }
    if(tot > fa)iscut[u]++;
}

桥
void tarjan(int u,int fa){
    f[u] = fa;
    low[u] = dfn[u] = ++cnt;
    for(){
        int v
        if(!dfn[v]){
            tarjan(v,u);
            low[u] = min();
            if(low[v] > dfn[u]){
                isbridge[v] = 1;++cnt_bridge;
            } else if(dfn[v] < dfn[u] && v != fa)low[u] = min(low,dfn);
        }
    }
}

//成功染色，这是求强连通分量
void tarjan(int u){
    low[u] = dfn[u] = ++cnt;
    vis[u] = 1;st[++tail] = u;;
    for(Int){
        int v
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low,low)
        } else if(vis[u]) low[u] = min(low,dfn)
    }
    if(low[u] == dfn[u]){
        ++color;
        while(st[tail] != u){
            col[st[tail]] = color;
            vis[st[tail]] = 0;
            --tail;sz[color]++;
        }
        col[st[tail]] = color;
        vis[st[tail]] = 0;
        --tail;sz[color]++;
    }
}