#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fr(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
const int N=1e6+6;
int mm,n,m,x,y,z,d[N<<1][5],c[N],f[N],xx,siz[N],root,v,a[N],t;
ll yy,sum,ans,l,r,mid;
bool bz,b[N<<1];
void ins(int x,int y,int z){
	d[++mm][1]=x; d[mm][2]=y; d[mm][3]=z; d[mm][4]=c[x]; c[x]=mm;
}
void dfs(int x,int y,ll z){
	if (z>yy) xx=x,yy=z;
	for(int k=c[x];k;k=d[k][4]) {
		if (d[k][2]==y) continue;
		dfs(d[k][2],x,z+d[k][3]);
	}
}
void dg(int x,int z){
	for(int k=c[x];k;k=d[k][4]) {
		if (d[k][2]==z) continue;
		f[d[k][2]]=d[k][3]; dg(d[k][2],x);
	}
}
bool pd(int x) {
	int y=0; ll l=0;
	fo(i,1,n) {
		l+=f[i]; if (l>=x) y++,l=0;
	}
	if (y>=m) return 1; return 0;
}
void dfs2(int x,int z){
	siz[x]=1; bool bz=1;
	for(int k=c[x];k;k=d[k][4]) {
		if (d[k][2]==z) continue;
		dfs2(d[k][2],x); siz[x]+=siz[d[k][2]];
		if (bz==1 && siz[d[k][2]]>(n/2)) bz=0;
	} 
	if (n-siz[x]>(n/2)) bz=0;
	if (bz) root=x;
}
void gc(int x,int z){
	f[x]=0;
	for(int k=c[x];k;k=d[k][4]) {
		if (d[k][2]==z) continue; gc(d[k][2],x);
	}
	t=0;
	for(int k=c[x];k;k=d[k][4]) {
		if (d[k][2]==z) continue; 
		if (f[d[k][2]]+d[k][3]>=mid) v++; else
		a[++t]=f[d[k][2]]+d[k][3];
	}
	if (!t) return;
	sort(a+1,a+t+1); int j=1;
	fr(i,t-1,1) {
		while (j<=(t-1) && (a[j]+a[i]<mid || (b[j])) && (j<=i)) j++;
	 	if (j>=t || (j>=i)) break;
	 	if ((b[i]==0) && (b[j]==0)) b[i]=b[j]=1,v++;
	}
	fo(i,1,t-1) {
		if ((b[i]==0) && (a[i]+a[t]>=mid)) {v++; b[i]=b[t]=1; break; }
	}
	fo(i,1,t) {
		if (!b[i]) f[x]=a[i]; b[i]=0;
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m); bz=0;
	fo(i,1,n-1) {
		scanf("%d %d %d",&x,&y,&z); if (x+1!=y) bz=1;
		ins(x,y,z); ins(y,x,z); sum+=z;
	}
	if (m==1) {
		xx=1; yy=0; dfs(1,0,0); dfs(xx,0,0); printf("%lld\n",yy); return 0;
	}
	if (!bz) {
		f[1]=0; dg(1,0);
		l=0; r=sum; ans=0;
		while (l<=r) {
			mid=(l+r)>>1;
			if (pd(mid)) l=mid+1,ans=mid; else r=mid-1;
		} printf("%lld\n",ans); return 0;
	}
	dfs2(1,0); 
	l=0; r=sum; ans=0; 
	while (l<=r) {
		mid=(l+r)>>1; //memset(f,0,sizeof(f));
		v=0; gc(root,0); 
		if (v>=m) ans=mid,l=mid+1; else r=mid-1;
	}
	printf("%lld\n",ans);
}
