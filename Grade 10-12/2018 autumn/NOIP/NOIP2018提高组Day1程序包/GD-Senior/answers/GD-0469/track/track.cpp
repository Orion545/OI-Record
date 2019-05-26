#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N=50100;
int n,m,v[N],f[N],faa[N],l,r,md,x,y,z;
int hed[N],nt[N<<1],too[N<<1],w[N<<1],p;
multiset<int> S;
multiset<int>::iterator it1,it2;
int rd() {
	int re=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') re=re*10+ch-48,ch=getchar();
	return re;
}
void ad(int x,int y,int z) {
	too[++p]=y; nt[p]=hed[x]; w[p]=z; hed[x]=p;
	too[++p]=x; nt[p]=hed[y]; w[p]=z; hed[y]=p;
}
void pre_dfs(int x) {
	for (int i=hed[x]; i; i=nt[i]) if (too[i]!=faa[x]) {
		faa[too[i]]=x; v[too[i]]=w[i]; pre_dfs(too[i]);
	}
}
int dfs(int x) {
	int cnt=0;
	for (int i=hed[x]; i; i=nt[i]) if (too[i]!=faa[x]) cnt+=dfs(too[i]);
	S.clear();
	for (int i=hed[x]; i; i=nt[i]) if (too[i]!=faa[x]) {
		if (f[too[i]]>=md) cnt++; else S.insert(f[too[i]]);
	}
	y=0;
	while (!S.empty()) {
		it1=S.begin(); z=*it1; S.erase(it1);
		if (S.empty()) {y=z; break;}
		it2=S.lower_bound(md-z);
		if (it2==S.end()) {y=z; continue;}
		cnt++; S.erase(it2);
	}
	f[x]=y+v[x];
	return cnt;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rd(); m=rd();
	for (int i=1; i<n; i++) x=rd(),y=rd(),r+=(z=rd()),ad(x,y,z);
	pre_dfs(1); l=1;
	while (l<r) {
		md=((l+r)>>1)+1;
		if (dfs(1)>=m) l=md; else r=md-1;
	}
	printf("%d\n",l);
	return 0;
}
