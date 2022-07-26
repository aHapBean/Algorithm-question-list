//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define derr(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = unsigned long long;
using namespace std;
const int maxn = 1e5 + 5;
ll n,e,t,x[maxn];
ll f[maxn];
vector<ll> rec[maxn];
ll sum[maxn];
ll post_ind[maxn];
ll tab[maxn];
int find(int x){
	if(f[x] == x)return f[x];
	return f[x] = find(f[x]);
}
ll solve(ll ind,ll val){
	ll ans = 2 * sum[ind];
	ll tmp = 2 * sum[ind];
	bool ok = (t <= ans);
	if(!ok)ans += (t - tmp);
	
	for(int i = 0; i < rec[ind].size(); ++i){
		if(ok){
			ans += rec[ind][i];
		} else {
			ans += rec[ind][i];
		}
	}
	return ans;
}
int main(){
	//fi;
	cin >> n >> e >> t;
	int pre = 0;
	for(int i = 0; i < maxn; ++i)f[i] = i;
	for(int i = 0; i < n; ++i){
		scanf("%llu",x + i);
	}
	//sort(x,x + n);
	int len = n;
	//for(int i = 0; i < n; ++i){
	//	tab[i] = lower_bound(x,x + n,x[i]);
	//}
	for(int i = 0; i < n; ++i){
		if(!i){
			rec[i].push_back(0);
			post_ind[i] = i;
			pre = i;
		} else if(x[i] - x[pre] <= t){
			int fa = find(pre);
			f[i] = fa;
			rec[fa].push_back(x[i] - x[pre]);
			sum[fa] += x[i] - x[pre];
			post_ind[fa] = i;
			pre = i;
		} else {
			rec[i].push_back(0);//new !! 
			post_ind[i] = i;
			pre = i;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans += solve(i,x[i]);
		//derr("%d %d\n",x[post_ind[x[i]] + 1] , x[post_ind[x[i]]]);
		if(post_ind[i] + 1 < n)ans += x[post_ind[i] + 1] - x[post_ind[i]];
		i = post_ind[i];// !!
	}
	ans += (e - x[n - 1] + 1);
	cout << ans;
	return 0;
}
