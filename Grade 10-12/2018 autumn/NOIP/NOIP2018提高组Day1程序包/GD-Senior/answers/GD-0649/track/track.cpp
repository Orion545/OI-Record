#include<bits/stdc++.h>

using namespace std ;

const int N=5e4+10;
struct Tedge{int v,w,nxt;}e[N*2];
int head[N],cnt,ans,n,m;
multiset<int>s[N],ss[N];
multiset<int>::iterator it;

int read()
{
	int x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar())x=x*10+(c^48);
	return x;
}

void addedge(int x,int y,int z)
{
	e[++cnt]=Tedge{y,z,head[x]};
	head[x]=cnt;
}

int dp(int x,int y,int l)
{
	s[x].clear(),ss[x].clear();
	for (int i=head[x];i;i=e[i].nxt)
		if (e[i].v!=y)
		{
			int t=dp(e[i].v,x,l)+e[i].w;
			if (t>=l) ans++; else s[x].insert(t);
		}
	for (;s[x].size()>1;)
	{
		it=s[x].begin();
		int MIN=*it;s[x].erase(it);
		it=s[x].lower_bound(l-MIN);
		if (it==s[x].end()) {ss[x].insert(MIN);continue;}
		s[x].erase(it),ans++;
	}
	int ret=0;
	if (!s[x].empty()) ret=max(*s[x].rbegin(),ret);
	if (!ss[x].empty())ret=max(*ss[x].rbegin(),ret);
	return ret;
}

bool check(int x)
{
	ans=0,dp(1,0,x);
	return ans>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w),addedge(v,u,w);
	}
	
	int l=0,r=5e8,mid;
	while (l<r)
	{
		mid=l+r>>1,mid+=(l==mid);
		if (check(mid)) l=mid;
			else		r=mid-1;
	}
	printf("%d\n",l);
	
	return 0;
}
