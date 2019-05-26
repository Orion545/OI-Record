#include<bits/stdc++.h>
using namespace std;

bool bo;

inline int rea()
{
	int x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-'))
	{
		if (ch=='A') bo=1;
		ch=getchar();
	}
	if (ch=='-') f=-1, ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48 , ch=getchar();
	return x * f;
}

typedef vector<int> ve;
vector <ve> vec(5050);
int a[100500],b[100500],n,m,t,ans;

bool chk()
{
	for (int i=1; i<=n; i++)
	{
		if (b[i]==1 || b[i]==2) continue;
		if (b[i+1]==1 || b[i+1]==2) continue;
		if (b[i-1]==1 || b[i-1]==2) continue;
		return 0;
	}
	return 1;
}

void f(int x, int v)
{
	if (x==n+1 && chk()) ans=min(ans,v);
	if (x==n+1) return;
	if (b[x]==2)
	{
		f(x+1,v+a[x]);
	}
	if (b[x]==-1)
	{
		f(x+1,v);
	}
	if (b[x]==0)
	{
		f(x+1,v);
		b[x]=1;
		f(x+1,v+a[x]);
		b[x]=0;
	}
}

void wor()
{
	for (int i=1; i<=n; i++) a[i]=rea();
	for (int i=1; i<=n-1; i++) t=rea(),t=rea();
	for (int i=1; i<=m; i++)
	{
		ans=999999999;
		int q=rea(),w=rea(),e=rea(),r=rea();
		memset(b,0,sizeof(b));
		if (w==0) b[q]=-1; else b[q]=2;
		if (r==0) b[e]=-1; else b[e]=2;
		f(1,0);
		if (ans==999999999) printf("-1\n"); else
		printf("%d\n",ans);
	}
}

bool chk1()
{
	for (int i=1; i<=n; i++)
	{
		if (b[i]==1 || b[i]==2) continue;
		int si=vec[i].size();
		bool bo=1;
		for (int j=0; j<si; j++)
			if (b[vec[i][j]]==1 || b[vec[i][j]]==2)
			{
				bo=0; break;
			}
		if (bo) return 0;
	}
	return 1;
}

void ff(int x, int v)
{
	if (x==n+1 && chk1()) 
	ans=min(ans,v);
	if (x==n+1) return;
	if (b[x]==2)
	{
		ff(x+1,v+a[x]);
	}
	if (b[x]==-1)
	{
		ff(x+1,v);
	}
	if (b[x]==0)
	{
		ff(x+1,v);
		b[x]=1;
		ff(x+1,v+a[x]);
		b[x]=0;
	}
}

void wo()
{
	for (int i=1; i<=n; i++) a[i]=rea();
	for (int i=1; i<=n-1; i++)
	{
		int x=rea(), y=rea();
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i=1; i<=m; i++)
	{
		ans=999999999;
		int q=rea(),w=rea(),e=rea(),r=rea();
		memset(b,0,sizeof(b));
		if (w==0) b[q]=-1; else b[q]=2;
		if (r==0) b[e]=-1; else b[e]=2;
		ff(1,0);
		if (ans==999999999) printf("-1\n"); else
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rea(), m=rea(), t=rea();
	if (bo) wor(); else wo();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
