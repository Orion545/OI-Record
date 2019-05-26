#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;
vector<long long>p[50010];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct node
{
	int x,y,c,nex;
}a[100010];int len,last[50010];
inline void ins(int x,int y,int c)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].nex=last[x];last[x]=len;
}
int n,m,f[50010];long long limit,mx[50010];
bool v[50010];
inline int erfen(int x,int r,long long w)
{
	int l=0,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(p[x][mid]>=w)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
inline void dfs(int x,int fa)
{
	for(int k=last[x];k;k=a[k].nex)
	{
		int y=a[k].y;
		if(y==fa)continue;
		dfs(y,x);
		f[x]+=f[y];
		p[x].push_back(mx[y]+a[k].c);
	}
	sort(p[x].begin(),p[x].end());
	for(int i=0;i<p[x].size();i++)v[i]=false;
	for(int i=0;i<p[x].size();i++)
	{
		int P=erfen(x,i-1,limit-p[x][i]);
		if(P!=-1)
		{
			for(int j=P;j<i;j++)if(p[x][j]+p[x][i]>=limit && v[j]==false){v[j]=v[i]=true,f[x]++;break;}
		}
		if(v[i]==false && p[x][i]>=limit)v[i]=true,f[x]++;
	}
	for(int i=p[x].size()-1;i>=0;i--)if(v[i]==false){mx[x]=p[x][i];break;}
}	
bool check(long long mid)
{
	memset(mx,0,sizeof(mx));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)p[i].clear();
	limit=mid,dfs(1,0);
	if(f[1]>=m)return true;
	else return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();long long l=1,r=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),c=read();
		ins(x,y,c),ins(y,x,c);r+=c;
	}
	long long ans;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid)==true)ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}
