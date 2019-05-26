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
const int N=100010;
int f[N<<2],a[N],ans,n;
void bt(int x,int l,int r){
	if(l==r){f[x]=l; return;}
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	bt(lc,l,mid),bt(rc,mid+1,r);
	f[x]=a[f[lc]]<a[f[rc]]?f[lc]:f[rc];
}
int get(int x,int l,int r,int ql,int qr){
	if(l==ql && r==qr) return f[x];
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	if(qr<=mid) return get(lc,l,mid,ql,qr);
	if(ql>mid) return get(rc,mid+1,r,ql,qr);
	int ln=get(lc,l,mid,ql,mid),rn=get(rc,mid+1,r,mid+1,qr);
	return a[ln]<a[rn]?ln:rn;
}
void solve(int l,int r,int c){
	if(l==r){ans+=a[l]-c; return;}
	int o=get(1,1,n,l,r);
	ans+=a[o]-c,c=a[o];
	if(l<o) solve(l,o-1,c);
	if(o<r) solve(o+1,r,c);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0;
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	bt(1,1,n);
	solve(1,n,0);
	printf("%d\n",ans);
	return 0;
}
