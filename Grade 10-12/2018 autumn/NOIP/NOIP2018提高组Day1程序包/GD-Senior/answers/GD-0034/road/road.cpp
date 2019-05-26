#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100005;
int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline int getminnum(int x,int y){return x<y?x:y;}
inline int getmaxnum(int x,int y){return x>y?x:y;}
int n,d[maxn<<2],mark[maxn<<2],minnum[maxn<<2],maxnum[maxn<<2];
inline void update(int now)
{
	minnum[now]=getminnum(minnum[now<<1],minnum[now<<1|1]);
	maxnum[now]=getmaxnum(maxnum[now<<1],maxnum[now<<1|1]);
}
inline void pushdown(int now)
{
	if(mark[now])
	{
		mark[now<<1]+=mark[now],mark[now<<1|1]+=mark[now];
		minnum[now<<1]-=mark[now],minnum[now<<1|1]-=mark[now];
		maxnum[now<<1]-=mark[now],maxnum[now<<1|1]-=mark[now];
		mark[now]=0;
	}
}
void build(int now,int l,int r)
{
	//cout<<now<<" "<<l<<" "<<r<<endl;
	if(l==r){scanf("%d",&d[now]);minnum[now]=d[now];maxnum[now]=d[now];mark[now]=0;return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	update(now);
}
void change(int now,int l,int r,int ll,int rr,int val)
{
	if(ll<=l&&r<=rr)
	{
		mark[now]+=val,minnum[now]-=val,maxnum[now]-=val;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(now);
	if(ll<=mid) change(now<<1,l,mid,ll,rr,val);
	if(mid+1<=rr) change(now<<1|1,mid+1,r,ll,rr,val);
	update(now);
}
int getnum(int now,int l,int r,int index)
{
	if(l==r) return maxnum[now];
	int mid=(l+r)>>1;
	pushdown(now);
	if(index<=mid) return getnum(now<<1,l,mid,index);
	else return getnum(now<<1|1,mid+1,r,index);
}
int getmin(int now,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr) return minnum[now];
	int ret=0x3f3f3f3f,mid=(l+r)>>1;
	pushdown(now);
	if(ll<=mid) ret=getminnum(ret,getmin(now<<1,l,mid,ll,rr));
	if(mid+1<=rr) ret=getminnum(ret,getmin(now<<1|1,mid+1,r,ll,rr));
	return ret;
}
int getstart(int now,int l,int r)
{
	if(l==r) return l;
	int mid=(l+r)>>1;
	pushdown(now);
	if(maxnum[now]==maxnum[now<<1]) return getstart(now<<1,l,mid);
	else return getstart(now<<1|1,mid+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	build(1,1,n);
	int cnt=0;
	while(maxnum[1])
	{
		int s=getstart(1,1,n),tmp=maxnum[1],t;
		int l=s,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(getmin(1,1,n,s,mid+1)<tmp) r=mid;
			else l=mid+1;
		}
		t=l;
		int num1=(s==1)?0:getnum(1,1,n,s-1),num2=(t==n)?0:getnum(1,1,n,t+1);
		int delta=tmp-getmaxnum(num1,num2);
		cnt+=delta;
		change(1,1,n,s,t,delta);
	}
	printf("%d\n",cnt);
}
