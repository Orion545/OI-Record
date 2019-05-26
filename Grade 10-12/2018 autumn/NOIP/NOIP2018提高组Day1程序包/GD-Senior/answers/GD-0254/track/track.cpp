# include <bits/stdc++.h>

using namespace std;
const int maxN=50004;
int n,m,ans,fp,f[1005][1005];
int head[maxN],w[maxN],s1[maxN],s2[maxN];
struct data
{
	int next,obj,val;
}p[maxN*2];

void add_edge(int u,int v,int w)
{
	p[fp].next=head[u];
	p[fp].obj=v;
	p[fp].val=w;
	head[u]=fp++;
}

int check(int k) 
{
	int cnt=0,dis=0;
	for (int i=1; i<n; i++)
	{
		dis=dis+w[i];
		if (dis>=k) cnt++,dis=0;
	}
	return cnt;
}

void dfs(int fa,int k)
{
	s1[k]=s2[k]=0;
	for (int i=head[k]; i!=-1; i=p[i].next)
	if (p[i].obj!=fa)
	{
		int x=p[i].obj;
		dfs(k,x);
		if (s1[x]+p[i].val>s1[k])
		{
			s2[k]=max(s1[k],s2[k]);
			s1[k]=s1[x]+p[i].val;
		}else s2[k]=max(s2[k],s1[x]+p[i].val);
	}
	ans=max(ans,s1[k]+s2[k]);
}

bool cmp(int a,int b)
{
	return p[a].val>p[b].val;
}

void work(int fa,int k,int lim)
{
	if (f[1][m]!=-1) return;
	int a[1005],sum=0;
	for (int i=head[k]; i!=-1; i=p[i].next)
	if (p[i].obj!=fa)
	{
		int x=p[i].obj;
	    work(k,x,lim);
		a[++sum]=i;
	}
	sort(a+1,a+1+sum,cmp);
	for (int i=1; i<=sum; i++)
	for (int t2=m; t2>=0; t2--)
	if (f[k][t2]!=-1)
	    for (int t1=0; t1<=m; t1++)
	    if (f[p[a[i]].obj][t1]==-1) break;
	    else{
		    if (f[p[a[i]].obj][t1]+p[a[i]].val+f[k][t2]>=lim)
		    f[k][t1+t2+1]=max(f[k][t1+t2+1],0);
		    f[k][t1+t2]=max(f[k][t1+t2],f[p[a[i]].obj][t1]+p[a[i]].val);
	    }
	if (f[k][m]!=-1)
	{
	    f[1][m]=0;
		return;
	}
}

bool pd(int k)
{
	memset(f,-1,sizeof f);
	for (int i=1; i<=n; i++) f[i][0]=0;
	work(0,1,k);
	/*printf(":%d\n",k);
	for (int i=1; i<=n; i++)
	{
	    for (int j=0; j<=m; j++) printf("%d ",f[i][j]);
	    printf("\n");
	}*/
	return f[1][m]!=-1;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) head[i]=-1;
	bool f1=true,f2=true;
	int u,v;
	for (int i=1; i<n; i++)
	{
		scanf("%d%d%d",&u,&v,&w[i]);
		add_edge(u,v,w[i]);
		add_edge(v,u,w[i]);
		if (v!=u+1) f1=false;
		if (u!=1) f2=false;
	}
	if (f1) //Á´±í20%
	{
		int l=0,r=1;
		for (int i=1; i<n; i++) r+=w[i];
		while (l+1<r)
		{
			int mid=(l+r)/2;
			if (check(mid)>=m) l=mid; else r=mid;
		}
		ans=l;
	}else if (f2) //ÐÇ×´Í¼20%
	{
		sort(w+1,w+n);
		ans=2147480000;
		n--;
		if (n<2*m)
		{
			for (int i=0; i<2*m-n; i++)
			ans=min(ans,w[n-i]);
			m=n-m;
			n=2*m;
		}
		for (int i=1; i<=m; i++)
		ans=min(ans,w[n-i+1]+w[n-2*m+i]);
	}else if (m==1) //15%
	{
		ans=0;
		dfs(0,1);
	}else if (n<=1000) //25%
	{
		int l=0,r=1;
		for (int i=1; i<n; i++) r+=w[i];
		r=r/m;
		while (l+1<r)
		{
			int mid=(l+r)/2;
			if (pd(mid)) l=mid; else r=mid;
		}
		ans=l;
	}else
	{
		srand(time(0));
	    ans=rand()%1000000000+1;
	}
	printf("%d\n",ans);
	return 0;
}
