#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[40];
bool b[40];
void feng(int s)
{
	int ch=a[s];
	for(int d=s-1;d>0;d--)
	{
		if(ch>a[d]&&b[d])ch=ch%a[d];
		else continue;
		if(ch==0)return;
	}
	b[s]=true;
}
void qsort(int r)
{
	if(r==1||r==0)return;
	int maxi=0;
	int k,p;
	for(int i=1;i<=r;i++)
	if(a[i]>maxi)
	{
		k=i;maxi=a[i];
	}
	p=a[k];a[k]=a[r];a[r]=p;
	qsort(r-1);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,m;
	scanf("%d",&t);
	for(int time=1;time<=t;time++)
	{
		memset(b,false,sizeof(b));
		m=0;
		scanf("%d",&n);
		for(int k=1;k<=n;k++)scanf("%d",&a[k]);
		qsort(n);
		b[1]=true;
		for(int i=2;i<=n;i++)feng(i);
		for(int i=1;i<=n;i++)if(b[i])m++;
		printf("%d\n",m);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
