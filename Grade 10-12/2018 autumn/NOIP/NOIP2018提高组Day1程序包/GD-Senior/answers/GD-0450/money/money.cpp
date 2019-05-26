#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100+5,M=1000+5;
inline int read()
{
	int sum;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	sum=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int kx[M*M]={0};
int a[N];
int n;
inline int solve2()
{
	int bx[N]={0};
	int ans=0;
	kx[0]=1;
	for(register int i=0;i<n;++i)
	{
		kx[a[i]]=1;
		for(register int j=i+1;j<n;++j)
		{
			if(a[j]%a[i]==0)
			{
				bx[j]=-1;
			}
		}
	}
	int ggs=1,zx=0;
	for(register int i=1;i<n;++i)
	{
		if(bx[i]!=-1)
		{
			ggs+=1;
			if(!zx)zx=i;
		}
	}
	if(ggs==1)return 1;
	//int sx=a[0]*a[1]-a[0]-a[1];
	int sx=a[0]*a[zx]-a[0]-a[zx];
	for(register int i=0;i<=sx;++i)
	{
		int gs=0,qwe=0;
		for(register int j=0;j<n;++j)
		{
			if(bx[j]==-1)continue;
			register int x=i-a[j];
			if(bx[j])
			{
				while(x>=0)
				{
					if(kx[x])
					{
						kx[i]=1;
						gs=2;
						break;
					}
					x-=a[j];
				}
			}
			else
			{
				while(x>=0)
				{
					if(kx[x])
					{
						kx[i]=1;
						if(gs)
						{
							gs=2;
							break;
						}
						else
						{
							gs=1;
							qwe=j;
						}
					}
					x-=a[j];
				}
			}
			if(gs>1)
			{
				break;
			}
		}
		if(gs==1)
		{
			//cout<<i<<endl;
			bx[qwe]=1;
			ans+=1;
		}
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<bx[i]<<" ";
	}*/
	//cout<<endl;
	ans=max(ans,2);
	return ans;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		for(register int i=0;i<n;++i)
		{
			a[i]=read();
		}
		sort(a,a+n);
		memset(kx,0,sizeof(kx));
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}
		if(n==2)
		{
			if(a[1]%a[0]==0)
			{
				cout<<"1"<<endl;
			}
			else
			{
				cout<<"2"<<endl;
			}
			continue;
		}
		cout<<solve2()<<endl;
	}
	return 0;
}
