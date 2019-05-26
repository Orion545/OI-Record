#include<iostream>
#include<cstdio>
#define MAXN 100000+10
using namespace std;
int n,a[MAXN],sum=0,aa;
int maxl;
bool pd(int i,int j)//判断di和dj是不是都不为零 
{
	if(i==0||j==0) 
		return false;
	else
		return true;
}
void work(int d)
{
	while(1)
	{
		int OvO;
		bool QwQ=true,all=false;
		for(int k=1;k<=d;++k)
			if(a[k]!=0)
			{
				QwQ=false;
				break;
			}
		if(QwQ)
			break;
		sum++;
		int i,j,m,n;
		for(i=1;i<=d;++i)
			if(a[i]!=0)
			{
				int jj=i+1;
				OvO=0;
				while(pd(a[i],a[jj]))
				{
					if(jj==d)
						jj-=d;
					jj++;
					OvO++;
					if(OvO>maxl)
					{
						maxl=OvO;
						aa=i;
					}
				}
			}//找起点 
		i=aa;
		j=i+1;
		while(pd(a[i],a[j]))
		{
			if(i==j)
			{
				all=true;
				break;
			}
			if(j==d)
				j-=d;
			j++;
		}
		if(all)
		{
			for(n=1;n<=d;++n)
				a[n]--;
			continue;
		}
		j-=1;
		if(j==0)
			j+=d;
		bool change=false;
		if(i>j)
		{
			change=true;
			int tump=j;
			j=i;
			i=tump;
		}//保证i是小数，为后面循环 
		if(!change)
		for(n=i;n<=j;++n)
			a[n]--;
		else
		{
			for(int q=1;q<=i;++q)
				a[q]--;
			for(int q=j;q<=d;++q)
				a[q]--;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	work(n);
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
}
