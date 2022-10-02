//#pragama optimize(2)
#define fi freopen("in","r",stdin);cout << "delete the freopen !!!!!"
#define derr(...) fprintf(stderr, __VA_AROS__)
#define debug(x) cout << "here" << x << "\n"
#define GFOR(i,u) for(ll (i) = fst[u]; (i); (i) = nxt[(i)]) 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll maxn = 2e5 + 5;
ll n,a[maxn],b[maxn],t[maxn << 2];
ll res = 0,ans = 0,cur = 0;
void build(ll rt,ll l,ll r){
	if(l == r){
		t[rt] = l;return ;
	}
	ll m = l + r >> 1;
	build(rt << 1,l,m);
	build(rt << 1 | 1,m + 1,r);
	if(b[t[rt << 1]] >= b[t[rt << 1 | 1]])t[rt] = t[rt << 1];
	else t[rt] = t[rt << 1 | 1];
}
void del(ll rt,ll l,ll r,ll x){
	if(l == r){
		t[rt] = 0;return ;
	}
	ll m = l + r >> 1;
	if(x <= m)del(rt << 1,l,m,x);
	else del(rt << 1 | 1,m + 1,r,x);
	if(b[t[rt << 1]] >= b[t[rt << 1 | 1]])t[rt] = t[rt << 1];
	else t[rt] = t[rt << 1 | 1];
}
ll ask(ll rt,ll l,ll r,ll x,ll y){
	if(x <= l && r <= y){
		return t[rt];
	}
	ll m = l + r >> 1;
	ll tmp = -1;
	if(x <= m)tmp = ask(rt << 1,l,m,x,y);
	if(y > m){
		if(tmp == -1)return ask(rt << 1 | 1,m + 1,r,x,y);
		ll tp = ask(rt << 1 | 1,m + 1,r,x,y);
		if(b[tmp] >= b[tp])return tmp;//  ???? 
		return tp;
	}
	return tmp;
}
int main(){
	//fi;
	cin >> n;
	for(ll i = 1; i <= n; ++i)scanf("%lld",a + i);
	for(ll i = 1; i <= n; ++i)scanf("%lld",b + i);
	build(1,1,n);
	b[0] = 0;
	for(ll i = 1; i <= n; ++i){
		cur += a[i];
		if(cur < b[i] && i == 1)del(1,1,n,i);
		else if(cur < b[i]){
			ll tmp = ask(1,1,n,1,i - 1);
			if(tmp == -1)continue;
			if(tmp == 0 || cur + b[tmp] < b[i] || b[tmp] < b[i]){
				del(1,1,n,i);
				continue;
			} else {
				cur += b[tmp];
				del(1,1,n,tmp);
				cur -= b[i];
			}
		} else if(cur >= b[i]){
			cur -= b[i];
			res++;
		}
	}
	cout << res;
	return 0;
}
