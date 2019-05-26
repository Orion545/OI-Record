#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct hh{
	int num,id;
}b[100100];
long long p,n,x,ans=0;

int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}

int rd()
{
	int ans=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}

bool cmp(hh x,hh y)
{
	return x.num<y.num;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ans=0;
	n=rd();
	for(int i=1;i<=n;i++)
	{
		x=rd();
		b[i].num=x;
		b[i].id=i;
	}
	ans=0;
	sort(b+1,b+n+1,cmp);
	int m=n;
	ans=b[1].num;
	for(int i=2;i<=n;i++)
	{
		ans+=b[i].num;
		int dis=200100;
		for(int j=1;j<=i-1;j++)
			if(abs(b[i].id-b[j].id)<dis||(abs(b[i].id-b[j].id)==dis&&b[j].num>b[p].num))
			{
				dis=abs(b[i].id-b[j].id);
				p=j;
			}
		ans-=b[p].num;
	}
	cout<<ans<<endl;
}
