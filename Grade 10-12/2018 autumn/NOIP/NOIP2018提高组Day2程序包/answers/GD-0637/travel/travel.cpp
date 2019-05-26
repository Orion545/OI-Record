#include<iostream>
#include<fstream>
using namespace std;
ifstream fin ("travel.in");
ofstream fout ("travel.out");
int a[5001][5001]={};int b[5001]={};int n,m,begin,iscout[5001]={},isi=0,recout[5001]={},beke[5001][5001];
bool isccer=false;
void solvee(int now,int left)
{
	if(left==1)
	{
		isccer=true;
		iscout[isi]=now;
		isi++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[now][i]==1)
		{
			a[now][i]=0;
			if(b[i]==0&&i!=begin)
			{
				b[i]=now;
				solvee(i,left-1);
				b[i]=0;
			}
			else
			{
				a[i][now]=0;
				solvee(i,left);
			}
			a[now][i]=1;
			a[i][now]=1;
		}
		if(isccer)
		{
			iscout[isi]=now;
			isi++;
			return;
		}
	}
}
int main()
{
	fin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		fin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
		beke[x][y]=1;
		beke[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		begin=i;
		solvee(i,n);
		if(isccer)
		{
			for(int j=isi-1;j>=0;j--)
			{
				if(recout[iscout[j]]==0)
				{
					fout<<iscout[j]<<' ';
					recout[iscout[j]]=1;
				}
			}
			break;
		}
	}
	return 0;
}
