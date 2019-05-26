#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100;
int T,n;
int a[N+10];
bool judge(int a3,int a1,int a2)
{
	for(int i=0;a[a3]-a[a1]*i>=0;i++)
	{
		int x=a[a3]-a[a1]*i;
		if(!(x%a[a2])) return 0;
	}
	return 1;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1){printf("1\n"); continue;}
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[1]) printf("2\n");
			else printf("1\n");
			continue;
		}
		if(n==3)
		{
			if(a[2]%a[1])
			{
				if(!judge(3,1,2)) printf("2\n");
				else printf("3\n");
			}
			else if(a[3]%a[1]) printf("2\n");
			else printf("1\n");
			continue;
		}
		if(n==4)
		{
			if(a[2]%a[1])
			{
				if(!judge(3,1,2))
				{
					if(!judge(4,1,2)) printf("2\n");
					else printf("3\n");
				}
				else
				{
					if(judge(4,1,2)&&judge(4,1,3)&&judge(4,2,3)) printf("4\n");
					else printf("3\n");
				}
			}
			else if(a[3]%a[1])
			{
				if(!judge(4,1,3)) printf("2\n");
				else printf("3\n");
			}
			else if(a[4]%a[1]) printf("2\n");
			else printf("1\n");
			continue;
		}
		if(n==5)
		{
			if(a[2]%a[1])
			{
				if(!judge(3,1,2))
				{
					if(!judge(4,1,2))
					{
						if(!judge(5,1,2)) printf("2\n");
						else printf("3\n");
					}
					else
					{
						if(judge(5,1,2)&&judge(5,1,4)&&judge(5,2,4)) printf("4\n");
						else printf("3\n");
					}
				}
				else
				{
					if(judge(4,1,2)&&judge(4,1,3)&&judge(4,2,3))
					{
						if(judge(5,1,2)&&judge(5,1,3)&&judge(5,1,4)&&judge(5,2,3)&&judge(5,2,4)&&judge(5,3,4)) printf("5\n");
						else printf("4\n");
					}
					else
					{
						if(judge(5,1,2)&&judge(5,1,3)&&judge(5,2,3)) printf("4\n");
						else printf("3\n");
					}
				}
			}
			else if(a[3]%a[1])
			{
				if(!judge(4,1,3))
				{
					if(!judge(5,1,3)) printf("2\n");
					else printf("3\n");
				}
				else
				{
					if(judge(5,1,3)&&judge(5,1,4)&&judge(5,3,4)) printf("4\n");
					else printf("3\n");
				}
			}
			else if(a[4]%a[1])
			{
				if(!judge(5,1,4)) printf("2\n");
				else printf("3\n");
			}
			else if(a[5]%a[1]) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}
