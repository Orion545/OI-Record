#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[25010],b[25010];
//a是数组排序,b是桶排,c是点亮图板,d是搜寻
bool c[25010],d[101][25010];
int ans;
void dfs(int y,int x,int n,int m)
//点亮起点,点亮终点,题目个数,搜寻个数 
{
	//取该点探索 
	d[m][y]=true;
	if(y<=x)
	for(int i=y;i<=x;)
	{
		if(c[y]==0)return;//该点覆盖未点亮区域 
		i+=y;
		if(y>x)//探索正确 
		{
			for(int i=y;i<=x;i++)
			{
				if(i%y==0)d[m][y]=1;
				else d[m][y]=0;
			}//得到该点模板 
			
			for(int j=0;j<=a[n-1];j++)//检测点亮覆盖相同吗 
			{
				int f=0;
				//在所有搜索模板中是否有符合 
				for(int k=0;k<=m;k++)
				if(d[k][j]==c[j])f=1;
				if(f==0)break;
				f=0;
				
				if(j==a[n-1])//完全相同,得到答案 
				{
					ans=m;
					return;
				}
			}
			
			//
			if(n==m+1)return;
			else dfs(y+1,x,n,m+1);
		}
	}
	else return;
	//放弃该点探索 
	d[m][y]=false;
	dfs(y+1,x,n,m);
}
void cal()
{
	//输入
	int n,x;
	cin>>n;
	ans=n;
	int c[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			cout<<1;
			return;
		}
		b[a[i]]++;
	}
	sort(a,a+n); 
	
	//点亮 
	for(int i=2;i<=a[n-1];i++)
	{
		if(b[i]!=0)
		for(int j=i;j<=a[n-1]*2;)
		{
			c[j]=1;
			j+=i;
		}
	}
	
	//搜寻 
	dfs(2,a[n-1],n,0);
	cout<<ans;
	return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	////freopen("out.txt","w",stdout);
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cal();
	return 0;
}
