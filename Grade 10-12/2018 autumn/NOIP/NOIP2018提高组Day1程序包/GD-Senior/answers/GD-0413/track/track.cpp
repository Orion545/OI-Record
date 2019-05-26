#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
priority_queue <long long> p,q;
int Head[50001],Next[100001],To[100001],Len[100001],t;
set <long long> rd[50001];
map <long long,int> dr[50001];
long long ans,tot,mid;
void add(int a,int b,int c)
{
	Next[++t]=Head[a];
	Head[a]=t;
	To[t]=b;
	Len[t]=c;
}
long long dfs(int u,int f)
{
	long long mx1,mx2;
	mx1=mx2=0;
	for (int i=Head[u];i;i=Next[i])
		if (To[i]!=f)
		{
			long long s;
			s=dfs(To[i],u)+Len[i];
			if (s>mx1) mx2=mx1,mx1=s;
			else if (s>mx2) mx2=s;
		}
	ans=max(ans,mx1+mx2);
	return mx1;
}
long long dfss(int u,int f)
{
	dr[u].clear();
	for (int i=Head[u];i;i=Next[i])
		if (To[i]!=f)
		{
			long long s;
			s=dfss(To[i],u)+Len[i];
			if (s>=mid) ans++;
			else rd[u].insert(s),dr[u][s]++;
		}
	set <long long> :: iterator	it;		
	long long mxl=0,p;
	while (!rd[u].empty())
	{
		p=*rd[u].begin();
		dr[u][p]--;
		if (!dr[u][p]) rd[u].erase(p);	
		it=rd[u].lower_bound(mid-p);
		if (it!=rd[u].end())
		{
			ans++;
			dr[u][*it]--;
			if (!dr[u][*it]) rd[u].erase(*it);
		}
		else mxl=max(mxl,p);
	}
	return mxl;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,a,b,c;
	bool is1=true,is2=true;
	scanf("%d %d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		tot+=c;
		if (a!=1) is1=false;
		if (b!=a+1) is2=false;
		add(a,b,c);
		add(b,a,c);
	}
	if (is1)
	{
		for (int i=0;i<m;i++) q.push(0);
		for (int i=Head[1];i;i=Next[i]) p.push(Len[i]);
		for (int i=1;i<n;i++)
		{
			a=q.top();
			q.pop();
			q.push(a-p.top());
			p.pop();
		}
		printf("%lld",-q.top());
	}
	else if (m==1)
	{
		dfs(1,0);
		printf("%lld",ans);
	}
	else if (is2)
	{
		long long l=1,r=tot+1,st,bf,curr,pt,tt;
		for (int i=1;i<=n;i++)
			if (!Next[Head[i]])
			{
				st=i;
				break;
			}
		while (l+1<r)
		{
			mid=((r-l)>>1)+l;
			bf=pt=tt=0; curr=st;
			for (int sss=1;sss<n;sss++)
			{
				for (int i=Head[curr];i;i=Next[i])
					if (To[i]!=bf)
					{
						bf=curr;
						curr=To[i];
						tt+=Len[i];
						if (tt>=mid)
						{
							tt=0;
							pt++;
						}
						break;
					}	
			}
			if (pt>=m) l=mid;
			else r=mid;
		}
		printf("%lld",l);
	}
	else
	{
		long long l=1,r=tot+1;
		while (l+1<r)
		{
			mid=((r-l)>>1)+l;
			ans=0;
			dfss(1,0);	
			if (ans>=m) l=mid;
			else r=mid;
		}
		printf("%lld",l);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
