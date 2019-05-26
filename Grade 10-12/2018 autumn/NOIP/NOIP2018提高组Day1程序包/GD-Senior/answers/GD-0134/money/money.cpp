#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,l,t,g[110];
bool v[25010];
int gcd(int x,int y)
{
	if(y) return gcd(y,x%y);
	return x;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++) scanf("%d",&g[i]);
		if(n<2)
		{
			printf("%d\n",n);
			continue;
		}
		sort(g,g+n);
		m=1;
		v[0]=1;
		l=g[n-1];
		for(int i=g[0];i<=l;i=i+g[0]) v[i]=1;
		for(int i=1;i<n;i++)
		{
			if(g[i]>l) break;
			if(v[g[i]]) continue;
			m++;
			for(int j=0;j<i;j++)
			{
				if(gcd(g[i],g[j])!=1) continue;
				if(g[i]*g[j]-g[i]-g[j]<l) l=g[i]*g[j]-g[i]-g[j];
			}
			for(int j=0;j<=l;j++)
			{
				if(!v[j]) continue;
				for(int a=j+g[i];a<=l;a=a+g[i]) v[a]=1;
			}
		}
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
