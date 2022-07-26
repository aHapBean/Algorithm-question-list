//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using pii = pair<int ,int>;
const int maxn = 1e4 + 5;
const int inf = 1e8;
int n,a[maxn],cnt[maxn << 1];
vector<int> ans;
bool check(int ind){
	a[ind] = -a[ind];
	if(cnt[a[ind]]){
		cnt[a[ind]]--;
		return true;
	} else if(cnt[0]) {
		cnt[0]--;
		//debug(cnt[0]);
		ans.push_back(a[ind]);
		return true;
	} else return false;
	return false;
}
int main(){
	cin >> n;
	bool ok = true;
	for(int i = 0; i < n; ++i){
		scanf("%d",a + i);
		if(a[i] < 0)ok = check(i);
		else cnt[a[i]]++;
		//debug(cnt[a[i]]);
		if(!ok)break;
	}
	if(ok){
		printf("Yes\n");
		for(int i = 0; i < ans.size(); ++i){
			printf("%d ",ans[i]);
			//debug(cnt[0]);
		}
		//debug(cnt[0]);
		if(cnt[0]){
			for(int i = 0; i < cnt[0]; ++i){
				cout << "1" << " ";
			}
		}
	} else printf("No");
	return 0;
}
