#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct T1{int d;int num;}a[100005];
int n,block,l[100005],r[100005],belong[100005],m,ans,de[100005];
bool cmp(T1 a,T1 b)
{
	return a.d<b.d;
}
void build()
{
	for (;(block+1)*(block+1)<=n;) block++;
	m=n/block;
	if (n%block) m++;
	for (int i=1;i<=n;i++) belong[i]=(i-1)/block+1;
	for (int i=1;i<=m;i++) l[i]=(i-1)*block+1,r[i]=block*i;
	r[m]=n;
	for (int i=1;i<=m;i++) sort(a+l[i],a+1+r[i],cmp);
	memset(de,0,sizeof(de));
}
int query(int x,int y)
{
	if (x>y) return -1;
	int s=2000000000,p=-1;
	for (int i=1;i<=m;i++)
	{
		if (l[i]>y || r[i]<x) continue;
		if (l[i]>=x && r[i]<=y)
		{
			if (a[l[i]].d-de[i]<s) 
			s=a[l[i]].d-de[i],p=l[i];
			continue;
		}else
		{
			for (int j=l[i];j<=r[i];j++)
			if (a[j].num>=x && a[j].num<=y)
			{
				if (a[j].d-de[i]<s) 
				 s=a[j].d-de[i],p=j;
			}
		}
	}
	return p;
}
void update(int x,int y,int z)
{
	for (int i=1;i<=m;i++)
	{
		if (l[i]>y || r[i]<x) continue;
		if (l[i]>=x && r[i]<=y) 
		{
			de[i]+=z;
			continue;
		}else
		{
			for (int j=l[i];j<=r[i];j++)
			if (a[j].num>=x && a[j].num<=y) a[j].d-=z;
			sort(a+l[i],a+1+r[i],cmp);	
		}
	}
}
void work(int x,int y)
{
	int p=-1;
	if (x>y) return ;
	p=query(x,y);
	if (p==-1) return ;	
	//cout<<x<<' '<<y<<' '<<de[belong[a[p].num]]<<endl;
	if (a[p].d-de[belong[a[p].num]]>0) 
	{
		ans+=a[p].d-de[belong[a[p].num]];
		update(x,y,a[p].d-de[belong[a[p].num]]);
	}
	work(x,a[p].num-1);
	work(a[p].num+1,y);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {scanf("%d",&a[i].d),a[i].num=i;}
	build();
	work(1,n);
	cout<<ans;
	return 0;
}
