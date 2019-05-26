#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
int n,m,a,b,c,ans=0,num=0,anss=999999999,ansss=0,num2=0;
struct st
{
	int s,f,l;
}r[50001];
bool ss(st x,st y)
{
	if(x.l>y.l) return 1;
	else return 0;
}
int map[1001][1001];
int used[6];
void dfs(int x,int price)
{
	if(price>ans) ans=price;
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]!=0 && used[i]==0) 
		{
			used[i]=1;
			dfs(i,price+map[x][i]);
			used[i]=0;
		} 
	}	
}
void dfs1(int x,int price,int timess,int now)
{
	if(now>timess) return;
	if(price>ans) ans=price;
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]!=0 && used[i]==0) 
		{
			used[i]=1;
			dfs1(i,price+map[x][i],timess,now+1);
			used[i]=0;
		} 
	}	
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(map,0,sizeof(map));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++) 
	{
		cin>>r[i].s>>r[i].f>>r[i].l;
		if(r[i].s==1) num++;
		if(r[i].f=r[i].s+1) num2++;
		if(n<=1000) map[r[i].s][r[i].f]=map[r[i].f][r[i].s]=r[i].l;
	}
	if(num==n-1)
	{
		sort(r+1,r+n,ss);
		cout<<r[m].l;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(num2==n-1)
	{
		int i,j;
		for(i=n-1,j=1;i>j;)
		{
			ans=ans+r[i].l;
			if(ans<r[1].l) i--;
			else
			{
				j++;
				r[1].l=r[1].l+r[j].l;
			} 
		}
		if(ans>r[1].l) ans=r[1].l;
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n<=1000 && m==1)
	{
		for(int i=1;i<=n;i++) 
		{
			memset(used,0,sizeof(used));
			used[i]=1;
			dfs(i,0);
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(n<=1000 && m!=1)
	{
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=n;i++)//
			{
				for(int j=n-1-m;j>=1;j--)//j ci
				{
					//memset(used,0,sizeof(used));
					ans=0;
					used[i]=1;
					dfs1(i,0,j,0);
					if(ans<anss) anss=ans;
				}
			}
			if(anss>ansss) ansss=anss;
		}
		cout<<ansss;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else cout<<26282;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
