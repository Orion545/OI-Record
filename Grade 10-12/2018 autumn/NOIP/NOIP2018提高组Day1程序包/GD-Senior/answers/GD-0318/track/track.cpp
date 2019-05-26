# include<cstdio>
# include<cstring>
# include<algorithm>
# include<set>
using namespace std;
const int N = 5e4 + 5;
multiset <int> s;
multiset <int>::iterator it;
int st[N],to[N << 1],nx[N << 1],len[N << 1];
int d[N],sta[N],z[N],c[N][2];
int n,m,tot,top;
inline void add(int u,int v,int w)
{
	to[++tot] = v,nx[tot] = st[u],st[u] = tot,len[tot] = w;
	to[++tot] = u,nx[tot] = st[v],st[v] = tot,len[tot] = w;
}
inline void pre(int x,int f)
{
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != f) d[to[i]] = d[x] + len[i],pre(to[i],x);
}
inline void check(int x,int lim,int f)
{
	z[x] = d[x];
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != f) check(to[i],lim,x);
	top = 0;
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != f) sta[++top] = z[to[i]];
	sort(sta + 1,sta + top + 1);
	int pos = 0;
	for (int i = top ; i ; --i)
	if (sta[i] - d[x] >= lim) ++tot;
	else { pos = i; break; }
	if (!pos) return;
	s.clear();
	for (int i = 1 ; i <= pos ; ++i) s.insert(i),c[i][0] = c[i][1] = 0;
	while (s.size() > 1)
	{
		it = s.end(); --it; int v = lower_bound(sta + 1,sta + pos + 1,2 * d[x] + lim - sta[*it]) - sta,id = *it;
		s.erase(it); it = s.lower_bound(v);
		if (it == s.end()) { s.insert(id); break; }
		++tot,c[id][0] = *it,c[*it][1] = id; s.erase(it);
	}
	if (s.size())
	{
		it = s.end(); --it;
		z[x] = max(z[x],sta[*it]);
	}
	int p = pos;
	for (int i = pos ; i ; --i)
	{
		while (p > i && sta[p] + sta[i] - 2 * d[x] >= lim)
		{
			if (c[p][0]) s.insert(c[p][0]);
			--p;
		}
		int v = c[i][0] ? c[i][0] : c[i][1];
		if (!v) continue;
		bool flag = 0; it = s.lower_bound(i);
		if (*it == i) { flag = 1; s.erase(it); }
		int ret = lower_bound(sta + 1,sta + pos + 1,2 * d[x] + lim - sta[v]) - sta;
		if (s.lower_bound(ret) != s.end()) z[x] = max(z[x],sta[i]);
		if (flag) s.insert(i);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l = 0,r = 0;
	for (int i = 1 ; i < n ; ++i)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),r += w;
	}
	int ans = r;
	pre(1,0),tot = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		tot = 0,check(1,mid,0);
		if (tot >= m) l = mid + 1,ans = mid;
		else r = mid - 1;
	} printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
