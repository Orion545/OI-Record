#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
int n,m,a[100],x[100],y[100],ans[100],p[100],q[100],l[100],r[100],s[100],f[500];
string st;
void find_(int k,int s)
{
	if (k>n)
	{
		for (int i=1;i<n;i++)
		 if (f[x[i]]==0&&f[y[i]]==0)return;
		for (int i=1;i<=m;i++)
		 if (f[p[i]]==q[i]&&f[l[i]]==r[i])
		  ans[i]=min(ans[i],s);
		return;
	}
	f[k]=1;
	find_(k+1,s+a[k]);
	f[k]=0;
	find_(k+1,s);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>st;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	 scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=m;i++)
	{
     scanf("%d%d%d%d",&p[i],&q[i],&l[i],&r[i]);
     ans[i]=10000000;
 	}
    find_(1,0);
    for (int i=1;i<=m;i++)
    {
    	if (ans[i]==10000000) cout<<"-1"<<endl;
    	 else cout<<ans[i]<<endl;
    }
	return 0;
}

