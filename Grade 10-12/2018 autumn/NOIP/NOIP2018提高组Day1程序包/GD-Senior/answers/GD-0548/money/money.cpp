#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int a[maxn];
int flag=1;	
int t,n,ans,sum,now,flag1=1;

bool cmp(int a,int b)
{
	return a<b;
}

void dfs(int num,int x,int k,int tot,int pos)
{
	if(!flag1)
	return ;
	int cal=tot;
	tot+=a[x]*k;
	if(tot>a[pos]||x>num)
	return ;
	if(tot==a[pos])
	{
		for(int i=pos;i<ans;i++)
			a[i]=a[i+1];
		ans--;
		flag1=0;
		return ;
	}
	dfs(num,x+1,0,tot,pos);
	dfs(num,x,k+1,cal,pos);
	return ;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=n;
		sum=1;
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		/*for(int i=2;i<=n;i++)
		{
		    if(a[i]%a[1]==0) 
			{
				for(int j=i;j<=ans;i++)
				a[j]=a[j+1];
				ans--;
			}
		}*/
		while(flag)
		{
			for(int i=ans;i>=sum+1;i--)
			{
				now=a[i];
				for(int j=sum;j>=1;j--)
				{
				   if(now!=0)
				      now=now%a[j];
				}
				if(now==0)
				{
					
					for(int j=i;j<ans;j++)
				    a[j]=a[j+1];
				    ans--;
				}
			}
			if(ans==sum)
			break;
			int yu=ans;
			int yo=sum;
			for(int i=yu;i>yo;i--)
			{
				flag1=1;
				dfs(yo,1,0,0,i);
			}
			
			if(ans==sum)
			break;
			sum++;
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 1;
}
