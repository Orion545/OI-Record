#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pr pair<int,int>
#define fr first
#define se second
#define mid (l+r>>1)
#define N 50050
#define mp make_pair
vector<pr > v,g[N];
pr f[N];
int jb,a[N],n,m,i;
bool cmp(pr x,pr y)
{
	return f[x.fr].se>f[y.fr].se;
}
void dfs(int now,int lst)
{
	v.clear();
	for (int ii=0;ii<g[now].size();ii++) if (g[now][ii].fr!=lst) v.push_back(g[now][ii]);
	g[now].swap(v);
	for (int ii=0;ii<g[now].size();ii++) dfs(g[now][ii].fr,now);
}
void dfs2(int now)
{
	for (int ii=0;ii<g[now].size();ii++) dfs2(g[now][ii].fr),f[now].fr+=f[g[now][ii].fr].fr,f[g[now][ii].fr].se+=g[now][ii].se;
	for (int ii=0;ii<g[now].size();ii++) if (f[g[now][ii].fr].se>=jb) f[now].fr++,f[g[now][ii].fr].se=0;
	sort(g[now].begin(),g[now].end(),cmp);
	int l=0,r=g[now].size()>>1;
	while (l!=r){
		bool zw=true;
		for (int ii=0;ii<=mid;ii++) if (f[g[now][ii].fr].se+f[g[now][((mid<<1)|1)-ii].fr].se<jb){
			zw=false;break;
		}if (zw) l=mid+1;else r=mid;
	}f[now].fr+=l;
	if (l*2==g[now].size()) return;
	int ans=l;
	l=0;r=g[now].size()-1;
	while (l!=r){
		for (int ii=0,jj=1;jj<=2*ans;ii++) if (ii!=mid) a[jj]=ii,jj++;
		bool zw=true;
		for (int ii=1;ii<=ans;ii++) if (f[g[now][a[ii]].fr].se+f[g[now][a[((ans<<1)|1)-ii]].fr].se<jb){
			zw=false;break;
		}if (zw) r=mid;else l=mid+1;
	}f[now].se=f[g[now][l].fr].se;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(mp(y,z));g[y].push_back(mp(x,z));
	}dfs(1,0);
	int l=1,r=500000000;
	while (r-l>1){
		for (i=1;i<=n;i++) f[i].fr=f[i].se=0;
		jb=mid;dfs2(1);
		if (f[1].fr>=m) l=mid;else r=mid;
	}printf("%d\n",l);
	return 0;
}
