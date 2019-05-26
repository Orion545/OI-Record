#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define LL long long
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x)
{
	if(!x){putchar('0');return ;}
	if(x<0)putchar('-'),x=-x;
	int sta[20],top=0;
	while(x)sta[++top]=x%10,x/=10;
	while(top)putchar(sta[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(int x){write(x);putchar('\n');}
struct node{int x,y,c,next;}a[110000];int len,last[51000];
void ins(int x,int y,int c){len++;a[len].x=x;a[len].y=y;a[len].c=c;a[len].next=last[x];last[x]=len;}

int n,m;
int ok1,ok2;


int dis[51000];
void go1(int x,int fa,int du)
{
	dis[x]=du;
	for(int k=last[x];k;k=a[k].next)
		if(a[k].y!=fa)go1(a[k].y,x,du+a[k].c);
}
//task1

int dd[51000],s[51000];
bool check1(int u)
{
	memset(dd,0,sizeof(dd));
	int lu=0;
	for(int i=1;i<n;i++)
	{
		while(s[i]-s[lu+1]>=u&&lu+1<n)lu++;
		if(s[i]-s[lu]>=u)dd[i]=dd[lu]+1;
		else dd[i]=dd[lu];
	}
	return dd[n-1]>=m;
}
//task2

int tt[51000],lo;
bool cmp(int n1,int n2){return n1>n2;}
bool check2(int u)
{
	int sum=0,st=-1;
	for(int i=1;i<n;i++)
	{
		if(tt[i]>=u)sum++;
		else {st=i;break;}
	}
	if(st==-1)return sum>=m;
	int r=n-1;
	for(int i=st;i<n;i++)
	{
		if(r<=i)break;
		while(tt[i]+tt[r]<u&&r>i)r--;
		if(r==i)break;
		sum++;r--;
	}
	return sum>=m;
}
//task3

int f[51000],g[51000],vis[51000],tim;
int temp[51000],ln,lim;
void dp(int x,int fa)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)dp(y,x),f[x]+=f[y];
	}
	ln=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)temp[++ln]=g[y]+a[k].c;
	}
	int l=1,r=ln;
	sort(temp+1,temp+1+ln,cmp);tim++;
	while(temp[l]>=lim&&l<=ln)f[x]++,vis[l]=tim,l++;
	bool tf=false;
	while(l<r)
	{
		while(temp[l]+temp[r]<lim&&l<r)r--;
		if(l>=r)break;
		if(l+1==r)vis[l]=vis[r]=tim,f[x]++,l++,r--;
		else if(temp[l+1]+temp[r]<lim)vis[l]=vis[r]=tim,f[x]++,l++,r--;
		else
		{
			if(!tf&&(ln&1))g[x]=temp[l],tf=true;
			else f[x]++,vis[l]=vis[r]=tim,r--;
			l++;
		}
	}
	for(int i=1;i<=ln;i++)if(vis[i]!=tim){g[x]=temp[i];break;}
}
bool check(int u)
{
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	memset(vis,0,sizeof(vis));tim=0;
	lim=u;
	dp(1,0);
	return f[1]>=m;
}
//wa
int main()
{	
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	ok1=ok2=1;
	n=read();m=read();int sum=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),c=read();
		tt[++lo]=c;
		ins(x,y,c);ins(y,x,c);sum+=c;s[x]=c;
		if(y!=x+1)ok2=0;
		if(x!=1)ok1=0;
	}
	if(m==1)
	{
		go1(1,0,0);
		int pos=0;
		for(int i=1;i<=n;i++)if(!pos||dis[i]>dis[pos])pos=i;
		go1(pos,0,0);pos=0;
		for(int i=1;i<=n;i++)pos=max(pos,dis[i]);
		pr2(pos);
	}
	else if(ok2)
	{
		for(int i=1;i<=n;i++)s[i]+=s[i-1];
		int l=1,r=sum,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check1(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		pr2(ans);
	}
	else if(ok1)
	{
		sort(tt+1,tt+1+lo,cmp);
		int l=1,r=sum,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check2(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		pr2(ans);
	}
	else
	{
		int l=1,r=sum,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		pr2(ans);
	}
	return 0;
}

