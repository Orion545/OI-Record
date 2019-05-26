#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,nex[100001],b[100001],c[100001],final[50001],dp[50001],q[50001],a[50001],bz[50001],d[50001];

int max(int x,int y){
	return x>y?x:y;
}

void dg1(int t,int las)
{
	int m1=0,m2=0;
	
	dp[1]=0;
	for(int j=final[t];j;j=nex[j])
	{
		if(b[j]==las)continue;
		
		dg1(b[j],t);
		
		dp[t]=max(dp[t],dp[b[j]]);
		
		if(q[b[j]]+c[j]>m1)
		{
			m2=m1;
			m1=q[b[j]]+c[j];
		}
		else m2=max(m2,q[b[j]]+c[j]);
	}
	
	dp[t]=max(dp[t],m1+m2);
	q[t]=m1;
}

void dg(int t,int las,int p)
{
	int g=0;
	
	dp[t]=0;
	for(int j=final[t];j;j=nex[j])
	{
		if(b[j]==las)continue;
		
		dg(b[j],t,p);
		dp[t]+=dp[b[j]];
		if(q[b[j]]+c[j]>=p)
			dp[t]++;
	}
	
	for(int j=final[t];j;j=nex[j])
	{
		if(b[j]==las)continue;
		
		if(q[b[j]]+c[j]<p)
			a[++g]=q[b[j]]+c[j];
	}
	
	if(!g)
	{
		q[t]=0;
		return;
	}
	
	sort(a+1,a+g+1);
	
	memset(bz,0,sizeof(bz));
	for(int i=g,j=1;i>j;i--)
	{
		for(;(j<i)&&(a[i]+a[j]<p);j++);
		
		if(j>=i)continue;
		dp[t]++;
		bz[j]=bz[i]=1;
	}
	
	for(;g&&bz[g];g--);
	
	if(g)q[t]=a[g];else q[t]=0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&b[i+n-1],&b[i],&c[i]);
		
		d[b[i+n-1]]++;d[b[i]]++;
		
		nex[i+n-1]=final[b[i]];
		final[b[i]]=i+n-1;
		nex[i]=final[b[i+n-1]];
		final[b[i+n-1]]=i;
		
		c[i+n-1]=c[i];
	}
	
	if(m==1)
	{
		dg1(1,0);
		printf("%d\n",dp[1]);
		return 0;
	}
	
	int l=1,r=1e9;
	for(;l+1<r;)
	{
		int mid=(l+r)/2;
		
		dg(1,0,mid);
		if(dp[1]>=m)l=mid;
		else r=mid-1;
	}
	
	dg(1,0,l);
	if(dp[1]>=m)printf("%d\n",l);
	else printf("%d\n",r);
}
