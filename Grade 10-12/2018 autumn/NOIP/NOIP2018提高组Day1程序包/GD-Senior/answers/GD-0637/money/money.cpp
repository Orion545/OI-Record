#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin ("money.in");
ofstream fout ("money.out");
bool cmp(int a,int b)
{
	return a<b;
}
int a[25001];int n;
bool devo(int now,int nop,int needn)
{
	if((needn-now)>=0&&(needn-now)%a[nop]==0)return true;
	if(a[nop]>needn)return false;
	if(now==needn)return true;
	int f=needn-now;
	f/=a[nop];
	f++;
	if(nop!=n-1)
	{
		if(devo(now,nop+1,needn))
		{
			return true;
		}
		for(int i=1;i<=f;i++)
		{
			if(devo(now+a[nop]*i,nop+1,needn))
			{
				return true;
			}
		}
	}
	if(nop==n-1)
	{
		if((needn-now)>=0&&(needn-now)%a[nop]==0)return true;
	}
	return false;
}
int main()
{
	int m,p;
	fin>>m;
	for(int i=0;i<m;i++)
	{
		fin>>p;
		int ans=p;
		memset(a,0,sizeof(a));
		for(int j=0;j<p;j++)
		{
			fin>>a[j];
		}	
		sort(a,a+p,cmp);
		for(int j=0;j<p;j++)
		{
			n=j+1;
			for(int k=j+1;k<p;k++)
			{
				if(devo(0,0,a[k]))
				{
					ans--;
					for(int f=k;f<p-1;f++)
					{
						a[f]=a[f+1];
					}
					p--;
				}
			}
			
		}
		fout<<ans<<endl;
	}
	return 0;
}
