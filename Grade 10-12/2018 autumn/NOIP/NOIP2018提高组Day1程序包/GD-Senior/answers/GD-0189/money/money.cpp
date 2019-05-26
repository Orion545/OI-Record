#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define min(a,b) (((a)<(b))?(a):(b))
#define maxn 110
#define maxm 25010
using namespace std;
long ans,n,a[maxn];
bool v[maxm];

//bool cmp(long a,long b) {return a>b;}

long gcd(long a,long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

void check(long x,long y,long r)
{
	long i,j;
	for(i=y+1;i<=r;i++)
		if (v[a[i]])
			for(j=1;j<=a[i]/a[j];j++)
				if ((a[i]-j*a[y])%a[x]==0) 
				{	
					v[a[i]]=false; 
					ans--; 
					break;
				}
}

void jian()
{
	long i,j,k;
	for(i=0;i<=a[n]/a[2];i++)
	{
		if (i*a[2]>a[n]) break;
		for(j=0;j<=a[n]/a[3];j++)
		{
			if (i*a[2]+j*a[3]>a[n]) break;
			if ((a[4]-(i*a[2]+j*a[3]))%a[1]==0&&v[a[4]]) {ans--; v[a[4]]=false;}
			if (n==5)
				for(k=0;k<=a[n]/a[4];k++)
				{
					if (i*a[2]+j*a[3]+k*a[4]>a[n]) break;
					if ((a[5]-(i*a[2]+j*a[3]+k*a[4]))%a[1]==0&&v[a[5]]) {ans--; v[a[5]]=false;}
				}
		}
	}
}


int main()
{
	long T,i,j,k,l,t;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%ld",&T);
	while (T--)
	{
		scanf("%ld",&n);
		ans=n;
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			v[a[i]]=true;
		}
		bool flag=false;
		for(i=1;i<=n;i++)
			if (a[i]==1) flag=true;
		if (flag) {printf("1\n"); continue;}
		sort(a+1,a+n+1);
		for(i=1;i<n;i++)
			if (v[a[i]])
				for(j=i+1;j<=n;j++)
					if (v[a[j]]&&a[j]%a[i]==0)
					{
						v[a[j]]=false;
						ans--;
					}
		if (n==4||n==5) {jian(); printf("%ld\n",ans); continue;}
		for(i=1;i<n;i++)
			if (v[a[i]])
				for(j=i+1;j<=n;j++)
					if (v[a[j]])
					{
						l=~(1<<31);
						t=a[i]*a[j]-a[i]-a[j];
						for(k=j+1;k<=n;k++)
							if (a[k]>t) {l=k; break;}
						for(k=l;k<=n;k++)
							if (v[a[k]]) {v[a[k]]=false; ans--;}
						check(i,j,min(l-1,n));
					}
		printf("%ld\n",ans);
		/*printf("\n");
		for(i=1;i<=n;i++)
			if (v[a[i]]) printf("%ld ",a[i]);
		printf("\n");*/
	}
	return 0;
}
