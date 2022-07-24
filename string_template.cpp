1.莫队

struct query{
    int l,r,id;
    bool operator<(const query &x) const {
        if(l / maxn != x.l / maxn)return l < x.l;
        return (l / maxn) & 1 ? r < x.r : r > x.r;//会有溢出
    }
}a[N];

ll gcd(ll a,ll b){
    return b > 0 ? gcd(b,a % b) : a;
}
void add(int i){
    sum += cnt[i];//简化后的式子
    //递推式
    cnt[i]++;
}
void del(int i){
    cnt[i]--;
    sum -= cnt[i];
}
int main() {
    scanf("%d%d",&n,&m);
    maxn = sqrt(n);
    for(int i = 1; i <= n; ++i)scanf("%d",&c[i]);
    for(int i = 0; i < m; ++i)scanf("%d%d",&a[i].l,&a[i].r),a[i].id = i;
    sort(a,a + m);
    for(int i = 0, l = 1, r = 0; i < m; ++i){
        if(a[i].l == a[i].r){
            ans1[a[i].id] = 0;
            ans2[a[i].id] = 1;
            continue;
        }
        while(l > a[i].l)add(c[--l]);
        while(r < a[i].r)add(c[++r]);
        while(l < a[i].l)del(c[l++]);
        while(r > a[i].r)del(c[r--]);
        ans1[a[i].id] = sum;
        ans2[a[i].id] = ll(r - l + 1) * (r - l) / 2;
    }
    for(int i = 0; i < m; ++i){
        if(ans1[i] != 0){
            ll g = gcd(ans1[i],ans2[i]);
            ans1[i] /= g;ans2[i] /= g;
        } else 
            ans2[i] = 1;
        printf("%lld/%lld\n",ans1[i],ans2[i]);
    }
    return 0;
}

bool cmp(int x,int y,int w){
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void SA(int n){
    int w,p,i,m = 300;
    for(int i = 1; i <= n; ++i)++cnt[rk[i] = s[i]];
    for(int i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];//m here !!
    for(int i = n; i >= 1; --i)sa[cnt[rk[i]]--] = i;
    for(w = 1;;w <<= 1,m = p){
        for(p = 0, i = n; i > n - w; --i)id[++p] = i;
        for(i = 1; i <= n; ++i)
            if(sa[i] > w)id[++p] = sa[i] - w;
        memset(cnt,0,sizeof(cnt));
        for(i = 1; i <= n; ++i)++cnt[px[i] = rk[id[i]]];
        for(i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
        for(i = n; i >= 1; --i)sa[cnt[px[i]]--] = id[i];
        memcpy(oldrk,rk,sizeof(rk));
        for(p = 0,i = 1; i <= n; ++i)
            rk[sa[i]] = cmp(sa[i],sa[i - 1],w) ? p : ++p;
        if(p == n){
            for(int i = 1; i <= n; ++i)sa[rk[i]] = i;
            break;
        }
    }
}