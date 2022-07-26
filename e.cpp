//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using pii = pair<int ,int>;
const int maxn = 1e4 + 5;
const int inf = 1e8;
int n,a[maxn];
vector<int> ans;
bool check(int ind){
	if(ind == 0)return false;
	a[ind] = -a[ind];
	for(int i = 0; i <= ind - 1; ++i){
		if(a[i] == a[ind]){
			a[i] = a[ind] = inf;
			return true;
		}
	}
	for(int i = 0; i <= ind - 1; ++i){
		if(a[i] == 0){
			ans.push_back(a[ind]);
			a[i] = a[ind] = inf;
			return true;
		}
	}
	return false;
}
int main(){
	cin >> n;
	bool ok = true;
	for(int i = 0; i < n; ++i){
		scanf("%d",a + i);
		if(a[i] < 0)ok = check(i);
		if(!ok)break;
	}
	if(ok){
		printf("Yes\n");
		for(int i = 0; i < ans.size(); ++i){
			printf("%d ",ans[i]);
		}
	} else printf("No\n");
	return 0;
}
