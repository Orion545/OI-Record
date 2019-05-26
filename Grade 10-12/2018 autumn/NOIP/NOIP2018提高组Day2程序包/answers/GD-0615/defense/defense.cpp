#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[100005],f[100005][5],u,v,p[100005],x,bb,y,b;
string type;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	if (type[0]=='A')
	  {
	  	for (int i=1;i<=n;i++)
	  	  {
	  	    cin>>a[i];
	  	    p[i]=-1;
	      }
	  	for (int i=1;i<=n-1;i++)
	  	  cin>>u>>v;
	  	for (int i=1;i<=m;i++)
	  	  {
	  	  	cin>>x>>bb>>y>>b;
	  	  	if ((x==y-1||x==y+1)&&bb==0&&b==0) {cout<<-1;continue;}
	  	  	if (x==y&&bb!=b) {cout<<-1;continue;}
	  	  	f[1][1]=a[1];f[1][0]=0;
	        for (int i=2;i<=n;i++)
	          {
	          	if (i!=x&&i!=y)
	          	  {
	      	        f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
	      	        f[i][0]=f[i-1][1];
	      	        continue;
	      	      }
	      	    if (i==x)
	      	      {
	      	      	if (bb==1) {f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];f[i][0]=9999999;}
	      	      	  else {f[i][1]=9999999;f[i][0]=f[i-1][1];}
	      	      }
	      	    if (i==y)
	      	      {
	      	      	if (b==1) {f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];f[i][0]=9999999;}
	      	      	  else {f[i][1]=9999999;f[i][0]=f[i-1][1];}
	      	      }
	          }
	        cout<<min(f[n][0],f[n][1])<<endl;
	  	  }
	  }
	return 0;
}
