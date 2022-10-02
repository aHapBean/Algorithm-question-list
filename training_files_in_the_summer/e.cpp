//#pragama optimize(2)
#define fi freopen("in","r",stdin);cout << "delete the freopen !!!!!"
#define derr(...) fprintf(stderr, __VA_AROS__)
#define debug(x) cout << "here" << x << "\n"
#define GFOR(i,u) for(int (i) = fst[u]; (i); (i) = nxt[(i)]) 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 10;
struct node{
	int val;
	node *nxt;
	node(int x){
		val = x;nxt = NULL;
	}
};
node *head = NULL;
int a[maxn],n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		a[i] = i;
	}
	bool flag = true;
	node *h1 = new node(1),*h2 = new node(2);
	node *hh1 = h1,*hh2 = h2;
	for(int i = 1; i <= n / 2; ++i){
		if(flag){
			h2->nxt = new node(i * 2 + 1);
			h1->nxt = new node(i * 2 + 2);
		} else {
			h2->nxt = new node(i * 2 + 2);
			h1->nxt = new node(i * 2 + 1);
		}
		h1 = h1->nxt;
		h2 = h2->nxt;
		flag = (flag == 0);
	}
	h1 = hh1;h2 = hh2;
	for(int i = 1;i <= n / 2; ++i){
		if(h1-> nxt == NULL || h2->nxt == NULL)break;
		cout << h1->val << " " << h2->val << " ";
		h1 = h1->nxt;h2 = h2->nxt;
	}
	if(n & 1)cout << n << endl;
	return 0;
}