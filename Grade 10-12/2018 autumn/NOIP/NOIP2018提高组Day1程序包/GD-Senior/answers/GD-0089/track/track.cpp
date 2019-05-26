#include<bits/stdc++.h>
using namespace std;
int cc,to[100100],net[100100],fr[100100],l[100100],f[100100],fa[100100],ff[100100];
int n,m,u,v,len;
void addedge(int u,int v,int len)
{
	cc++;
	to[cc]=v;net[cc]=fr[u];fr[u]=cc;l[cc]=len; 
}
void ts_1(int x)
{
	int maxx=0,max1=0;
	for (int i=fr[x];i;i=net[i])
	{
		if (to[i]==fa[x]) continue;
		int y=to[i];fa[y]=x;ts_1(y);
		if (ff[y]+l[i]>maxx) max1=maxx,maxx=ff[y]+l[i];
		else
		{
			if (ff[y]+l[i]>max1) max1=ff[y]+l[i];
		}
		f[x]=max(f[x],ff[y]+l[i]);
	}
	ff[x]=f[x];
	f[x]=max(f[x],maxx+max1);
//	cout<<x<<" "<<f[x]<<" "<<ff[x]<<endl;
}
bool check(long long x)
{
	long long sum=0,d=0;
	for (int j=1;j<=n;j++)
	{
	  for (int i=fr[j];i;i=net[i])
	  {
	    if (to[i]==j-1) continue;
	    sum+=l[i];
	    if (sum>=x) 
	    {
	    	sum=0;
	    	d++;
	    }
	  }
    }
    if (d>=m) return true; else return false;
}
int ts_2() 
{
	long long l=0,r=2147483647;
	while (l+1<r)
	{
		long long mid=(l+r)/2;
		if (check(mid)) l=mid;else r=mid;
	//	cout<<mid<<" "<<l<<" "<<r<<endl;
	}
	return l;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	bool flag1=true;
	for (int i=1;i<n;i++)
    {
    	cin>>u>>v>>len;
    	if (u>v) swap(u,v);
    	if (u!=v-1) flag1=false;
    	addedge(u,v,len);
    	addedge(v,u,len);
    }
    if (m==1) 
    {
    	ts_1(1);
    	int ans=0;
    	for (int i=1;i<=n;i++)
    	  ans=max(ans,f[i]);
    	cout<<ans<<endl;return 0;
    }
    if (flag1)
    {
    	cout<<ts_2()<<endl;
    }
	return 0;
} 
