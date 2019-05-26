#include <bits/stdc++.h>

using namespace std;
const long long maxn=100005;
struct data
{long long sum,maxlen;};
data f[maxn];
long long sum,l,r,mid,n,m,len,val[maxn],zan[maxn],lef,rig,mmd;
long long h,t,x,y,v,p,line[maxn],nextt[maxn],pp[maxn],to[maxn],pan[maxn];
long long fid()
{
	h=1;t=line[0];
	long long s=0;
	for (long long i=t;i>=1;i--)
	{
		while (h<n && line[h]+line[i]<len) h++;
		if (h>=i) break;
		h++;s++;
	}
	return s;
}
void dfs(long long k)
{
	pan[k]=1;
	long long pu=pp[k];
	while (pu>0)
	{
		if (pan[to[pu]]==0)
		{
			dfs(to[pu]);
		}
		pu=nextt[pu];
	}
	pu=pp[k];
	f[k].sum=0;f[k].maxlen=0;
	line[0]=0;
	while (pu>0)
	{
		if (pan[to[pu]]==0)
		{
			f[k].sum+=f[to[pu]].sum;
			if (f[to[pu]].maxlen+val[pu]<len)
			{line[0]++;line[line[0]]=f[to[pu]].maxlen+val[pu];}
			else f[k].sum++;
		}
		pu=nextt[pu];
	}
	sort(line+1,line+1+line[0]);
	zan[0]=line[0];
	for (long long i=1;i<=line[0];i++) zan[i]=line[i];
	long long num=fid();
	f[k].sum+=num;
	lef=0;rig=zan[0]+1;
	line[0]--;
	while (lef+1<rig)
	{
		mmd=(lef+rig)/2;
		for (long long i=1;i<mmd;i++) line[i]=zan[i];
		for (long long i=mmd;i<=line[0];i++) line[i]=zan[i+1];
		if (fid()<num) rig=mmd;
		else lef=mmd;
	}
	if (lef==0) f[k].maxlen=0;
	else f[k].maxlen=zan[lef];
	pan[k]=0;
}
bool check_(long long len)
{
	dfs(1);
	if (f[1].sum>=m) return true;
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;sum=1;
	for (long long i=1;i<n;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&v);
		sum+=v;
		p++;to[p]=y;nextt[p]=pp[x];pp[x]=p;val[p]=v;
		p++;to[p]=x;nextt[p]=pp[y];pp[y]=p;val[p]=v;
	}
	l=0;r=sum+1;
	while (l+1<r)
	{
		mid=(l+r)/2;
		len=mid;
		if (check_(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
