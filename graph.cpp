---1.最短路

仅正权图
void dijkstra(){
    for(int i = 1; i <= n; ++i)dis[i] = inf;
    dis[s] = 0;pq.push(node{s,0});
    while(!pq.empty()){
        int u = pq.top().ind;pq.pop();
        if(vis[u])continue;//最小路径一旦确定就 √ （对正权图
        // 开始认为 0 距离 还没有被确定为最小路径
        vis[u] = 1;
        for(int i = fst[u]; i; i = nxt[i]){
            int v = side[i].v,w = side[i].w;
            if(dis[v] > dis[u] + w){
                if(vis[v])cout << "hack" << endl; // no vis[v] will get here  
                dis[v] = dis[u] + w;
                pq.push(node{v,dis[v]});
            }
        }
    }
}

SPFA(),可有负环
判断负环只需引入 cnt 数组， dis[v] > dis[u] + w 时 cnt[v] = cnt[u] + 1;
当 cnt[v] >= n 代表有环
int inst[maxn],st[maxn << 4],head = 0,tail = -1;
void SPFA(){
    for(int i = 1; i <= n; ++i)dis[i] = inf;
    dis[s] = 0;inst[s] = 1;st[++tail] = s;
    while(head <= tail) {
        int u = st[head++];
        inst[u] = 0;// here !!
        for(int i = fst[u]; i; i = nxt[i]){
            int v = side[i].v,w = side[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!inst[v])inst[v] = 1,st[++tail] = v;
            }
        }
    }
}

多源最短路
建图：
(1) if(i == j)dis[i][j] = 0;
    else dis[i][j] = inf;
(2) if(dis[i][j] > w){
        dis[u][v] = dis[v][u] = w;
    }
void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j  = 1; j <= n; ++j){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[k][j];// 是 j 的前一顶点的顶点号
                    // j 的 ！！
                }
            }
        }
    }
}


---2.连通性相关

1.找强连通分量 -> 可以结合缩点等等

    (1)tarjan 
    连通分量，割点和桥

    void tarjan(int u){
        dfn[u] = low[u] = ++tnt;
        st[++tail] = u;inst[u] = 1;
        for(int i = fst[u]; i; i = nxt[i]){
            int v = side[i].v;
            if(!dfn[v]){
                tarjan(v);
                low[u] = min(low[v],low[u]);
            } else if(inst[v])  //here ！
                low[u] = min(low[u],dfn[v]);//还是未归类的点
        }
        if(low[u] == dfn[v]){
            ++scc;
            while(st[tail + 1] != u){//这里可以两种写法
                col[st[tail]] = scc;
                inst[st[tail]] = 0;
                sz[scc]++;
                --tail;
            }
        }
    }

    (2)two dfs (建反图,dfn序大的开始
    从强连通分量定义理解

    //dfs1 要几次 ???
    //看题目条件 or ？？？
    void dfs1(int u){

    }
    void dfs2(int v){

    }


2.找割点和桥 -> tarjan
OJ 20034

    in main the code is :
    for(int i = 1;i <= m; ++i)
        if(!dfn[i])tarjan(i,1);

    void tarjan(int u,int fa){
        dfn[u] = low[u] = ++tnt;
        //inst[u] = 1;st[++tail] = u;
        for(int i = fst[u]; i; i = nxt[i]){
            int v = side[i].v;
            if(!dfn[v]){
                tarjan(v,0);    // 0 or u ?  u ??
                low[u] = min(low[u],low[v]);
                tot += (low[v] >= low[u]);
            } else low[u] = min(low[u],dfn[v]);// if ??
        }
        if(tot > fa)iscur[u]++;//rt is 0 特判
        //在有些里面 root 是这个标记
    }

    patch here : the code needs father like u ??

    别人找割点代码:
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            root=i;
            rs=0;
            Tarjan(i,i);
            if(rs>=2)
                cut[i]=true;
        }
    }
    void Tarjan(int u,int f){
        int v;
        dfn[u]=low[u]=++Time;
        for(int i=h[u];i!=-1;i=edge[i].nxt){
            v=edge[i].to;
            if(!dfn[v]){
                Tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u]){
                    if(u!=root){
                        cut[u]=true;
                    }
                    else{
                        rs++;
                    }
                }
            }
            else{
                if(v!=f)
                    low[u]=min(low[u],dfn[v]);
            }
        }
    }


    找桥
    void tarjan(int u,int fa){
        f[u] = fa;
        low[u] = dfn[u] = ++tnt;
        for(int i = fst[u]; i; i = nxt[i]){
            int v = side[i].v;
            if(!dfn[v]){
                tarjan(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v] > dfn[u]){//  ”回不来“
                    isbrige[i] = 1;++cnt_bridge;
                }
            } else if(dfn[v] < dfn[u] && v != fa){
                low[u] = min(low[u],dfn[v]);
            }
        }
    }