//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll maxn = 1e5 + 5;
ll n,q,depth[maxn],val[maxn],f[maxn][22];
struct edge{
	ll u,v;
}side[maxn << 1];
ll fst[maxn],nxt[maxn << 1],cnt;
void add(ll u,ll v){
	side[++cnt] = {u,v};
	nxt[cnt] = fst[u];
	fst[u] = cnt;
}
struct query{
	ll u,v,ind,len,fa;
}qq[maxn];
void dfs(ll u,ll fa){
	f[u][0] = fa;depth[u] = depth[fa] + 1;
	for(ll i = 1; i < 22; ++i)f[u][i] = f[f[u][i - 1]][i - 1];
	for(ll i = fst[u]; i; i = nxt[i]){
		ll v = side[i].v;
		if(v == fa)continue;
		dfs(v,u);
	}
}
ll lca(ll u,ll v){
	for(ll i = 21; i >= 0; --i){
		if(depth[f[u][i]] >= depth[v])u = f[u][i];
	}
	if(u == v)return u;
	for(ll i = 21; i >= 0; --i){
		if(f[u][i] != f[v][i]){
			u = f[u][i];v = f[v][i];
		}
	}
	return f[u][0];
}
ll ask(ll u,ll v,ll fa){
	ll ans = 0;
	while(u != fa){
		ans += val[u];u = f[u][0];
	}
	while(v != fa){
		ans += val[v];v = f[v][0];
	}
	ans += val[fa];
	return ans == 0 /*(|| (ans < 0 && !(abs(ans) & 1))*/;//0 or - even
}

int main(){
	fi;
	cin >> n >> q;
	debug(n);
	debug(q);
	for(ll i = 0; i < n - 1; ++i){
		ll u,v;scanf("%lld%lld",&u,&v);
		add(u,v);add(v,u);//debug(u);
	}
	dfs(1,0);
	bool ok = true;
	// sort !
	for(ll i = 0; i < q; ++i){
		ll u,v;scanf("%lld%lld",&u,&v);
		if(depth[u] < depth[v])swap(u,v);
		ll fa = lca(u,v);
		//debug(fa);
		ll len = depth[u] + depth[v] - 2 * depth[fa] + 1;
		qq[i] = {u,v,i,len,fa};
	}
	sort(qq,qq + q,[](query a,query b){
		return a.len < b.len;
	});
	/*
6 5 
1 2
2 3
3 4
5 6
5 2
2 1
6 6
1 4
3 4
4 1
	*/
	
	for(ll i = 0; i < q; ++i){
		//u down v up !
		ll u = qq[i].u,v = qq[i].v,fa = qq[i].fa;
		if(depth[u] < depth[v])swap(u,v);
		/*if(u != v && (val[u] < 0 || val[v] > 0)){
			ok = false;break;
		} else*/ if(u == v)continue;
		  else  {
			ok = ask(u,v,fa);
			//debug(fa);
			if(!ok)break;
			else {
				val[u]++;val[v]++;val[fa] -= 2;//debug(val[fa]);
			}
		}
	}
	if(ok)printf("Yes");
	else printf("No");
	return 0;
}
