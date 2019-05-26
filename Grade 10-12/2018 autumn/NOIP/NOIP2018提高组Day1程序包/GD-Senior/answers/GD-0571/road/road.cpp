#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct qqq
{
	int x;
	int y;
	int tim;
}Q[440000];
int n,m,ass=0,bin[50],logg[440000],a[440000][30],x,y,nam[440000][30],tim;
int tot=0,s,t;
void jvruo(int x,int y,int tim)
{
	if(y<x) return;
	if(x==y)
	{
		ass+=(a[x][0]-tim);
		return;
	}
	int t=y-x+1,QAQ,thename;
	int lg=logg[t];
	if(a[x][lg]<a[y-bin[lg]+1][lg]) 
	{
		QAQ=a[x][lg];
		thename=nam[x][lg];
	}
	else
	{
		QAQ=a[y-bin[lg]+1][lg];
		thename=nam[y-bin[lg]+1][lg];
	}
	ass+=(QAQ-tim);
	jvruo(x,thename-1,QAQ); 
	jvruo(thename+1,y,QAQ);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i][0]);
		nam[i][0]=i;
	}
	bin[0]=1;
	for(int i=1; i<=30; i++) bin[i]=bin[i-1]*2;
	logg[0]=-1;
	for(int i=1; i<=n; i++) logg[i]=logg[i/2]+1;
	for(int i=1; i<=logg[n]; i++)
	for(int j=1; j<=n; j++)
	if(j+bin[i]-1<=n)
	{
		if(a[j][i-1]<a[j+bin[i-1]][i-1])
		{
			a[j][i]=a[j][i-1];
			nam[j][i]=nam[j][i-1];
		}
		else
		{
			a[j][i]=a[j+bin[i-1]][i-1];
			nam[j][i]=nam[j+bin[i-1]][i-1];
		}
	}
	jvruo(1,n,0);
	printf("%d",ass);
}
