#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[25010],b[25010];
//a����������,b��Ͱ��,c�ǵ���ͼ��,d����Ѱ
bool c[25010],d[101][25010];
int ans;
void dfs(int y,int x,int n,int m)
//�������,�����յ�,��Ŀ����,��Ѱ���� 
{
	//ȡ�õ�̽�� 
	d[m][y]=true;
	if(y<=x)
	for(int i=y;i<=x;)
	{
		if(c[y]==0)return;//�õ㸲��δ�������� 
		i+=y;
		if(y>x)//̽����ȷ 
		{
			for(int i=y;i<=x;i++)
			{
				if(i%y==0)d[m][y]=1;
				else d[m][y]=0;
			}//�õ��õ�ģ�� 
			
			for(int j=0;j<=a[n-1];j++)//������������ͬ�� 
			{
				int f=0;
				//����������ģ�����Ƿ��з��� 
				for(int k=0;k<=m;k++)
				if(d[k][j]==c[j])f=1;
				if(f==0)break;
				f=0;
				
				if(j==a[n-1])//��ȫ��ͬ,�õ��� 
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
	//�����õ�̽�� 
	d[m][y]=false;
	dfs(y+1,x,n,m);
}
void cal()
{
	//����
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
	
	//���� 
	for(int i=2;i<=a[n-1];i++)
	{
		if(b[i]!=0)
		for(int j=i;j<=a[n-1]*2;)
		{
			c[j]=1;
			j+=i;
		}
	}
	
	//��Ѱ 
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
