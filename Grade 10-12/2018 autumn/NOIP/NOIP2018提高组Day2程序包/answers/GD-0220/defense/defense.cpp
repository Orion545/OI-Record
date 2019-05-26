#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p[100001],bian[100001],a,b,x,y,ans=0;
int main()
{
	char ask[5];
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>ask;
	p[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n-1;i++)
		scanf("%d %d",&x,&y);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if(ask[0]=='A')
		{
			if(x==0)
				p[a]=199999;
			if(y==0)
				p[b]=199999;
			if((b==a+1||a==b+1)&&x==0&&y==0)
				printf("-1\n");
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(i==a&&x==1)
						ans+=p[a];
					else
					{
						if(i==a-1&&x==1)
						{
							ans+=p[a];
							i++;
						}
						else
						{
							if((i==b||i==b-1)&&y==1)
							ans+=p[b];
							else
							{
								if(i==b-1&&y==1)
								{
									ans+=p[b];
									i++;
								}
								else
								{
									if(i==a-2&&x==1)
									{
										ans+=p[i]+p[a];
										i+=2;
									}
									else
									{
										if(i==b-2&&y==1)
										{
											ans+=p[i]+p[b];
											i+=2;
										}
										else
										{
											if(p[i]+p[i+2]<p[i+1])
											{
												ans+=p[i]+p[i+2];
												i+=2;
											}
											else
											{
												ans+=p[i+1];
												i++;
											}
										}
									}
								}
							}
						}
					}
				}
				printf("%d\n",ans);
			}
		}
		else
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
