#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=r;i>=r;--i)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n,a[N],st[N],tp,L[N],R[N];
int ans=0;

struct node{int x,l,r;}q[N];int tt=0;
inline bool cmp(node x,node y){return a[x.x]<a[y.x];}

namespace TA{
#define lowbit(x) (x&-x)
int tr[N];
inline void add(int x,int d){for(;x<=n;x+=lowbit(x))tr[x]+=d;}
inline void add(int l,int r,int d){add(l,d);add(r+1,-d);}
inline int query(int x){int res=0;for(;x;x-=lowbit(x))res+=tr[x];return res;}

}

int main()
{
	fin("road.in");
	fou("road.out");
	n=rd();fo(i,1,n)a[i]=rd(),ans+=a[i];
	L[st[tp=1]=1]=0;
	fo(i,2,n){
		while(tp&&a[st[tp]]>a[i])R[st[tp--]]=i;
		L[i]=st[tp];st[++tp]=i;
	}
	while(tp)R[st[tp--]]=n+1;
	fo(i,1,n)if(a[i]==a[L[i]])L[i]=L[L[i]];
	of(i,n,1)if(a[i]==a[R[i]])R[i]=R[R[i]];
	fo(i,1,n){
		q[i].x=i;
		q[i].l=L[i]+1;
		q[i].r=R[i]-1;
//		cerr<<L[i]<<' '<<R[i]<<endl;
	}
	sort(q+1,q+n+1,cmp);
	fo(i,1,n)TA::add(i,i,a[i]);
	fo(i,1,n){
		int res=TA::query(q[i].x);
		if(!res)continue;
		ans-=(q[i].r-q[i].l)*res;
		TA::add(q[i].l,q[i].r,-res);
	}
	printf("%d\n",ans);
//	cerr<<ans<<endl;
	return 0;
}

