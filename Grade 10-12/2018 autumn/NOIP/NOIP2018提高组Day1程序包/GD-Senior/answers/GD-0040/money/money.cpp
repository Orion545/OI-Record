#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],sum[100005],ans,maxn,cn,vis[1005],b[100005][105],s[1005];
bool p[2500005],d[2500005],flag[10005];
inline void dfs(int now){
	if (now>maxn) return;
	p[now]=true;
	for (int i=1;i<=n;++i){
		if (!p[now+a[i]]) dfs(now+a[i]);
	}
}
inline void dfss(int now){
	if (now>maxn) return;
	d[now]=true;
	for (int i=1;i<=n;++i){
		if (!d[now+a[i]] && flag[i]) dfss(now+a[i]);
	}
}
inline void zhs(int cnt,int now,int goal){
	if (cnt==goal){
		cn++;
		for (int i=1;i<=cnt;++i) b[cn][i]=s[i];
		return;
	}
	for (int i=now+1;i<=n;++i){
		s[cnt+1]=i;
		zhs(cnt+1,i,goal);
		s[cnt+1]=0;
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		if (n==1) {
			scanf("%d",&a[n]);
			printf("1\n");
			continue;
		}
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		maxn=0;
		memset(p,false,sizeof(p));
		for (int i=1;i<n;++i) for (int j=i+1;j<=n;++j) maxn=max(maxn,a[i]*a[j]-a[i]-a[j]);
		dfs(0);
		for (int i=1;i<=n;++i) {
			cn=1;
			memset(b,0,sizeof(b));
			memset(s,0,sizeof(s));
			bool pp=false;
			zhs(0,0,i);
			for (int j=1;j<=cn;++j){
				memset(flag,false,sizeof(flag));
				for (int k=1;k<=i;++k) flag[b[j][k]]=true;
				memset(d,false,sizeof(d));
				dfss(0);
				pp=true;
				for (int k=1;k<=maxn;++k) if (d[k]!=p[k]) {
					pp=false;
					break;
				}
				if (pp){
					break;
				}
			}
			if (pp) {
				printf("%d\n",i);
				break;
			}
		}
	}	
	return 0;
}
