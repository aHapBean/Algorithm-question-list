//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define derr(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 2e4 + 5;
int ut = 2e4 + 5;
int a[maxn],b[maxn],n,p[maxn];
int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		a[i] = i * ut;
		b[i] = (n - i + 1) * ut;
	}
	for(int i = 0; i < n; ++i)scanf("%d",p + i);
	int span = 0;
	for(int i = n - 1; i >= 0; --i){
		b[p[i]] -= span;
		span++;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ",a[i]);
	} puts("");
	for(int i = 1; i <= n; ++i){
		printf("%d ",b[i]);
	} puts("");
	return 0;
}
