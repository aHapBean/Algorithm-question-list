//#pragama optimize(2)
#define fi freopen("in","r",stdin);
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cout << "here" << x << "\n"
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
// set can build a pq that can be deleted !
const int maxn = 2e5 + 5;
int x,y,t,xx[maxn],n,cnt = -1;//cir[maxn],
struct circle{
	int x,y;
}cir[maxn],q[maxn];
struct op{
	int t,x,y;
}op[maxn];
int cirl = -1,tail = -1;
map<int,int> tt[maxn << 2];
//struct node{
//	int l,r;
//	set<int> lz;
//	set<
//}
void pushdown(int rt,int l,int m,int r){
	if(tt[rt].size() != 0)return ;
	if(l == r)return ;// leaf doesn't need to !
	if(l == m && m + 1 == r){
		while(!tt[rt].size()){
			int flag = tt[rt].begin()->second;
			if(flag == -1){
				tt[rt << 1 | 1].erase((*tt[rt].begin()).first);
				tt[rt << 1].erase((*tt[rt].begin()).first);
				tt[rt].erase(tt[rt].begin());
				continue;
			}
			tt[rt << 1 | 1].insert(*tt[rt].begin());
			tt[rt << 1].insert(*tt[rt].begin());
			tt[rt].erase(tt[rt].begin());
		}
	} else if(l == m && m + 1 != r){
		while(tt[rt].size() != 0){
			int flag = tt[rt].begin()->second;
			if(flag == -1){
				tt[rt << 1 | 1].insert(*tt[rt].begin());
				tt[rt << 1].erase((*tt[rt].begin()).first);
				tt[rt].erase(tt[rt].begin());
				continue;
			}
			tt[rt << 1 | 1].insert(*tt[rt].begin());
			tt[rt << 1].insert(*tt[rt].begin());
			tt[rt].erase(tt[rt].begin());
		}
	} else if(l != m && m + 1 == r){
		while(tt[rt].size() != 0){
			int flag = tt[rt].begin()->second;
			if(flag == -1){
				tt[rt << 1 | 1].insert(*tt[rt].begin());
				tt[rt << 1].erase((*tt[rt].begin()).first);
				tt[rt].erase(tt[rt].begin());
				continue;
			}
			tt[rt << 1 | 1].insert(*tt[rt].begin());
			tt[rt << 1].insert(*tt[rt].begin());
			tt[rt].erase(tt[rt].begin());
		}
	} else {
		while(!tt[rt].size()){
		tt[rt << 1 | 1].insert(*tt[rt].begin());
		tt[rt << 1].insert(*tt[rt].begin());
		tt[rt].erase(tt[rt].begin());
	}
	}
	/*if(l == m && m + 1 == r){
		while(!lz[rt].size()){
			tt[rt << 1 | 1].insert(*lz[rt].begin());
			tt[rt << 1].insert(*lz[rt].begin());
			lz[rt].erase(lz[rt].begin());
		}
	} else if(l == m && m + 1 != r) {
		while(!lz[rt].size()){
			lz[rt << 1].insert(*lz[rt].begin());
			lz[rt].erase(lz[rt].begin());
		}
	}*/
	
}
void update(int rt,int l,int r,int x,int y,int ind){
	int m = l + r >> 1;
	pushdown(rt,l,m,r);
	if(x <= l && r <= y){
		tt[rt].insert(ind);return ;
	}
	if(x <= m)update(rt << 1,l,m,x,y,ind);
	if(y > m)update(rt << 1 | 1,m + 1,r,x,y,ind);
}
int check(int x,int y,set<int> &tar){
	for(auto i : tar){
		int a = (op[i - 1].x - x) * (op[i - 1].x - x) + (op[i - 1].y * 2 - y) * (0 - y);
		if(a < 0)return i; //ind ! no zero
	}
	return -1;
}
int ask(int rt,int l,int r,int x,int y){
	int m = l + r >> 1;
	pushdown(rt,l,m,r);
	if(l == r){
		return check(x,y,tt[rt]);
	}
	if(x <= m)return ask(rt << 1,l,m,x,y);
	else return ask(rt << 1 | 1,m + 1,r,x,y);
}

void del(int rt,int l,int r,int x,int y,int ind){
	int m = l + r >> 1;
	pushdown(rt,l,m,r);
	if(x <= l && r <= y){
		tt[rt].insert(ind);return ;
	}
	if(x <= m)update(rt << 1,l,m,x,y,ind);
	if(y > m)update(rt << 1 | 1,m + 1,r,x,y,ind);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		scanf("%d%d%d",&t,&x,&y);

		//if(t == 1)++cirl,scanf("%d%d",&cir[cirl].x,&cir[cirl].y);
		//else ++tail,scanf("%d%d",&q[tail].x,&q[tail].y);
		//if(t == 1){
		//	xx[++cnt] = cir[cirl].x - cir[cirl].y;xx[++cnt] = cir[cirl].x + cir[cirl].y;
		//} else xx[++cnt] = q[tail].x;
		op[i] = {t,x,y};
		if(t == 1){
			xx[++cnt] = x - y;xx[++cnt] = x + y;
		} else xx[++cnt] = x;
	}
	sort(xx,xx + cnt + 1);
	int len = unique(xx,xx + cnt + 1) - xx;
	for(int i = 0; i < n; ++i){
		int t = op[i].t,x = op[i].x,y = op[i].y;
		if(t == 1){
			update(1,1,len,lower_bound(xx,xx + len,x - y) - xx + 1,lower_bound(xx,xx + len,x + y) - xx + 1,i + 1);
		} else {
			int ind = lower_bound(xx,xx + len,x) - xx + 1;
			int index = 0;
			printf("%d\n",index = ask(1,1,len,ind,y));
			if(index == -1)continue;
			del(1,1,len,lower_bound(xx,xx + len,op[index - 1].x - op[index - 1].y) - xx + 1,lower_bound(xx,xx + len,op[index - 1].x + op[index - 1].y) - xx + 1,index);
		
		}
	}
	return 0;
}
