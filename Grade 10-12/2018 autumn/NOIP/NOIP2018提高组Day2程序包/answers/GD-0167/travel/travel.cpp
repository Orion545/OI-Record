#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 5000+10
using namespace std;
int n,m,a[MAXN][MAXN],r[MAXN];//二维数组模拟链表。。。 
bool c[MAXN]={false};//是否走过 ,没走过为 0，走过为1； 
int u,v;//other是另外一条路的可行点 //m=n
void dfs(int,int);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		a[u][v]=1;
		a[v][u]=1;//单向可走一次
	}
	dfs(1,1);
	for(int i=1;i<=n;++i)
		printf("%d ",r[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
void dfs(int i,int j)//i是点，j是第几个新地方 
{
	if(i==1&&j==n)
		return;
	if(!c[i])
	{
		r[j]=i;
		c[i]=true;
		if(j==n) 
			return;
		j++;
	}
	for(int k=1;k<=n;++k) 
	{
		if(a[i][k]&&c[k]==0)//能走且是新的点 
		{
			a[i][k]--;
			dfs(k,j);
		}
	}
	for(int k=1;k<=n;++k) 
	{
		if(a[i][k]&&c[k]!=0)//能走，但是是旧点 
		{
			a[i][k]--;
			dfs(k,j);
		}
	}
	return;
}
