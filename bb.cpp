//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define derr(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 5;
int n,t,a[maxn],ans[maxn],st[maxn],head = 0,tail = -1,nil = -1;
int mxx[maxn];
int main(){
	int mx = 0;
	cin >> n >> t;
	for(int i = 0; i < n; ++i){
		scanf("%d",a + i);
	}
	for(int i = n - 1; i >= 0; --i){
		mxx[i] = max(a[i],mxx[i + 1]);
	}
	for(int i = 0; i < n; ++i){
		if(mxx[i + 1] - a[i] > mx){
			nil = -1;
			ans[++nil] = i;
			mx = mxx[i + 1] - a[i];
		} else if(mx == mxx[i + 1] - a[i]){
			ans[++nil] = i;
		}
	}
	cout << nil + 1;
	return 0;
}
