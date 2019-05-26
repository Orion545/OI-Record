#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,i,a,b,c[500005],s,j,f[1005][1005],s2,e[1005][1005],k;
long long oo=100000000000,h[1005][1005];
int main()
{ 
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m; s=0; s2=0;
 	for(i=1;i<n;++i) 
	 {
	 	scanf("%d%d%d",&a,&b,&c[i]);
	 	if (a!=1) s=1;
	 	if (b!=a+1) s2=1;
	 }
	if (s==0)
	 {
	 	sort(c+1,c+n);
	 	cout<<c[n-m];
	 	return 0;
	 }
	if (s2==0)
	 {
	 	for(i=0;i<n;++i)
	 	 for(j=0;j<=m;++j)
	 	  f[i][j]=oo;
	 	f[1][1]=c[1];
	 	e[1][1]=c[1];
	 	h[1][1]=1;
	 	for(i=2;i<n;++i)
	 	 for(j=1;j<=min(i,m);++j)
	 	  {
            k=min(f[h[i-1][j]-1][j-1],e[i-1][j]+c[i]); 
	 	  	if (i-1<j) k=-1;
	 	  	if (min(f[i-1][j-1],c[i])>k)
	 	  	 {
	 	  	 	f[i][j]=min(f[i-1][j-1],c[i]); e[i][j]=c[i];
	 	  	 	h[i][j]=i;
	 	  	 } else 
	 	  	 {
	 	  	 	f[i][j]=k; e[i][j]=e[i-1][j]+c[i];
	 	  	 	h[i][j]=h[i-1][j];
	 	  	 }
	 	  }
	 	cout<<f[n-1][m]<<endl;
	 	return 0;
	 }
	return 0;
}
