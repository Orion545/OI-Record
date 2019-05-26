#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,sz[1005],f[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int group=1;group<=T;group++)
	  {
	  	memset(f,0,sizeof(f));
	  	memset(sz,0,sizeof(sz));
	  	scanf("%d",&n);
	  	int ans=n,ma=0;
	  	
	  	for (int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d",&sz[i]);
	  	  	ma=max(ma,sz[i]);
	  	  }
	  	sort(sz+1,sz+1+n);
	  	for (int i=1;i<=n;i++)
	  	  {
		  	if (f[sz[i]]) {ans--;continue;}
		  	f[sz[i]]=n+1;
		  	for (int j=1;j<=ma;j++)
		  	  {
		  	  	if (!f[j]||f[j]==i) continue;
		  	  	for (int k=1;j+sz[i]*k<=ma;k++) f[j+sz[i]*k]=i;
 		  	  }
	  	  }
	  	printf("%d\n",ans);
	  }
	
	return 0;
}
