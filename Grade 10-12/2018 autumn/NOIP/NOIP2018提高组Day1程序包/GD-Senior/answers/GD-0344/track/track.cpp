#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
using namespace std;
struct data
{
	long long mx,sx;
}f[50505];
vector <int> a[50505],b[50505];
int n,m;
int c[50505],r[50505];
long long dfs(int x,int father)
{
	for (int i=0;i<a[x].size();i++)
	  {
	  	int v=a[x][i];
	  	int r=b[x][i];
	  	if (v==father) continue;
	  	long long u=dfs(v,x);
	  	if (u+r>f[x].mx) 
		  {
		    f[x].sx=f[x].mx;
	        f[x].mx=u+r;
	      }
		else if (u+r>f[x].sx) f[x].sx=u+r; 
	  	
	  }
	return f[x].mx;
} 
bool cmp(int x,int y)
{
	return (x>y);
}
bool check(long long mid)
{
	long long add=0;
	int k=0;
	for (int i=1;i<=n-1;i++)
	  if (add>=mid) 
	  {
	  	k++;
	  	add=0;
	  	if (k==m) return true;
	  }else add+=r[i];
	  
    add=0;
	k=0;
	for (int i=n-1;i>=1;i--)
	  if (add>=mid) 
	  {
	  	k++;
	  	add=0;
	  	if (k==m) return true;
	  }else add+=r[i];  
	return false;  
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool sym=true;
	long long ans=999999999;
	long long xx=0;
    for (int i=1;i<=n-1;i++)
	  {
		  	int x,y,z;
		  	scanf("%d%d%d",&x,&y,&z);
		  	a[x].push_back(y);
		  	a[y].push_back(x);
		  	b[x].push_back(z);
		  	b[y].push_back(z);
		  	r[x]=z;
		  	c[i]=z;
		  	xx+=z;
		  	if (y-1!=x) sym=false;
		  	if (z<ans) ans=z;
	  }
	if (m==1)
	{
		a[0].push_back(1);
		b[0].push_back(0);
		long long k=dfs(0,0);
		long long ans=0;  
		for (int i=1;i<=n;i++)
		  if (f[i].mx+f[i].sx>ans) ans=f[i].mx+f[i].sx;
		cout<<ans<<endl;
	}else
	if (m==n-1)
	{
		cout<<ans<<endl;
	}else
	if (2*m>n)
	{
	  	sort(c+1,c+n+1,cmp);  
		cout<<c[m]<<endl;
	}else
	{
	   xx=xx/m;
	   cout<<xx<<endl;	  
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
