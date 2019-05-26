#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
struct node{
	int x,y,d,next;
}a[1110000];int len,last[510000];
void ins(int x,int y,int d)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].d=d;
	a[len].next=last[x];last[x]=len;
}
int n,m;
int d[310000];
void dfs(int x,int fa)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			d[y]=d[x]+a[k].d;
			dfs(y,x);
		}
	}
}
bool check(int mid)
{
	int sum=m;
	int x=1;int s=0;
	while(x!=n)
	{
		for(int k=last[x];k;k=a[k].next)
		{
			if(a[k].y==x-1)continue;
			s+=a[k].d;
			if(s>=mid)s=0,sum--;
		}
		x++;
	}
	
	if(sum>0)return false;
	return true;
}
int X;
int maxx[510000],maxlu[510000];
int list[510000],PD[510000];
void treedp(int x,int fa)
{
	
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			treedp(y,x);
			if(maxlu[y]+a[k].d>=X)maxx[x]++;
			maxx[x]+=maxx[y];
		}
	}
	int cnt=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa&&maxlu[y]+a[k].d<X)
			list[++cnt]=maxlu[y]+a[k].d,PD[cnt]=1;
	}
	sort(list+1,list+1+cnt);
	int L=1,R=cnt;int s=0;
	while(L<R)
	{
		while(list[L]+list[R]>=X&&L<R)R--,s++;
		
		if(s)
		{
			int j=R+1;
			while(!PD[j])j++;
			L++,s--,maxx[x]++,PD[j]=0;PD[L]=0;
		}
		else L++;
	}
	if(s>0)
	{
		maxx[x]+=s/2;
		if(s%2==0){maxlu[x]=0;return ;}
	}
	for(int i=1;i<=cnt;i++)if(PD[i])maxlu[x]=max(maxlu[x],list[i]);
}
bool Check(int mid)
{
	X=mid;
	memset(maxx,0,sizeof(maxx));
	memset(maxlu,0,sizeof(maxlu));
	treedp(1,0);
	if(maxx[1]>=m)return true;
	return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool pd=true;
	n=read(),m=read();
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y,d;
		x=read();y=read();d=read();
		ins(x,y,d);ins(y,x,d);
		if(y!=x+1)pd=false;
	}
	if(m==1)
	{
		d[1]=0;dfs(1,0);
		int maxx=0,pos;
		for(int i=2;i<=n;i++)if(d[i]>maxx)maxx=d[i],pos=i;
		d[pos]=0;dfs(pos,0);
		for(int i=1;i<=n;i++)if(d[i]>maxx)maxx=d[i];
		printf("%d\n",maxx);
		return 0;
	}
	if(pd)
	{
		int l=0,r=1<<30;int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	int ans;
	int l=0,r=1<<30;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(Check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
