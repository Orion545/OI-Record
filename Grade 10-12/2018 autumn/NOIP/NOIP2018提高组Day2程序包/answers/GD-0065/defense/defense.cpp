#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int first[maxn],last[maxn],next[maxn],a[maxn],f[maxn][2];
int d[maxn],size[maxn],g[maxn][4],deep[maxn],fa[maxn];
int n,m,i,t,j,k,l,x,y,z,bz,num,p[2],q[2],ans,xx,yy,zz;
char ch;
void lian(int x,int y){
	last[++num]=y;next[num]=first[x];first[x]=num;
}
void dg(int x,int y){
	int t;f[x][1]=a[x];deep[x]=deep[y]+1;fa[x]=y;size[x]++;d[x]=++num;
	for (t=first[x];t;t=next[t]){
		if (last[t]==y) continue;
		dg(last[t],x);size[x]+=size[last[t]];
		f[x][0]+=f[last[t]][1];
		f[x][1]+=min(f[last[t]][0],f[last[t]][1]);
	}
}
void dg1(int x,int y){
	if (y){
		g[x][0]=f[x][0]+g[y][1]-min(f[x][0],f[x][1]);
		if (y!=1) g[x][1]=f[x][1]+min(g[y][0]-f[x][1],g[y][1]-min(f[x][0],f[x][1]));
		else g[x][1]=f[x][1]+g[y][1]-min(f[x][0],f[x][1]);
	}else g[x][1]=f[x][1];
	int t;
	for (t=first[x];t;t=next[t])if (last[t]!=y) dg1(last[t],x);
}
void dg2(int x,int y){
	if (y){
		g[x][1]=g[y][2];
		g[x][2]=min(g[y][3],g[y][1])-min(f[x][0],f[x][1])+f[x][0];
		g[x][3]=min(g[y][3],g[y][1])-min(f[x][0],f[x][1])+f[x][1];
	}else g[x][1]=g[x][3]=f[x][1],g[x][2]=f[x][0];
	int t;
	for (t=first[x];t;t=next[t])if (last[t]!=y) dg2(last[t],x);
}
int main(){
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	scanf("%d%d %c%d\n",&n,&m,&ch,&bz);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),lian(x,y),lian(y,x);
	num=0;dg(1,0);
	if (bz==1){
		dg1(1,0);
		for (i=1;i<=m;i++){
			scanf("%d%d%d%d",&x,&t,&y,&k);
			printf("%d\n",g[y][k]);
		}
	}else if (bz==2){
		dg2(1,0);
		for (i=1;i<=m;i++){
			scanf("%d%d%d%d",&x,&t,&y,&k);
			if (t+k==0) printf("-1\n");
			else{
				if (deep[x]>deep[y]) swap(x,y),swap(t,k);
				t=t*2+k;
				printf("%d\n",g[y][t]);
			}
		}
	}else{
		dg2(1,0);
		for (i=1;i<=m;i++){
			scanf("%d%d%d%d",&x,&t,&y,&k);
			if (deep[x]>deep[y]) swap(x,y),swap(t,k);xx=x;
			if (fa[y]==x && t+k==0) printf("-1\n"); 
			else{
				if (d[x]+size[x]<=d[y] || d[x]>d[y]) ans=f[x][t]+f[y][k];
				else ans=f[y][k]; 
				p[k]=0;p[1-k]=1e9;q[t]=0;q[1-t]=1e9;
				while(x!=y){
					if (deep[x]>deep[y]) swap(x,y),swap(t,k),swap(p,q),swap(yy,zz);
					z=min(p[0],p[1]);
					p[0]=f[fa[y]][0]-f[y][1]+p[1];
					p[1]=f[fa[y]][1]-min(f[y][0],f[y][1])+z;
					yy=y,y=fa[y];
				}
				if (xx!=x){
					p[0]-=f[zz][1],q[0]-=f[yy][1],p[1]-=min(f[zz][0],f[zz][1]);q[1]-=min(f[yy][0],f[yy][1]);
					ans+=min(p[0]+q[0]-g[x][2]+f[yy][1]+f[zz][1],p[1]+q[1]-min(g[x][1],g[x][3])+min(f[yy][0],f[yy][1])+min(f[zz][0],f[zz][1]));
				}
				else if (!t) ans+=p[0]-g[x][2]+f[yy][1];
				else ans+=p[1]-min(g[x][1],g[x][3])+min(f[yy][0],f[yy][1]);
				printf("%d\n",ans);
			}
		}
	}
}
