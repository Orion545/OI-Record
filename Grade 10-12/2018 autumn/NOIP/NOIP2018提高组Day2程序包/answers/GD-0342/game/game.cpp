#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n,m,sum[1010],pcnt,cou,ans,mappa[100][100];
long long modd=1000000007,thr=3;
string pth[1010],emp;
void dfs(int hng,int lie,string lu,int num)
{
	if(hng==n-1&&lie==m-1)
	{
		sum[++cou]=num;
		pth[cou]=lu;
		return;
	}
	if(lie<m-1) dfs(hng,lie+1,lu+'R',num*10+mappa[hng][lie+1]);
	if(hng<n-1) dfs(hng+1,lie,lu+'D',num*10+mappa[hng+1][lie]);
}
void tian(int hng,int lie)
{
	if(hng==n)
	{
		cou=0;
		dfs(0,0,emp,mappa[0][0]);
		int flag=0;
		for(int i=1;i<cou;i++)
		{
			for(int j=i+1;j<=cou;j++)
			{
				if(!((pth[i]<pth[j]&&sum[i]>=sum[j])||(pth[i]>pth[j]&&sum[i]<=sum[j])))
				{
					return;
				}
			}
		}
		ans=(ans+1)%modd;
		return;
	}
	int nexh=hng,nexl=lie+1;
	if(nexl==m){nexl=0;nexh++;}
	mappa[hng][lie]=0;
	tian(nexh,nexl);
	mappa[hng][lie]=1;
	tian(nexh,nexl);
}
long long ksm(ll num,ll x,ll modd)
{
	if(x==0) return 1;
	if(x==1) return num%modd;
	ll tora=ksm(num,x/2,modd)%modd;
	if(x%2==0) return (tora*tora)%modd;
	else return ((tora*tora)%modd*num)%modd;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=3&&m<=3)
	{
		tian(0,0);
		printf("%d\n",ans);
	}
	else
	{
		if(n==2)
		{
			long long prt=(4*ksm(thr,m-1,modd))%modd;
			printf("%lld\n",prt);
		}
		else 
		{
			if(n==3)
			{
				long long prt=(336*ksm(thr,m-4,modd))%modd;
				printf("%lld\n",prt);
			}
			else
			{
				tian(0,0);
				printf("%d\n",ans);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
