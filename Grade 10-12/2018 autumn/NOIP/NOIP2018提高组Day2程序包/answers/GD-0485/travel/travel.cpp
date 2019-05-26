#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int y2=1,y=1,n,m,p,q,l[5001],l2[5001],text[5001][5001];
bool a[5001][5001],b[5001][5001];
int maxn(int x[],int y)
{
	int maxm=0;
	for(int i=1;i<=y;i++)
		if(x[i]>maxm) maxm=x[i];
	return maxm;
}
void walk(int x,int z)
{
	int son=0;
	for(int i=1;i<=y;i++)
	{
		if(l[i]==x) break;
		if(i==y&&l[i]!=x) 
		{
			l[i]=x;
			if(z!=0)
			{
				for(int i=1;i<=n;i++)
				{
					a[i][z]=0;
				}
				a[x][z]=1;
			}
			y++;
			break;
		}
	}	
	if(y==n+1) return;
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(a[x][i]==1) son++;
	}
	if(son==0) return;
	for(int i=1;i<=n;i++)
	{
		if(son==1&&a[x][i]==1)
		{
			text[x][i]++;
			walk(i,x);
		}
		if(son!=1&&a[x][i]==1&&i!=z&&(text[x][i]+text[i][x])<2)
		{
			text[x][i]++;
			walk(i,x);
			continue;
		}
	}
}
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p>>q;
		a[p][q]=1;
		a[q][p]=1;
		b[p][q]=1;
		b[q][p]=1;
	}
	walk(1,0);
	for(int i=1;i<=n;i++)
		 cout<<l[i]<<" ";
	return 0;
}
