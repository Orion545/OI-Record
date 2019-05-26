#include<iostream>
#include<cstdio>
using namespace std;

int n;
int cf[100005];
int now,last,s=1,e=1,add,ans;
bool flag=1;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&now);
		cf[i]=now-last;
//		cout<<cf[i]<<" ";
		last=now;
	}
	while(flag)
	{
//		cout<<s<<endl;
		int minn=1000000;
		add=0;
		for(e=s;e<=n;e++)
		{
			add+=cf[e];
			if(!add)break;
			minn=min(add,minn);
		}
		cf[s]-=minn;
		cf[e]+=minn;
		ans+=minn;
		while(!cf[s])
		{
			s++;
			if(s>n)
			{
				flag=0;
				break;
			}
		}
	}
	printf("%d",ans);
}
