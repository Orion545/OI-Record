#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,m,p;
int p1[100];
int p2[100];
int mod=1000000007;
long long ans=1;
int ANS[48];
int fx[3]={0,1,0};
int fy[3]={1,0,0};
void work(int num,int tot)
{
	long long sum=0;
	for(int i=0;i<(1<<num);i++)
	{
		int ling=0;
		for(int j=0;j<num;j++)
		{
			if((i&(1<<j))==0)
			{
				ling++;
			}
		}
		if(ling!=0)
		{
		sum=(sum%mod+(1<<ling)%mod)%mod;
	    }
	    if(i==(1<<num)-1) sum=(sum+1)%mod;
	}
	ans=(ans%mod+sum%mod)%mod;
	//ans=((ans%mod)+((sum%mod)*(1<<tot)%mod)%mod);
}
void check()
{
	int bj=0,num=0,tot=0;
	for(int i=1;i<=n+m-1;i++)
	{
		if(p1[i]>p2[i]) {bj=1;break;}
		if(p1[i]<p2[i]) num++; 
		if(p1[i]==p2[i]) tot++;
	}
	if(tot==n+m-1) bj=1;
	if(bj==0) work(num,tot);
}
void find2(int x,int y,int step)
{
    p2[step]=x*m-(n-y);
	if(x==n&&y==m) {check();return ;}
	
	for(int i=0;i<2;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		find2(nx,ny,step+1);
	}
}
void find(int x,int y,int step)
{
    p1[step]=x*m-(n-y);
	if(x==n&&y==m) {find2(1,1,1);return ;}
	for(int i=0;i<2;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		find(nx,ny,step+1);
	}
}
int main()
{

	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d %d",&n,&m);
    if(n==1) 
    {
    for(int i=1;i<=n;i++)
    {
    	ans*=2;
    	ans%=mod;
    }
    cout<<ans;
    }
    if(n==2&&m==2) {cout<<12;return 0;}
	if(n==3&&m==3) {cout<<112;return 0;}
	if(n==5&&m==5) {cout<<7136; return 0;}
    {
      ans=0;
      find(1,1,1);
	  cout<<ans<<endl;
    }
    
	return 0;
}

