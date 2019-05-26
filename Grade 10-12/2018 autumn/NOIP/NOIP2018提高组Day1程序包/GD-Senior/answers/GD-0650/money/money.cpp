#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long t,n,q[1050],v[1050],v3[1050],v2[250050],a,ans;
long long gcd(long long a,long long s)
{
	if (a%s==0) return s;
	return gcd(s,a%s);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
		 scanf("%d",&q[j]);
		sort(q+1,q+1+n);
		if (q[1]==1) 
		{
			printf("1\n");
			continue;
		} 
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v2));
		memset(v3,0,sizeof(v3));
		a=0;
		for (int j=1;j<n;j++)
		{
			for (int k=j+1;k<=n;k++)
	    	 if (gcd(q[j],q[k])==1)
	    	 {
		    	a=q[j]*q[k]-q[j]-q[k];
		    	break;
	    	 }
	    	 if (a) break;
		}
		for (int j=1;j<=n;j++)
		 if (!v3[j])
		 for (int k=j+1;k<=n;k++)
		  if (q[k]%q[j]==0) 
		  {
		  	v[k]=1;
		  	v3[k]=1;
		  }
		 v2[0]=1; 
		for (int j=1;j<=n;j++)
		{
			if (v3[j]) continue;
			if (v2[q[j]]) v[j]=1;
			for (int k=1;k<=q[n]/q[j];k++)
			 for (int l=0;l+k*q[j]<=q[n];l++) 
			  if (v2[l]) 
			   v2[l+k*q[j]]=1;
		}
		ans=0;
		for (int j=1;j<=n;j++) ans+=v[j];
		printf("%d\n",n-ans); 
	}
	return 0;
}
