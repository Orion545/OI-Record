#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

struct Troute{int s,w;};

Troute a[10100];
int mp[6][6];
int ans=0;
int n,m,k;

bool _cmp(Troute a,Troute b) {return a.s<b.s;}

void dfs(int x,int y,int s,int w)
{
	if (x+1==n && y+1==m)
	{
		a[k].s=s;
		a[k++].w=w;
		return ;
	}
	if (x+1!=n)
		dfs(x+1,y,(s<<1),(w<<1)+mp[x+1][y]);
	if (y+1!=m)
		dfs(x,y+1,(s<<1)+1,(w<<1)+mp[x][y+1]);
}

int qpow(int a,int k)
{
	int ans=1;
	for (int i=0;(1<<i)<=k;i++,a=(1ll*a*a)%MOD)
		if (k&(1<<i))
			ans=(1ll*ans*a)%MOD;
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	bool f;
	scanf("%d%d",&n,&m);
	if (n==2)
	{
		printf("%lld\n",1ll*qpow(3,m-1)*4%MOD);
		return 0;
	}
	for (int s=0;s<(1<<(n*m));s++)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				mp[i][j]=((s&(1<<(i*m+j)))!=0);
		k=0;
		f=1;
		dfs(0,0,0,mp[0][0]);
		sort(a,a+k,_cmp);
	//	cerr << '\n';
		for (int i=1;i<k && f;i++)
			if (a[i].w>a[i-1].w)
				f=0;
		if (f)
		{
	//		for (int i=0;i<k;i++)
	//			cerr << a[i].s <<' ' << a[i].w << '\n';;
	//		cerr << "**\n";
			ans++;
	//		for (int i=0;i<n;i++)
	//		{
	//			for (int j=0;j<m;j++)
	//				cerr << mp[i][j] << ' ';
	//			cerr << '\n';
	//		}
	//		cerr << "--------------------\n";
		}
	}
	printf("%d\n",ans);
	return 0;
}
