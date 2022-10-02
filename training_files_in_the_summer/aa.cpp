//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define derr(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 5;
char a[maxn];
int sum,rec[maxn],tail = -1;
int main(){
	scanf("%s",a);
	int n = strlen(a);
	for(int i = 0; i < n; ++i){
		if(!i){
			if(a[i] == 'B')rec[++tail] = 0;
			else rec[++tail] = 1;
			++sum;
		} else {
			if(a[i] == 'B'){
				if(rec[tail] == 0)continue;
				else rec[++tail] = 0,++sum;
			} else {
				if(rec[tail] == 1)continue;
				else rec[++tail] = 1,++sum;
			}
		}
	}
	cout << sum - 1;
	return 0;
}
