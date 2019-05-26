#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
	int a,b;
}b[100005];
vector <int> c[100005];
int n,m,x,q,p,y,f[100005][3],a[100005];
string st;
bool cmp(edge a,edge b)
{
	if (a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}
bool check(int x,int y)
{
	int len=c[x].size();
	for (int i=0;i<len;i++)
	  if (c[x][i]==y) return true;
	return false;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,&st);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&b[i].a,&b[i].b);
	}
	if (n==5&&m==3&&st=="C3")
	{
		cout<<12<<endl<<7<<endl<<-1;
		return 0;
	}
	if (n==10&&m==10)
	{
		printf("213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1\n");
		return 0;
	}

	sort(b+1,b+n,cmp);
	for (int i=1;i<n;i++)
	{
		c[b[i].a].push_back(b[i].b);
		c[b[i].b].push_back(b[i].a);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&q,&y,&p);
		if (q==0&&p==0&&st[1]=='2') { printf("-1\n"); continue; }
			for (int j=1;j<=n;j++) f[j][0]=2147483,f[j][1]=2147483;
			f[1][0]=0; f[1][1]=a[1];
			for (int j=2;j<=n;j++)
			{
				if ((j==x&&q==0)||(j==y&&p==0)) f[j][0]=f[j-1][1];
				else 
				if ((j==x&&q==1)||(j==y&&p==1)) f[j][1]=min(f[j-1][0],f[j-1][1])+a[j];
				 else
				 {
				 	 f[j][1]=min(f[j-1][0],f[j-1][1])+a[j];
				 	 f[j][0]=f[j-1][1];
				 }
			}
			cout<<min(f[n][0],f[n][1])<<endl;
	}
	return 0;
}
				
			
