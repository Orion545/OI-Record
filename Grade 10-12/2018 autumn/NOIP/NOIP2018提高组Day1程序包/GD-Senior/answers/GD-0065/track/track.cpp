#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=1e5+5;
int first[maxn],last[maxn],next[maxn],value[maxn],d[maxn],bz[maxn],f[maxn];
int n,m,i,t,j,k,l,x,y,z,num,bz1,r,mid,ans,mi;
multiset<int> g;
void lian(int x,int y,int z){
	last[++num]=y;next[num]=first[x];first[x]=num;value[num]=z;
}
void dg(int x,int y){
	int t;
	for (t=first[x];t;t=next[t]){
		if (last[t]==y) continue;
		dg(last[t],x);
		if (f[last[t]]+value[t]>f[x]) d[x]=f[x],f[x]=f[last[t]]+value[t];
		else if (f[last[t]]+value[t]>d[x]) d[x]=f[last[t]]+value[t];
	}
	ans=max(ans,f[x]+d[x]);
}
int dg1(int x,int y){
	if (num>=m) return 0;int t,k;
	for (t=first[x];t;t=next[t]){
		if (last[t]==y) continue;
		k=dg1(last[t],x);f[last[t]]=k+value[t];
		if (num>=m) return 0;
	}d[0]=0;
	for (t=first[x];t;t=next[t]){
		if (last[t]==y) continue;
		d[++d[0]]=f[last[t]];
	}
	while (!g.empty()) g.erase(g.begin());
	g.insert(1e9);
	for (i=1;i<=d[0];i++) g.insert(d[i]);k=0;
	while(1){
		y=*g.begin();
		if (y==1e9) break;
		if (y>=mid){
			g.erase(y),num++;continue;
		}
		x=*g.upper_bound(mid-y-1);
		if (x==y){
			z=*(++g.begin());
			if (z!=y) x=z;
		}
		if (x!=1e9) num++,g.erase(x),g.erase(y);
		else g.erase(y),k=y;
	}
	return k;
}
int main(){
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);mi=1e9;
	for (i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);lian(x,y,z);lian(y,x,z);d[x]=z;ans+=z;
		if (y!=x+1) bz1=1;mi=min(mi,z);
	}
	if (!bz1){
		l=1;
		r=ans/m;
		while (l<r){
			mid=(l+r+1)/2;t=0;k=0;
			for (i=1;i<n && k<m;i++){
				t+=d[i];
				if (t>=mid) k++,t=0;
			}
			if (k>=m) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}else if (m==1){
		memset(d,0,sizeof(d));ans=0;
		dg(1,0);printf("%d\n",ans);
	}else{
		l=1;
		r=ans/m;
		while (l<r){
			mid=(l+r+1)/2;num=0;
			dg1(1,0);
			if (num>=m) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
