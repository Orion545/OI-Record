# include <bits/stdc++.h>

using namespace std;
const int maxN=100005;
int n,m,a,x,b,y,c[maxN],f[maxN][2],g[maxN][2],fa[maxN];
vector<int> p[maxN];

void dfs(int last,int k)
{
	fa[k]=last;
	bool flag=true;
	for (int i=0; i<p[k].size(); i++)
	if (p[k][i]!=last) dfs(k,p[k][i]),flag=false;
	if (!(a==k && x==0) && !(b==k && y==0))
	{
	    f[k][1]=c[k];
	    for (int i=0; i<p[k].size(); i++)
	    if (p[k][i]!=last)
		{
			int x=p[k][i];
			if (max(f[x][1],f[x][0])==-1)
			{
				f[k][1]=-1;
			    break;
			}else if (f[x][0]==-1) f[k][1]+=f[x][1];
			else if (f[x][1]==-1) f[k][1]+=f[x][0];
			else f[k][1]+=min(f[p[k][i]][1],f[p[k][i]][0]);
		}
	}
	if (!(a==k && x==1) && !(b==k && y==1))
	{
		f[k][0]=0;
		for (int i=0; i<p[k].size(); i++)
	    if (p[k][i]!=last)
		{
		    if (f[p[k][i]][1]==-1)
			{
				f[k][0]=-1;
			    break;
			}
			else f[k][0]+=f[p[k][i]][1];
		}
	}
}

void work(int k,int wh)
{
	if (k==0) return;
	g[k][1]=c[k];
	for (int i=0; i<p[k].size(); i++)
	if (p[k][i]!=fa[k])
	{
		int x=p[k][i];
		if (max((x==wh?g[x][1]:f[x][1]),(x==wh?g[x][0]:f[x][0]))==-1)
		{
			g[k][1]=-1;
		    break;
		}else if ((wh?g[x][0]:f[x][0])==-1) g[k][1]+=(x==wh?g[x][1]:f[x][1]);
		else if ((x==wh?g[x][1]:f[x][1])==-1) g[k][1]+=(x==wh?g[x][0]:f[x][0]);
		else g[k][1]+=min((x==wh?g[x][1]:f[x][1]),(x==wh?g[x][0]:f[x][0]));
	}
	g[k][0]=0;
	for (int i=0; i<p[k].size(); i++)
	if (p[k][i]!=fa[k])
	{
		if ((p[k][i]==wh?g[p[k][i]][1]:f[p[k][i]][1])==-1)
		{
			g[k][0]=-1;
			break;
		}else g[k][0]+=(p[k][i]==wh?g[p[k][i]][1]:f[p[k][i]][1]);
	}
	work(fa[k],k);
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	string op;
	cin>>op;
	for (int i=1; i<=n; i++) scanf("%d",&c[i]);
	int u,v;
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&u,&v);
		p[u].push_back(v);
		p[v].push_back(u);
	}
	int ans;
	if (n<=2000)// 11/25
	for (int i=1; i<=m; i++)
	{
		memset(f,-1,sizeof f);
		scanf("%d%d%d%d",&a,&x,&b,&y);
		dfs(0,1);
		if (f[1][0]==-1 && f[1][1]==-1) ans=-1;
		else if (f[1][0]==-1) ans=f[1][1];
		else if (f[1][1]==-1) ans=f[1][0];
		else ans=min(f[1][0],f[1][1]);
		printf("%d\n",ans);
	}else if (op=="A1") //2/25
	{
		f[1][1]=c[1]; f[1][0]=2147480000;
		for (int i=2; i<=n; i++)
		f[i][1]=c[i]+min(f[i-1][0],f[i-1][1]),
		f[i][0]=f[i-1][1];
		for (int i=n; i>=1; i--)
		g[i][1]=c[i]+min(g[i+1][0],g[i+1][1]),
		g[i][0]=g[i+1][1];
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			ans=0;
			if (!y) ans=f[b-1][1]+g[b+1][1];
			else ans=min(f[b][1]+min(g[b+1][0],g[b+1][1]),min(f[b-1][0],f[b-1][1])+g[b][1]);
			printf("%d\n",ans);
		}
	}else if (op=="A2") // 3/25
	{
		for (int i=1; i<=n; i++)
		f[i][1]=c[i]+min(f[i-1][0],f[i-1][1]),
		f[i][0]=f[i-1][1];
		for (int i=n; i>=1; i--)
		g[i][1]=c[i]+min(g[i+1][0],g[i+1][1]),
		g[i][0]=g[i+1][1];
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if (!x && !y) printf("-1\n");
			else{
				if (a>b) swap(a,b);
				printf("%d\n",f[a][x]+g[b][y]);
			}
		}
	}else if (op[2]=='1') //5/25
	{
		a=b=x=y=1;
		dfs(0,1);
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if (!x && !y) printf("-1\n");
			else
			{
				int temp=f[b][y^1];
				g[b][y^1]=f[b][y^1]=-1;
			    work(fa[b],b);
			    f[b][y^1]=temp;
			    printf("%d\n",g[1][1]);
			}
		}
	}
	return 0;
}
