//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll w,h,a[3];
bool check(ll a,ll b){
	if(a > b){
		ll tmp = a;
		a = b;
		b = tmp;
	}
	return (a <= w) && (b <= h);
}
int main(){
	cin >> a[0] >> a[1] >> a[2];
	cin >> w >> h;
	if(w > h){
		ll tmp = w;
		w = h;h = tmp;
	}
	bool ok = false;
	sort(a,a + 3);
	do{
		ll l = a[0],w = a[1],h = a[2];
		ok = check((l + h) * 2,w + 2 * h);if(ok)break;
		ok = check((l + h) * 2,w + 2 * l);if(ok)break;
		ok = check((l + h) * 2,w + h + l);if(ok)break;
		ok = check(2 * l + h + w,w + 2 * h);if(ok)break;
		ok = check(l + h + w,2 * w + h + l);if(ok)break;
		ok = check(3 * w + h + l,l + h);if(ok)break;//here
		ok = check(2 * l + w,2 * h + l + w);if(ok)break;
	}while(!ok && next_permutation(a,a + 3));
	if(ok)printf("Yes");
	else printf("No");
	return 0;
}
