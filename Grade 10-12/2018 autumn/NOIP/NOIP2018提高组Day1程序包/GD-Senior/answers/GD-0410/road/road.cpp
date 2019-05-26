#include <cstdio>
#include <cstring>
#include <algorithm>
#define L rt<<1
#define R rt<<1|1
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int N=1e5+5;
int n,i,ans,a[N];
struct node{
	int x,y;
} tr[N<<2];
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
void build(int rt,int l,int r){
	if (l==r){
		tr[rt].x=a[l];
		tr[rt].y=l;
		return;
	}
	int mid=(l+r)>>1;
	build(L,l,mid),build(R,mid+1,r);
	if (tr[L].x<=tr[R].x) tr[rt]=tr[L];
	   else tr[rt]=tr[R];
}
node query(int rt,int l,int r,int x,int y){
	if (l>=x&&r<=y) return tr[rt];
	int mid=(l+r)>>1;
	node p,w;
	p.x=1e9+7,w.x=1e9+7;
	if (x<=mid) p=query(L,l,mid,x,y);
	if (y>mid) w=query(R,mid+1,r,x,y);
	if (p.x<=w.x) return p;
	  else return w;
}
void work(int l,int r,int now){
	if (l>r) return;
	node p=query(1,1,n,l,r);
	ans+=p.x-now;
	work(l,p.y-1,p.x),work(p.y+1,r,p.x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	fo(i,1,n) a[i]=read();
	build(1,1,n);
	work(1,n,0);
	printf("%d\n",ans);
}
