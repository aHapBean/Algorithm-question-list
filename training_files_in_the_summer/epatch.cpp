//#pragama optimize(2)
#define fi freopen("in","r",stdin);cout << "delete the freopen !!!!!"
#define derr(...) fprintf(stderr, __VA_AROS__)
#define debug(x) cout << "here" << x << "\n"
#define GFOR(i,u) for(int (i) = fst[u]; (i); (i) = nxt[(i)]) 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 5e2 + 5;
int n,m,vis[maxn][maxn],win[maxn],cnt[maxn];
ll grad[maxn];
string to;
int a,b,x,y;
int ccnt;
int main(){
	//fi;
	cin >> n >> m;
	//ll cnt = 0;
	for(int i = 0; i < m; ++i){
		scanf("%d",&a);cin >> to;
		bool ok = false;
		ll x = 0;y = 0;
		for(int i = 0; i < to.size(); ++i){
			if(ok){
				y = y * 10 + to[i] - '0';
			} else if(to[i] != ':'){
				x = x * 10 + to[i] - '0';
			} else ok = true;
		}
		scanf("%d",&b);

		vis[a][b] = vis[b][a] = 1;
		grad[a] += x;
		grad[b] += y;
		win[a] += (x > y);
		win[b] += (x < y);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(vis[i][j] || i == j)continue;
			vis[i][j] = vis[j][i] = 1;
			if(i == 1){
				win[i]++;grad[i] += 1e9;
			} else {
				ccnt++;
				cnt[i]++;cnt[j]++;
			}
		}
	}
	ll res = 0;
	for(int i = 2; i <= n; ++i){
		if(grad[i] + win[1] - win[i] > grad[1]){
			res += min(cnt[i],win[1] - win[i] - 1);
		} else res += min(cnt[i],win[1] - win[i]);
	}
	if(res <= ccnt){
		printf("NO");
	} else printf("YES");
	return 0;
}
/*
4 3
1 80:91 2
2 89:101 3
3 100:98 4

4 5
1 99:101 2
1 80:91 3
1 120:83 4
2 103:70 5
3 98:97 4
*/
