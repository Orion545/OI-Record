#include<bits/stdc++.h>
#define sz 50050
using namespace std;
void read(int &x)
{
	char ch=getchar();x=0;
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
int n,m;
struct hh{int t,w,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,int w)
{
	edge[++ecnt]=(hh){t,w,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,w,head[t]};
	head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
int dp[sz];
int ans[sz];
int A;
void dfs(int x,int fa)
{
	dp[x]=ans[x]=0;
	vector<int>ret;
	go(x) if (v!=fa)
	{
		dfs(v,x);dp[v]+=edge[i].w;
		if (dp[v]<A) ret.push_back(dp[v]);
		else ans[x]++;
	}
	sort(ret.begin(),ret.end());
	int _ans=0,cur=0,i;
	for (i=ret.size()-1;i>=0;i--) 
	{
		if (i<=cur) break;
		while (cur<i&&ret[cur]+ret[i]<A) ++cur;
		if (i<=cur) break;
		++_ans;++cur;
	}
	ans[x]+=_ans;
	if (_ans*2==ret.size()) return;
	int l=0,r=ret.size()-1,_ret;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		cur=0;int t=0;
		for (i=ret.size()-1;i>=0;i--)
		{
			if (i==mid) --i;
			if (i<0) break;
			while (cur<i&&ret[cur]+ret[i]<A) ++cur;
			if (cur==mid) ++cur;
			if (cur>=i) break;
			++t;++cur;
		}
		if (t==_ans) _ret=mid,l=mid+1;
		else r=mid-1;
	}
	dp[x]=ret[_ret];
}
bool judge()
{
	dfs(1,0);
	int ret=0;
	for (int i=1;i<=n;i++) ret+=ans[i];
	return ret>=m;
}
int main()
{
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	int i,x,y,z;
	read(n);read(m);
	for (i=1;i<n;i++) read(x),read(y),read(z),make_edge(x,y,z);
	int l=1,r=5e8,_out;
	while (l<=r)
	{
		int mid=(l+r)>>1;A=mid;
		if (judge()) l=mid+1,_out=mid;
		else r=mid-1;
	}
	cout<<_out;
	return 0;
}
