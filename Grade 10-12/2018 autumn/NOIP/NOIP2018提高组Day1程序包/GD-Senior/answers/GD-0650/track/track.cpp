#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct II
{
	int t,n,v,l;
}edge[2*50050];
long long n,m,p,h[50050],l,r,l1,r1,mid,mid1,a,s,t,q[2*50050],w[2*50050],e[2*50050],v[2*50050],v2[2*50050],maxm,cur=-1,dis[2*50050],d;
void add(int f,int t,int v)
{
	cur++;
	edge[cur].t=t;
	edge[cur].v=v;
	edge[cur].n=h[f];
	edge[cur].l=cur+1;
	h[f]=cur;
	cur++;
	edge[cur].t=f;
	edge[cur].v=v;
	edge[cur].n=h[t];
	edge[cur].l=cur-1;
	h[t]=cur;
}
bool dfs(int now)
{
	memset(dis,0,sizeof(dis));
	memset(v2,0,sizeof(v2));
	q[0]=now;
	v2[now]=1;
	s=0;
	t=1;
	while (s!=t)
	{
		for (int j=h[q[s]];j!=-1; j=edge[j].n)
		if (!v[j]&&!v2[edge[j].t])
		{
			dis[edge[j].t]=dis[q[s]]+edge[j].v;
			q[t]=edge[j].t;
			t++;
			v2[edge[j].t]=1;
			w[edge[j].t]=q[s];
			e[edge[j].t]=j;
		}
		s++;
	}
	maxm=10100000000;
	for (int j=1;j<=n;j++)
	 if (dis[j]>=mid&&dis[j]-mid<maxm)
	 {
	 	maxm=dis[j]-mid;
	 	s=j;
	 }
	if (maxm!=10100000000) 
	{
		while (s!=now)
		 {
		 	v[e[s]]=1;
		 	v[edge[e[s]].l]=1;
		 	s=w[s];
		 }
		 return true;
	} else return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) h[i]=-1;
	p=1;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&s,&d);
		add(a,s,d);
	}
	l=0; r=1000000000000;
	while (l+1<r)
	{
		mid=(l+r)/2;
		a=0;
		memset(v,0,sizeof(v));
		for (int i=1;i<=n;i++)
		if (dfs(i))
			a++;
		if (a>=m) l=mid; else r=mid;	
	}
	cout<<l;
	return 0;
}
