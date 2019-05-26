#include<iostream>
#include<fstream>
using namespace std;
ifstream fin ("road.in");
ofstream fout ("road.out");
int a[100001]={};
long long ans=0;int cre;
void cut(int l,int r,int c)
{
	for(int i=l;i<=r;i++)
	{
		a[i]-=c;
		if(a[i]==0)cre--;
	}
	return;
}
int main()
{
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		fin>>a[i];
	}
	int ner0=0;
	cre=n;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)cre--;
	}
	for(int i=0;i<n;i++)
	{
		bool ft0=true;
		int l,r,c;
		for(int j=ner0;j<n;j++)
		{
			r=n-1;
			if(a[j]==0&&ft0==true)
			{
				ner0=j;
			}
			else
			if(a[j]!=0&&ft0==true)
			{
				ft0=false;
				l=j;
				c=a[j];
			}
			else
			if(a[j]==0&&ft0==false)
			{
				r=j-1;
				break;
			}
			else
			if(a[j]<c)
			{
				c=a[j];
			}
		}
		cut(l,r,c);
		ans+=c;
		if(cre==0)break;
	}
	fout<<ans;
	return 0;
}
