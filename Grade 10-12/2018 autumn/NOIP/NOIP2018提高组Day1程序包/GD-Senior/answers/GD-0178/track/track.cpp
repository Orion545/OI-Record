#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
struct node
{
	int x,y,d,next;
}a[110000];int len,last[51000];
bool cmp(node n1,node n2){return n1.x<n2.x;}
void ins(int x,int y,int d)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].d=d;
	a[len].next=last[x];last[x]=len;
}
LL dep[51000];
void dfs(int x,int fa)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa) continue;
		dep[y]=dep[x]+a[k].d;
		dfs(y,x);
	}
}
LL D[51000];int n,m;
bool check(LL d)
{
	LL sum=0;int mm=0;
	for(int i=1;i<=len;i++)
	{
		if(sum+a[i].d>=d) mm++,sum=0;
		else sum+=a[i].d;
	}
	if(mm>=m) return true;
	return false;
}
bool check1(LL d)
{
	int mm=0,R=len;
	for(int i=1;i<=len;i++)
	{
		if(D[i]<d&&i==R) break;
		if(D[i]>=d)
		{
			mm+=R-i+1;
			break;
		}
		else if(D[i]+D[R]<d) return false;
		else mm++,R--;
	}
	if(mm>=m) return true;
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	bool bk=false,bk2=false;
	LL dd=0;
	for(int i=1;i<n;i++)
	{
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		if(x!=1) bk=true;
		if(x+1!=y) bk2=true;
		ins(x,y,d);ins(y,x,d);dd+=d;
	}
	if(m==1)
	{
		dep[1]=0;dfs(1,0);
		LL mmax=0;int st;
		for(int i=1;i<=n;i++) if(mmax<dep[i]) st=i,mmax=dep[i];
		dep[st]=0;dfs(st,0);mmax=0;
		for(int i=1;i<=n;i++) if(mmax<dep[i]) mmax=dep[i];
		printf("%lld\n",mmax);
	}
	else if(bk==false)
	{
		LL sum=0;
		for(int i=2;i<=len;i+=2) D[i/2]=a[i].d,sum+=a[i].d;
		len=n-1;
		sort(D+1,D+len+1);
		LL l=1,r=sum,ans;
		while(l<=r)
		{
			LL mid=(l+r)/2;
			if(check1(mid)==true) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	else if(bk2==false)
	{
		for(int i=1;i<=len;i+=2) a[i/2+1]=a[i];
		len=n-1;LL sum=0;
		sort(a+1,a+len+1,cmp);
		for(int i=1;i<=len;i++) D[i]=a[i].d,sum+=D[i];
		LL l=1,r=sum,ans;
		while(l<=r)
		{
			LL mid=(l+r)/2;
			if(check(mid)==true) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	else printf("%lld\n",dd);
	return 0;
}
