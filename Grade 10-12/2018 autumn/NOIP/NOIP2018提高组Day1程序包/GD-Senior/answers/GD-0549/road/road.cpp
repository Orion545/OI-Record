#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
int a[100005];
struct dk{
	int l,r,mi,mip;	
}xd[4*N];
void biu(int l,int r,int t){
	 if(l==r) {xd[t].mi=a[l],xd[t].mip=xd[t].l=xd[t].r=l;return;}
	 xd[t].l=l,xd[t].r=r;
	 int mid=(l+r)/2;
	 biu(l,mid,2*t);biu(mid+1,r,2*t+1);
	 xd[t].mi=min(xd[2*t].mi,xd[2*t+1].mi);
	 xd[t].mip=xd[2*t].mi<xd[2*t+1].mi?xd[2*t].mip:xd[2*t+1].mip;
}
void ga1(int l,int r,int &x,int &y,int t){
//	 printf("%d %d\n",l,r);
	 if(l<=xd[t].l&&r>=xd[t].r) {x=xd[t].mi,y=xd[t].mip;return;}
	 int mid=(xd[t].l+xd[t].r)/2,x1=N,x2=N,y1,y2;
	 if(l<=mid) ga1(l,r,x1,y1,2*t);
	 if(r>=mid+1) ga1(l,r,x2,y2,2*t+1);
	 x=min(x1,x2);y=x1<x2?y1:y2;
}
int ga(int l,int r,int tjm){
	if(l==r) return a[l]-tjm;
	if(l>r) return 0;
	int re=0,ans,ap;
	ga1(l,r,ans,ap,1);
//	printf("LL");
	re+=ans-tjm;tjm=ans;
	re+=ga(l,ap-1,tjm);
	re+=ga(ap+1,r,tjm);
	return re;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int n1=1;n1<=n;n1++) scanf("%d",&a[n1]);
	biu(1,n,1);
//	for(int n1=1;n1<=2*n;n1++) printf("%d: %d %d %d %d\n",n1,xd[n1].l,xd[n1].r,xd[n1].mi,xd[n1].mip);
	printf("%d\n",ga(1,n,0));
}
