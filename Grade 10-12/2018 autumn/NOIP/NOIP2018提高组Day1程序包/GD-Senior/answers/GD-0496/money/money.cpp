#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int T,n,num=0,k,o=0;
int a[101];
int used[25001];
int ggg[101];
int gg[101];
int g(int x,int y)
{
	if(y==0) return x;
	else return g(y,x%y);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money","w",stdout);
	scanf("%d",&T);
	memset(used,0,sizeof(used));
	memset(gg,0,sizeof(gg));
	memset(ggg,0,sizeof(ggg));
	for(int i=2;i<=sqrt(25000)+1;i++)
	{
		if(used[i]==0)
			for(int j=i+i;j<=25000;j=j+i) used[j]=1;
	}
	while(T>=1)
	{
		memset(gg,0,sizeof(gg));
		memset(ggg,0,sizeof(ggg));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		o=num=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(a[i]==1) num++;
		}
		sort(a+1,a+n+1);
		if(num!=0) printf("1\n");
		else if(num==0 && n==2)
		{
			if(a[2]%a[1]==0) printf("1\n");
			else printf("%d\n",n);
		}
		else if(num==0 && n>2)
		{
			for(int i=1;i<=n;i++) if(used[a[i]]==1) num++;
			if(num==0) printf("%d\n",n);
			else
			{
				num=0;
				for(int i=1;i<=n-1;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						k=g(a[i],a[j]);
						if(k==1)
						{
							if(ggg[i]==0) 
							{
								ggg[i]=1;
								num++;
							}
							if(ggg[j]==0) 
							{
								ggg[j]=1;
								num++;
							}
						}
						else if(k==a[i] && gg[j]==0) 
						{
							gg[j]=1;
							o--;
						}
					}
				}
				if(num==n) printf("%d\n",n);
				else printf("%d\n",n+o);
			}
		}
		T--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
