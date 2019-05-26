#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
#define fd(i,a,b) for(i=a;i>=b;--i)
using namespace std;
const int N=1e5+5;
int n,m,x,y,z,i,tot,nx[N<<1],we[N<<1],he[N],f[N],g[N],p[N],fa[N],id[N],q[N],num;
int fl1,fl2,le[N<<1],sum;
struct edge{
	int x,y,z;
} e[N<<1];
int read(){
	int sum=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void dg(int x,int fr){
	int i;
	for(i=he[x];i;i=nx[i])
	  if (we[i]!=fr){
	  	  dg(we[i],x);
	  	  if (f[we[i]]+le[i]>f[x]){
	  	  	g[x]=f[x],f[x]=f[we[i]]+le[i];
	  	  } else if (f[we[i]]+le[i]>g[x]) g[x]=f[we[i]]+le[i];
	  }
}
void dfs(int x,int fr){
	int i;
	for(i=he[x];i;i=nx[i])
	  if (we[i]!=fr){
	  	p[x]=1;
	  	fa[we[i]]=x,id[we[i]]=i;
	  	  dfs(we[i],x);
	  }
	if (!p[x]) q[++num]=x;
}
void add(int x,int y,int z){
	nx[++tot]=he[x],he[x]=tot,we[tot]=y,le[tot]=z;
}
bool check(int mid){
	int i,cnt,j,l;
	cnt=0;
	fo(i,1,n-1) if (e[i].z>=mid) break;
	cnt+=n-i;
	l=1;
	fd(j,i-1,1){
		if (l>=j) break;
		while (l<j&&e[l].z+e[j].z<mid) ++l;
		if (l<j&&e[l].z+e[j].z>=mid) ++cnt;
		if (e[l].z+e[j].z<mid) break; 
		++l;
	}
	return (cnt>=m);
}
bool get(int mid){
	int i;
	fo(i,1,num) {
		
	}
}
bool pd(int mid){
	int i,cnt,k;
	k=cnt=0;
	fo(i,1,n-1){
		k+=e[i].z;
		if (k>=mid) ++cnt,k=0;
	}
	return (cnt>=m);
}
bool cmp(edge x,edge y){
	return x.z<y.z;
}
bool cm(edge x,edge y){
	return x.x<y.x;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	fo(i,1,n-1){
		x=read(),y=read(),z=read();
		if (y!=x+1) fl2=1;
		if (x!=1) fl1=1;
		add(x,y,z),add(y,x,z);
		e[i].x=x,e[i].y=y,e[i].z=z;
		sum+=z;
	}
	if (m==1){
		dg(1,0);
		printf("%d\n",f[1]+g[1]);
		return 0;
	}
	if (!fl1){
		sort(e+1,e+n,cmp);
		int l=0,r=sum;
		while (l<=r){
			int mid=(l+r)>>1;
			if (check(mid)) l=mid+1; else r=mid-1;
		}
		printf("%d\n",l-1);
		return 0;
	}
	if (!fl2){
		sort(e+1,e+n,cm);
		int l=0,r=sum;
		while (l<=r){
			int mid=(l+r)>>1;
			if (pd(mid)) l=mid+1; else r=mid-1;
		}
		printf("%d\n",l-1);
		return 0;
	} else {
		dfs(1,0);
		int l=0,r=sum;
		while (l<=r){
			int mid=(l+r)>>1;
			if (get(mid)) l=mid+1; else r=mid-1;
		}
	}
}
