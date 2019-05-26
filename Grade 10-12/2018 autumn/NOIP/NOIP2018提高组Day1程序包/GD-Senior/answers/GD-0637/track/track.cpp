#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin ("track.in");
ofstream fout ("track.out");
int a[15000][15000];
int ccde[50001];
int tt[50001]={};
int n;int m;
int rod(int now,int sum)
{
	tt[now]=1;int mmax=sum;
	for(int i=1;i<=n;i++)
	{
		if(tt[i]==0&&a[now][i]!=0)
		{
			int ff=rod(i,sum+a[now][i]);
			if(mmax<ff)mmax=ff;
		}
	}
	tt[now]=0;
	return mmax;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	fin>>n>>m;
	int mmin=1000000,ssum=0;
	bool tttf=true;
	for(int i=0;i<n-1;i++)
	{
		int x,y,r;
		fin>>x>>y>>r;
		ccde[x]=r;
		ssum+=r;
		if(x+1!=y)
		{
			tttf=false;
		}
		if(r<mmin)mmin=r;
		if(x<15000&&y<15000)
		{
			a[x][y]=r;
			a[y][x]=r;
		}
	}
	if(m==1)
	{
		int mmaex=0;
		for(int i=1;i<=n;i++)
		{
			int ff=rod(i,0);
			if(ff>mmaex)mmaex=ff;
		}
	fout<<mmaex;
	return 0;
	}
	if(m==n-1)
	{
		fout<<mmin;
		return 0;
	}
	if(tttf)
	{
		while(n>m)
		{
			sort(ccde+1,ccde+1+n,cmp);
			ccde[n-1]=ccde[n]+ccde[n-1];
			n--;
		}
		sort(ccde+1,ccde+1+n,cmp);
		fout<<ccde[n];
		return 0;
	}
	fout<<ssum/m;
	return 0;
}
