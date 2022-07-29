//#pragama optimize(2)
#define fi freopen("in","r",stdin);cout << "delete the freopen !!!!!"
#define derr(...) fprintf(stderr, __VA_AROS__)
#define debug(x) cout << "here" << x << "\n"
#define GFOR(i,u) for(int (i) = fst[u]; (i); (i) = nxt[(i)]) 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxm = 6e5 + 5;
const int maxn = 3e5 + 5;
struct edge{
	int u,v,w;
}side[maxm],pside[maxm];
int vis[maxn],n,m,k,cnt,pcnt,fst[maxn],nxt[maxm],f[maxn];
void add(int u,int v,int w){
	side[++cnt] = {u,v,w};
	nxt[cnt] = fst[u];
	fst[u] = cnt;
}
void padd(int u,int v,int w){
	pside[++pcnt] = {u,v,w};
}

void dfs(int u,int fa){
	vis[u] = 1;
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(v == fa)continue;
		if(vis[v])continue;
		dfs(v,u);
	}
}
int sum = 0;
ll ans = 0;
int find(int x){
	if(f[x] == x)return x;
	return f[x] = find(f[x]);
}
void cope(int u,int v,int w){
	int a = find(u),b = find(v);
	if(a == b)return ;
	f[a] = b;
	++sum;
	ans += w;
}
int main(){
	//fi;
	cin >> n >> m >> k;
	for(int i = 0; i <= n + m; ++i)f[i] = i;
	for(int i = 0; i < k; ++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v + n,w);add(v + n,u,w);
		padd(u,v + n,w);
	}
	dfs(1,0);
	bool ok = true;
	for(int i = 1; i <= n + m; ++i)
		if(!vis[i])ok = false;
	if(!ok){
		printf("cbddl");return 0;
	}
	sort(pside + 1,pside + pcnt + 1,[](edge a,edge b){
		return a.w < b.w;
	});

	for(int i = 1; i <= pcnt; ++i){
		int u = pside[i].u,v = pside[i].v,w = pside[i].w;
		cope(u,v,w);
		if(sum == n + m - 1)break;
	}
	cout << ans << endl;
	return 0;
}
