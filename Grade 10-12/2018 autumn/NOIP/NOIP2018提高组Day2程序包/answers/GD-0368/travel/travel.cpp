#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

int sum[5001],f[5001],las[5001],bz[5001],a[10001],b[10001];

int n,m,q,p,c;

void kp(int l,int r)
{
	int i=l,j=r,mid1=a[(l+r)/2],mid2=b[(l+r)/2];
	
	for(;i<=j;)
	{
		for(;(mid1>a[i])||((mid1==a[i])&&(mid2>b[i]));i++);
		for(;(mid1<a[j])||((mid1==a[j])&&(mid2<b[j]));j--);
		
		if(i<=j)
		{
			int t=a[i];a[i]=a[j];a[j]=t;
			t=b[i];b[i]=b[j];b[j]=t;
			
			i++;j--;
		}
	}
	
	if(l<j)kp(l,j);
	if(i<r)kp(i,r);
}

void dg(int t)
{
	bz[t]=1;
	
	for(int j=sum[t-1]+1;j<=sum[t];j++)
	{
		if(b[j]==f[t])continue;
		
		if(bz[b[j]])
		{
			if(q)continue;
			q=t;p=b[j];
			continue;
		}
		
		f[b[j]]=t;
		las[b[j]]=j;
		dg(b[j]);
	}
}

void dfs(int t)
{
	bz[t]=1;
	printf("%d ",t);
	
	for(int j=sum[t-1]+1;j<=sum[t];j++)
	{
		if(bz[b[j]])continue;
		
		dfs(b[j]);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum[a[i]]++;sum[b[i]]++;
		
		b[i+m]=a[i];a[i+m]=b[i];
	}
	
	kp(1,2*m);
	
	sum[0]=0;
	for(int i=2;i<=n;i++)
		sum[i]+=sum[i-1];
	
	if(m==n)
	{
		q=p=0;
		dg(1);
		for(int i=q;i!=p;i=f[i])
			if(i>q)c=i;
		
		b[las[c]]=q;
		for(int i=las[c];(i>sum[f[i]-1]+1)&&(b[i]<b[i-1]);i--)
		{
			int t=b[i];b[i]=b[i-1];b[i-1]=t;
		}
	}
	
	memset(bz,0,sizeof(bz));
	dfs(1);
	printf("\n");
}
