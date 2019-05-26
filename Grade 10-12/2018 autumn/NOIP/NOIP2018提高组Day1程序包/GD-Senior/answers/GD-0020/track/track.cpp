#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
const int N=50010;
struct edg{int y,c,nex;}e[N<<1]; int len,fir[N];
void ins(int x,int y,int c){
	e[++len].y=y,e[len].c=c,e[len].nex=fir[x],fir[x]=len;
}
int n,m,p,s,f[N],q[N]; bool v[N];
int Cmp(int x,int y){return x>y;}
int b[N];
int get(int x){return x==b[x]?x:b[x]=get(b[x]);}
inline void dfs(int x,int fa){
	f[x]=0; int ql=0;
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(y==fa) continue;
		dfs(y,x); f[y]+=e[k].c;
	}
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(y==fa) continue;
		q[++ql]=f[y];
	}
	if(!ql) return;
	sort(q+1,q+1+ql,Cmp);
	int o,i;
	for(o=1;o<=ql;++o)
		if(q[o]>=p)++s;
		else break;
	for(i=o;i<=ql;++i) v[i]=0,b[i]=i;
	for(i=ql;i;--i) if(!v[i]){
		int l=o,r=i-1,u=0;
		while(l<=r){
			int mid=l+r>>1;
			if(q[mid]+q[i]>=p) l=(u=mid)+1;
			else r=mid-1;
		}
		u=get(u); if(u<o)continue;
		v[u]=v[i]=1,b[u]=u-1,++s;
	}
	for(i=o;i<=ql;++i) if(!v[i]){f[x]=q[i]; break;}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	int l=1,r=0,ans=1; b[0]=0;
	for(int i=1;i<n;++i){
		int x=read(),y=read(),c=read();
		ins(x,y,c),ins(y,x,c); r+=c;
	}
	while(l<=r){
		p=l+r>>1,s=0;
		dfs(1,0);
		if(s>=m) l=(ans=p)+1;
		else r=p-1;
	}
	printf("%d\n",ans);
	return 0;
}
