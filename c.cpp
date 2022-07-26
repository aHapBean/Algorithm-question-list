//#pragama optimize(2)
#define fi cout << "freopen here,del !" << endl;freopen("in","r",stdin);
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxm = 1e5 + 5;
int n,m,fst[maxm],nxt[maxm],cnt,tmp,dfn[maxm],tnt;
struct edge{
	int u,v,flag;
}side[maxm],sider[maxm];
int flag[maxm];
int fr[maxm],nxr[maxm],rcnt;
int t; 
int vis[maxm];
// there must be a out and a in
// but may not exist 2 out
void init(){
	cnt = 0;rcnt = 0;tnt = 0;
	memset(fst,0,sizeof(fst));
	memset(nxt,0,sizeof(nxt));
	memset(nxr,0,sizeof(nxr));
	memset(fr,0,sizeof(fr));
	memset(flag,0,sizeof(flag));
	memset(dfn,0,sizeof(dfn));
	memset(vis,0,sizeof(vis));
}
void add(int u,int v){
	side[++cnt] = {u,v,0};
	nxt[cnt] = fst[u];
	fst[u] = cnt;
}
void addr(int u,int v){
	sider[++rcnt] = {u,v,0};
	nxr[rcnt] = fr[u];
	fr[u] = rcnt;
}
void dfs(int u){
	dfn[u] = ++tnt;
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(!dfn[v]){
			flag[i] = 1;
			dfs(v);
		}
	}
}
void dfs2(int u){
	vis[u] = 1;
	for(int i = fr[u]; i; i = nxr[i]){
		int v = sider[i].v;
		if(!vis[v]){
			flag[i] = 1;
			dfs2(v);
		}
	}
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		for(int i = 0; i < m; ++i){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);addr(v,u);
		}
		dfs(1);// 1 can go to any
		dfs2(1);// any can go to 1 !!!
		int ccnt = m - 2 * n;
		for(int i = 1; i <= cnt; ++i){
			if(!flag[i]){
				--ccnt;
				printf("%d %d\n",side[i].u,side[i].v);
			}
			if(ccnt == 0)break;
		}
	}

	return 0;
}
