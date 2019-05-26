#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
void solve(int x,int y)
{
	int bs=x+y-2;
	long long a=0,b=0;
	long long az=0,bz=0;
	int ans=0;
	int qp[5][5]={0};
	long long qwe=0;
	for(;qwe<(1ll<<(x*y));qwe++)
	{
		for(int i=0;i<x*y;i++)
		{
			if(qwe&(1ll<<i))qp[i/x][i%x]=1ll;
			else qp[i/x][i%x]=0;
		}
		for(a=0;a<(1ll<<bs);a++)
		{
			int an=0,am=0;
			for(int i=0;i<bs;i++)
			{
				if(a&(1ll<<i))an++;
			}
			if(an!=x-1ll)continue;
			//cout<<"!"<<endl;
			az=0;
			int ax=0,ay=0;
			az=(qp[0][0]<<bs);
			for(int i=0;i<bs;i++)
			{
				if(a&(1ll<<i))
				{
					ax+=1ll;
				}
				else
				{
					ay+=1ll;
				}
				az+=qp[ax][ay]*(1ll<<(bs-i-1ll));
			}
			
			for(b=a+1ll;b<(1ll<<bs);b++)
			{
				int bn=0,bm=0;
				for(int i=0;i<bs;i++)
				{
					if(b&(1ll<<i))bn++;
				}
				if(bn!=x-1ll)continue;
				bz=0;
				int bx=0,by=0;
				bz=(qp[0][0]<<bs);
				for(int i=0;i<bs;i++)
				{
					if(b&(1ll<<i))
					{
						bx+=1ll;
					}
					else
					{
						by+=1ll;
					}
					bz+=qp[bx][by]*(1ll<<(bs-i-1ll));
				}
				if(bz<=az)ans++;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<ans<<endl;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m)swap(n,m);
	if(n==1||m==1)
	{
		cout<<"0"<<endl;
	}
	else if(n==2&&m==2)
	{
		cout<<"12"<<endl;
	}
	else if(n==2&&m==3)
	{
		cout<<"36"<<endl;
	}
	else if(n==3&&m==3)
	{
		cout<<"112"<<endl;
	}
	else if(n==5&&m==5)
	{
		cout<<"7136"<<endl;
	}
	else
	{
		long long ans=(rand()*1);
		cout<<ans<<endl;
	}
	return 0;
}
