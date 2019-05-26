#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[150],b[150],ans,n,sum,tot,tot1,made[1048576];
bool check[30000];

void dfs(int k)
{
	if(k==n+1)
	{
		if(sum!=0)
			made[++tot]=sum;
		return;
	}
	else
	{
		sum+=b[k];
		dfs(k+1);
		sum-=b[k];
		dfs(k+1);
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T,maxn=-1;
	scanf("%d",&T);
	while(T--)
	{
		maxn=-1;
		memset(check,false,sizeof(check));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]!=0&&a[i]!=0&&a[j]%a[i]==0)
					a[j]=0;
		for(int i=1;i<=n;i++)
			check[a[i]]=true;
		tot=sum=n=0;
		for(int i=1;i<=maxn;i++)
			if(check[i])
				b[++n]=i;
				
		dfs(1);
		
//		for(int i=1;i<=tot;i++)
//			printf("%d ",made[i]);
//		puts("");
		
		memset(check,false,sizeof(check));
		check[0]=true;
		for(int i=1;i<=n;i++)
		{
			int p=1;
			while(b[i]*p<=maxn)
			{
				check[b[i]*p]=true;
				p++;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=tot;j++)
			{
				if(made[j]>=b[i])
					continue;
				if(check[b[i]-made[j]])
					b[i]=0;
			}
		
		int ans=0;
		for(int i=1;i<=n;i++)
			if(b[i]!=0)
			{
//				printf("%d\n",b[i]);
				ans++;
			}
		printf("%d\n",ans);
	}
}
