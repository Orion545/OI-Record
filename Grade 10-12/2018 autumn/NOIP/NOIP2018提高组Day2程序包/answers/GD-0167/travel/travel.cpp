#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 5000+10
using namespace std;
int n,m,a[MAXN][MAXN],r[MAXN];//��ά����ģ���������� 
bool c[MAXN]={false};//�Ƿ��߹� ,û�߹�Ϊ 0���߹�Ϊ1�� 
int u,v;//other������һ��·�Ŀ��е� //m=n
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
		a[v][u]=1;//�������һ��
	}
	dfs(1,1);
	for(int i=1;i<=n;++i)
		printf("%d ",r[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
void dfs(int i,int j)//i�ǵ㣬j�ǵڼ����µط� 
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
		if(a[i][k]&&c[k]==0)//���������µĵ� 
		{
			a[i][k]--;
			dfs(k,j);
		}
	}
	for(int k=1;k<=n;++k) 
	{
		if(a[i][k]&&c[k]!=0)//���ߣ������Ǿɵ� 
		{
			a[i][k]--;
			dfs(k,j);
		}
	}
	return;
}
