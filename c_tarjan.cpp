//dfs + ancestor edge
// the final tarjan version

//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(...) fprintf(stderr, __VA_ARGS__)
// there must exist a high back edge !!
// or this vertice can't reach the any other vertice !
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 5;
struct edge{
	int u,v,flag;
}side[maxn];
int n,m,t,fst[maxn],nxt[maxn << 1],rec[maxn << 1],cnt,dfn[maxn],low[maxn];
int tnt;
void add(int u,int v){
	side[++cnt] = {u,v,0};nxt[cnt] = fst[u];fst[u] = cnt;
}
void init(){
	memset(fst,0,sizeof(fst));
	memset(dfn,0,sizeof(dfn));
	cnt = tnt = 0;
}
void tarjan(int u){
	dfn[u] = low[u] = ++tnt;
	int rec = 0;
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(!dfn[v]){
			side[i].flag = 1;
			tarjan(v);
			low[u] = min(low[u],low[v]);
		} else if(dfn[v] < low[u]){// get to the lowest ! 
			rec = i;// recursion understand !
			low[u] = dfn[v];
			// the meaning of dfn !
		}
	}
	side[rec].flag = 1;
}
int main(){
	cin >> t;
	while(t--) {
		init();
		cin >> n >> m;
		for(int i = 0; i < m; ++i){
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);
		}
		tarjan(1);
		int count = m - 2 * n;
		for(int i = 1; i <= cnt; ++i){
			if(side[i].flag)continue;
			printf("%d %d\n",side[i].u,side[i].v);
			count--;
			if(count == 0)break;
		}
	}
	return 0;
}
