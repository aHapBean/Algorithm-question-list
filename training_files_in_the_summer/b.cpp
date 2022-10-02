//#pragama optimize(2)
#define fi freopen("in.txt","r",stdin)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 5;
int t,n,m,fst[maxn],nxt[maxn << 1],tnt;
struct edge{
	int u,v;
}side[maxn << 1];
// find the scc !
int dfn[maxn],st[maxn],tail = -1,vis[maxn],low[maxn],col[maxn],sc,cnt;
void add(int u,int v){
	side[++tnt] = {u,v};
	nxt[tnt] = fst[u];
	fst[u] = tnt;
}

void tarjan(int u){
	low[u] = dfn[u] = ++cnt;
	vis[u] = 1;st[++tail] = u;
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		} else if(vis[v])low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){
		//debug(sc);
		++sc;
		while(st[tail] != u){
			col[st[tail]] = sc;
			vis[st[tail]] = 0;
			--tail;
		}
		col[st[tail]] = sc;
		vis[st[tail]] = 0;
		--tail;
	}
}
int main(){
	//fi;
	cin >> t;
	debug(t);
	while(t--){
		scanf("%d%d",&n,&m);
		int u,v;
		for(int i = 0; i < m; ++i){
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		for(int i = 1; i <= n; ++i)
			if(!dfn[i])tarjan(i);
		//for(int i = 1; i <= n; ++i)cout << col[i] << "col" << endl;
		//cout << sc;
	}
	return 0;
}
