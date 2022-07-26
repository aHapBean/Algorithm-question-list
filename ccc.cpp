//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define derr(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 2e5 +5;
const double inf = 1e8 + 9;
struct edge{
	int u,v;
}side[maxn];
int fst[maxn],k,cnt,nxt[maxn],n,uu[maxn],vv[maxn],flag[maxn],sflag[maxn],ans[maxn];
bool ok = true;
struct node{
	double val,span;
}pt[maxn];
void add(int u,int v){
	side[++cnt] = {u,v};
	nxt[cnt] = fst[u];
	fst[u] = cnt;
}
void pre(int u,int f){
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(v == f)continue;
		pre(v,u);
		if(flag[v])flag[u] = 1,sflag[i] = 1;
		else flag[u] = max(flag[u],flag[v]);//sflag = 0 !
	}
}

node merge(node a,node b){
	double aa = a.val - a.span,aaa = a.val + a.span;
	double bb = b.val - b.span,bbb = b.val + b.span;
	double x = max(aa,bb),y = min(aaa,bbb);
	if(x > y)return (node){0,-1};
	return (node){(x + y) / 2,(y - x) / 2};
}
node dfs(int u,int f){
	node cur = (pt[f].span == inf) ? pt[f] : (node){pt[f].val,pt[f].span + 1};
	cur = merge(pt[u],cur);
	for(int i = fst[u]; i; i = nxt[i]){
		if(sflag[i]){
			int v = side[i].v;
			//derr("%d %d\n",u,v);
			if(v == f)continue;
			//derr("merge %d %d\n",u,v);
			//derr("info: %lf %lf %lf %lf\n",cur.val,cur.span,pt[v].val,pt[v].span);
			node res = dfs(v,u);
			node tmp = {res.val,res.span + 1};
			//derr("tmp info: %lf %lf\n",tmp.val,tmp.span);
			cur = merge(cur,tmp);
			//derr("after info: %lf %lf\n",cur.val,cur.span);
		}
	}
	pt[u] = cur;
	return pt[u];
}
int vis[maxn];
void pdfs(int u,int f){
	vis[u] = 1;
	node cur = (pt[f].span == inf) ? pt[f] : (node){pt[f].val,pt[f].span + 1};
	cur = merge(pt[u],cur);
	for(int i = fst[u]; i; i = nxt[i]){
		if(!sflag[i]){
			int v = side[i].v;
			if(v == f || vis[v])continue;
			vis[v] = 1;
			pdfs(v,u);
		}
	}
	pt[u] = cur;// only pushdown ! ! !
}
int get(int u,int condi,int f){
	double a = pt[u].val - pt[u].span,b = pt[u].val + pt[u].span;
	if(pt[u].span == -1){
		ok = false;
		return a;
	}
	int aa = a,bb = b;
	if(f == 0){
		return aa;
	}
	if(bb - aa == 2){
		if(abs(aa - condi) == 1)return aa;
		else if(abs(bb - condi) == 1)return bb;
	} else {
		for(int i = aa; i <= bb; ++i){
			if(abs(i - condi) == 1)return i;
		}
	}
	ok = false;
	return aa;
}
void dfs_get(int u,int f){
	if(pt[u].span == 0)ans[u] = pt[u].val;
	else ans[u] = get(u,ans[f],f);
	//derr("ans :%d %d\n",u,ans[u]);
	for(int i = fst[u]; i; i = nxt[i]){
		int v = side[i].v;
		if(v == f)continue;
		dfs_get(v,u);
	}
}
int main(){
	//fi;
	int u,v,a,p;
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		scanf("%d%d",&u,&v);
		uu[i] = u;vv[i] = v;
	}
	for(int i = 0; i <= n; ++i){
		pt[i].span = inf;
	}
	cin >> k;
	for(int i = 0; i < k; ++i){
		scanf("%d%d",&a,&p);
		pt[a].val = double(p);
		pt[a].span = 0;flag[a] = 1;
	}
	for(int i = 0; i < n - 1; ++i){
		add(uu[i],vv[i]);add(vv[i],uu[i]);
	}
	pre(1,0);
	dfs(1,0);
	for(int i = 1; i <= n; ++i)
		if(!vis[i])pdfs(i,0);
	
	dfs_get(1,0);
	if(ok == false){
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i = 1; i <= n; ++i)printf("%d\n",ans[i]);
	return 0;
}
