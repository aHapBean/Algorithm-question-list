//#pragama optimize(2)
#define fi freopen("in","r",stdin);cout << "delete the freopen !!!!!"
#define derr(...) fprintf(stderr, __VA_AROS__)
#define debug(x) cout << "here" << x << "\n"
#define GFOR(i,u) for(int (i) = fst[u]; (i); (i) = nxt[(i)]) 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn],cnt[maxn],k,n;
int st[maxn],tail = -1,head = 0;
ll ans;
ll sum;
int main(){
	//fi;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)scanf("%d",a + i);
	for(int i = 1; i <= n; ++i){
		st[++tail] = i;
		cnt[a[st[tail]]]++;
		if(cnt[a[st[tail]]] == 2)sum++;
		if(sum > k){
			while(head <= tail && sum > k){
				if(cnt[a[st[head]]] >= 2){
					cnt[a[st[head++]]]--;
					if(cnt[a[st[head - 1]]] < 2)sum--;
				} else cnt[a[st[head++]]]--;
			}
		}
		ans += (st[tail] - st[head] + 1);
	}
	cout << ans << endl;
	return 0;
}
