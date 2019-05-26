#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const bool local=0;
void read(int &x){
	int c=getchar();
	x=0;
	while((c<'0')||(c>'9'))c=getchar();
	while((c>='0')&&(c<='9')){
		x=x*10+(c^48);
		c=getchar();
	}
	return;
}
int n,m,p,q,r,d,l,j,mi,mihao,di1,di2;
int dfd[5002],dfn[5002];
bool vis[5002];
int tou[5002],wei[10002],xyg[10002],shu,biantou[5002],bianwei[5002];
struct bian{
	int a,b;
}b[10002];
int lx,ly;
int cx[20],cy[20];
bool tris(int x,int y){
	return x<y;
	lx=ly=0;
	while (x){
		cx[++lx]=x%10;
		x/=10;
	}
	while (y){
		cy[++ly]=y%10;
		y/=10;
	}
	while(lx&&ly){
		if (cx[lx]<cy[ly]) return 1;
		if (cx[lx]>cy[ly]) return 0;
		--lx;
		--ly;
	}
	if (ly) return 1;
	return 0;
}
bool cmp(bian a,bian b){
	if (a.a==b.a)return tris(a.b,b.b);
	return tris(a.a,b.a);
}
void add(int x,int y){
	b[shu].a=x;
	b[shu].b=y;
	++shu;
	xyg[shu]=tou[x];
	tou[x]=shu;
	wei[shu]=y;
}
void del(int x,int dep,int fa){
	if (di1) return;
	if (vis[x]) if (dfn[x]==dfn[fa]-1)return;
	if (vis[x]) {
		d=dfn[x];
		l=dep-d;
		mi=6000;
		for (int i=d;i<dep;++i){
			if (tris(dfd[i],mi)) {
				mi=dfd[i];
				mihao=i;
			}
		}
		p=(mihao-d+1+l)%l+d;
		q=(mihao-d-1+l)%l+d;
		di1=mi;
		if (tris(dfd[p],dfd[q])){
			di2=dfd[q];
		}else{
			di2=dfd[p];
		}
		return;
	}
	dfd[dep]=x;
	vis[x]=1;
	dfn[x]=dep;
	for (int i=tou[x];i;i=xyg[i]){
		del(wei[i],dep+1,x);
		if (di1) break;
	}
	return;
}
void dfs(int x){
	printf("%d ",x);
	vis[x]=1;
	if (x==di1){	
		for (int i=biantou[x];i<=bianwei[x];++i){
			if (!vis[b[i].b]&&(b[i].b!=di2)) dfs(b[i].b);
		}
		return;
	}
	if (x==di2){
		for (int i=biantou[x];i<=bianwei[x];++i){
			if (!vis[b[i].b]&&(b[i].b!=di1)) dfs(b[i].b);
		}
		return;
	}
	for (int i=biantou[x];i<=bianwei[x];++i){
		if (!vis[b[i].b]) dfs(b[i].b);
	}
	return;
}
int main()
{
	if (local){
		freopen("travel3.in","r",stdin);
	}else{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	}
	read(n);read(m);
	for (int i=0;i<m;++i){
		read(p);read(q);
		add(p,q);add(q,p);
	}
	if (m==n){
		del(1,1,0);
	}
	memset(vis,0,sizeof vis);
	sort(b,b+shu,cmp);
	for (int i=0;i<shu;++i){
		if (b[i].a!=b[i-1].a) {
			biantou[b[i].a]=i;
			bianwei[b[i-1].a]=i-1;
		}
	}
	bianwei[b[shu-1].a]=shu-1;
	dfs(1);
	return 0;
}
