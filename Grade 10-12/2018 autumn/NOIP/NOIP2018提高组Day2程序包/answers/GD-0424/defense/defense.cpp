#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,z;
int ans;
int f[1000001];
char a;
int q,w,e,r;
int lian()
{
	int sum=0;
	if(w==1) sum+=f[q];
	if(r==1) sum+=f[e];
	if((q==1&&w==0&&e==2&&r==0)||(q==2&&w==0&&e==1&&r==0)||(q==n&&w==0&&e==n-1&&r==0)||(q==n-1&&w==0&&e==n&&r==0))
	{
		ans=-1;
		return ans;
	}
	else
	{
		if(f[q-1]<=f[q+1]&&(q-1)>0) sum+=f[q-1];
		else sum+=f[q+1];
		if(f[e-1]<=f[e+1]&&(e-1)>0) sum+=f[e-1];
		else sum+=f[e+1];
	}
	for(int i=1;i<=n;i+=2)
	{
		if(f[i]<=f[i+1]) 
		{
			sum+=f[i];
		}
		else 
		{
			sum+=f[i+1];
			i++;
		}
	}
	return ans;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int t;
	cin>>n>>m;
	cin>>a>>t;
	for(int j=1;j<=n;j++)  
		{
			int x;
			cin>>x;
			f[j]=x;
		}
		for(int j=1;j<=n-1;j++)
		{
			int x,y;
			cin>>x>>y;
		}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=4;j++)
		{
			cin>>q>>w>>e>>r;
		}
		if(a=='A')
	{
		ans=lian();
		cout<<ans<<endl;
	}
	else cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
