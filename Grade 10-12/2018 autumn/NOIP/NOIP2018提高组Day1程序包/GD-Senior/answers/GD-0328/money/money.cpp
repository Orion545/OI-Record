#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,t2,n,m,c[100005],f[100005],a[10005],i,j,m2;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(t2=1;t2<=t;++t2)
	 {
	 	cin>>n; m=0; 
	 	memset(f,0,sizeof(f));
	 	memset(c,0,sizeof(c));
	 	
	 	for(i=1;i<=n;++i) scanf("%d",&a[i]),m=max(m,a[i]),c[a[i]]=1,f[a[i]]=2;
	 	for(i=1;i<=m;++i)
	 	 for(j=1;j<=n;++j)
	 	  if (f[i-a[j]]) 
		    {
		    f[i]=1; break;
		    }
	 	for(i=1;i<=m;++i) if (f[i]==1&&c[i]) n--;
	 	cout<<n<<endl;
	 }
	return 0;
}
