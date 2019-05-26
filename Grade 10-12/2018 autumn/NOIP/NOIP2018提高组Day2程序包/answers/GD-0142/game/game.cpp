#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#define MOD 1000000007
#define LL long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
char ch[5000],str[5000];
int n,m,cnt,fac[10],ans[20][20];
int getans(int x)
{
	int ret=0,t=0;
	ret=(x&1);
	for(int i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='D')t+=m;
		else t++;
		ret<<=1;
		ret|=(x>>t&1);
	}
//	cout<<ch<<' '<<x<<' '<<ret<<endl;
	return ret;
}
LL pow(LL x,int y)
{
	LL ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m)swap(n,m);
	ans[4][4]=912;
	ans[5][5]=7136;
	ans[4][6]=8064;
	ans[4][5]=2688;
	if((n<10)&&(m<10))
	{
		if(ans[n][m])
		{
			cout<<ans[n][m]<<endl;
			return 0;
		}
	}
	if(n==1)
	{
		cout<<pow(2,m-1)<<endl;
	}
	else if(n==2)
	{
		cout<<4*pow(3,m-1)%MOD<<endl;
	}
	else if(n==3)
	{
		cout<<112*pow(3,m-3)%MOD<<endl;
	}
	else if(n==4)
	{
		cout<<2688*pow(3,m-5)%MOD<<endl;
	}
	else
	{
		for(int i=0;i<n-1;i++)str[i]='D';
		for(int i=n-1;i<n+m-2;i++)str[i]='R'; 
		fac[0]=1;
		for(int i=1;i<=n+m-2;i++)fac[i]=fac[i-1]*i;
		for(int i=0;i<(1<<(n*m-2));i++)
		{
			int pre=1e9;
			bool flag=1;
			strcpy(ch,str);
			for(int j=1;j<=fac[n+m-2]/fac[n-1]/fac[m-1];j++)
			{
				int temp=getans(i*2);
				if(pre<temp)
				{
					flag=0;
					break;
				}
				pre=temp;
				next_permutation(ch,ch+n+m-2);
			}
			if(flag)cnt++;
		}
		cout<<cnt*4<<endl;
	} 
	return 0;
}
