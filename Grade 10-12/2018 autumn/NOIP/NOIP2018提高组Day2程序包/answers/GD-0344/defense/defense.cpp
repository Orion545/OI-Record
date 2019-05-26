#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
long long f[303030][3];
int n,m;
int c[303030];
vector <int> a[101010];
int aa,bb,xx,yy;
long long cmpmi(long long x,long long y)
{
	if (x<y) return x;
	else return y;
}
string st;
long long anss;
void dfs(int x,int fhr)
{		  
	for (int i=0;i<a[x].size();i++)
	  {
	  	int v=a[x][i];
	  	if (v==fhr) continue;
	  	dfs(v,x);
	  }
	for (int i=0;i<a[x].size();i++)
	{
		int v=a[x][i];
		if (v==fhr) continue;
	  if (x==aa || x==bb)
		{
		  	if ((xx==0 && x==aa) || (x==bb && yy==0)) 
			  {
			    f[x][0]+=f[v][1];
			    f[x][1]=9999999999999;
			  }
		  	if ((xx==1 && x==aa) || (x==bb && yy==1))
		  	{
		  		f[x][1]+=cmpmi(f[v][0],f[v][1]);
		  		f[x][0]=9999999999999;
		  	}
		}
		  else
		  {
		  	f[x][0]+=f[v][1];
		  	f[x][1]+=cmpmi(f[v][0],f[v][1]);
	}  
	}
	f[x][1]+=c[x];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>st;
	char tt=st[0];
	if (tt=='A')
	{
	
	for (int i=1;i<=n;i++)
	  scanf("%d",&c[i]);
	for (int i=1;i<=n-1;i++)
	  {
	    int x,y;
	    scanf("%d%d",&x,&y);
	  }
	for (int i=1;i<=m;i++)
	  {
	  	int a,x,b,y;
	  	scanf("%d%d%d%d",&a,&x,&b,&y);
	  	if ((a-b==1 || b-a==1 ) && x==0 && y==0) 
		  {
		    cout<<"-1"<<endl;
		    continue;
		  }
		if (a==b && x!=y) 
		{
			cout<<"-1"<<endl;
			continue;
		} 
		memset(f,0,sizeof(f));  
		for (int i=1;i<=n;i++)
		{
		if (i==a || i==b)
		  {
		  	if ((x==0 && i==a) || (i==b && y==0)) 
			  {
			    f[i][0]=f[i-1][1];
			    f[i][1]=9999999999999;
			  }
		  	if ((x==1 && i==a) || (i==b && y==1))
		  	{
		  		f[i][1]=cmpmi(f[i-1][0]+c[i],f[i-1][1]+c[i]);
		  		f[i][0]=9999999999999;
		  	}
		  }
		  else
		  {
		  	f[i][0]=f[i-1][1];
		  	f[i][1]=cmpmi(f[i-1][0]+c[i],f[i-1][1]+c[i]);
		  } 
	    }
	    long long ans=cmpmi(f[n][0],f[n][1]);
	    cout<<ans<<endl;
	  }  
}
else
{
		for (int i=1;i<=n;i++)
	  scanf("%d",&c[i]);
	for (int i=1;i<=n-1;i++)
	  {
	    int x,y;
	    scanf("%d%d",&x,&y);
	    a[x].push_back(y);
	    a[y].push_back(x);
	  }
	for (int i=1;i<=n;i++)
	  a[i].push_back(0);  
	  
	for (int i=1;i<=m;i++)
	  {
	  	scanf("%d%d%d%d",&aa,&xx,&bb,&yy);
		memset(f,0,sizeof(f)); 
		dfs(1,0);
		anss=cmpmi(f[1][0],f[1][1]);
		if (anss>=999999999999) cout<<"-1"<<endl;
		else 
		cout<<anss<<endl;
	  }
}
	  fclose(stdin);
	  fclose(stdout);
	  return 0;
	  
}
