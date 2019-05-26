#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 201
#define maxm 100010
using namespace std;

int n,m,i,j,k,ans,sumc,a[maxm][3],tp,co[maxm],l,r,mid,cnt,t,s,co2[maxm];
int em,e[maxm],nx[maxm],ls[maxm],ec[maxm],f[maxm][8];

void insert(int x,int y,int z){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; ec[em]=z;
}

int dg(int x,int p){
	int mx1=0,mx2=0;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		int tmp=dg(e[i],x)+ec[i];
		if (tmp>mx1) mx2=mx1,mx1=tmp;
		else if (tmp>mx2) mx2=tmp;
	}
	ans=max(ans,mx1+mx2);
	return max(mx1,mx2);
}

int pd1(int mid){
	cnt=t=0;
	for(j=n-1;j>t;j--) {
		while(j>t&&co[j]+co[t]<mid) t++;
		if (j>t) cnt++,t++;
	}
	return (cnt>=m);
}

int pd2(int mid){
	cnt=0,s=0;
	for(i=1;i<n;i++){
		s+=co2[i];
		if (s>=mid) cnt++,s=0;
	}
	return (cnt>=m);
}

int dis[maxn][maxn],fa[maxn],dep[maxn];
void dfs(int x,int p,int st){
	if (st==1) dep[x]=dep[p]+1,fa[x]=p;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		dis[st][e[i]]=dis[st][x]+ec[i];
		dfs(e[i],x,st);
	}
}

int q[40005][2],tot,bz[maxn];

int check(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]>dep[y]){
		if (bz[x]) return 0;
		x=fa[x];
	}
	while (x!=y){
		if (bz[x]||bz[y]) return 0;
		x=fa[x],y=fa[y];
	}
	return 1;
}

void cover(int x,int y,int t){
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]>dep[y]) 
		bz[x]=t,x=fa[x];
	while (x!=y)
		bz[x]=bz[y]=t,x=fa[x],y=fa[y];
}
int baoli(int i,int cnt){
	if (cnt>=m) return 1;
	if (i>tot) return 0;
	if (check(q[i][0],q[i][1])){
		cover(q[i][0],q[i][1],1);
		if (baoli(i+1,cnt+1)) return 1;
		cover(q[i][0],q[i][1],0);
	}
	return baoli(i+1,cnt);
}

int pd3(int mid){
	tot=0;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (dis[i][j]>=mid)
		q[++tot][0]=i,q[tot][1]=j;
	for(i=1;i<=n;i++) bz[i]=0;
	return baoli(1,0);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]),sumc+=a[i][2];
	if (m==1){
		ans=0;
		for(i=1;i<n;i++) insert(a[i][0],a[i][1],a[i][2]);
		dg(1,0);
		printf("%d",ans);
		return 0;
	} 
	tp=1;
	for(i=1;i<n;i++) if (a[i][0]!=1) {tp=0;break;}
	if (tp){
		for(i=1;i<n;i++) co[i]=a[i][2];
		sort(co+1,co+n);
		l=0,r=sumc;
		while (l<r-1){
			mid=(l+r)/2;
			if (pd1(mid)) l=mid;
			else r=mid-1;
		}
		if (pd1(r)) printf("%d",r);
		else printf("%d",l);
		return 0;
	}
	tp=1;
	for(i=1;i<n;i++) if (a[i][0]+1!=a[i][1]) {tp=0;break;}
	if (tp){
		for(i=1;i<n;i++) co2[a[i][0]]=a[i][2];
		l=0,r=sumc;
		while (l<r-1){
			mid=(l+r)/2;
			if (pd2(mid)) l=mid; 
			else r=mid-1;
		}
		if (pd2(r)) printf("%d",r);
		else printf("%d",l);
		return 0;
	}
	for(i=1;i<n;i++) insert(a[i][0],a[i][1],a[i][2]);
	for(i=1;i<=n;i++) dfs(i,i,i);
	l=0,r=sumc;	
	while (l<r-1){
		mid=(l+r)/2;
		if (pd3(mid)) l=mid;
		else r=mid-1;
	}
	if (pd3(r)) printf("%d",r);
	else printf("%d",l);
}
