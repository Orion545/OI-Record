#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
long long sumji=0,sumou=0;
int n,m,p[300005],dl[350000][3],dbe=0,den=1,dcs[300005];//0数，1层，2上一个 
string type;
struct hw
{
	int x,y;
}a[300005];
bool cmp(hw c,hw d)
{
	if(c.x!=d.x)
	return c.x<d.x;
	else
	return c.y<d.y;
}
int fleft(int be,int en,int zz)//左不，右可 
{
	if(be+1==en)
	return en;
	int mid=(be+en)/2;
	if(a[mid].x>=zz)
	return fleft(be,mid,zz);
	else
	return fleft(mid,en,zz);
}
int fright(int be,int en,int zz)//左可，右不 
{
	if(be+1==en)
	return be;
	int mid=(be+en)/2;
	if(a[mid].x<=zz)
	return fright(mid,en,zz);
	else
	return fright(be,mid,zz);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)
	cin>>p[i];
	for(int i=1;i<2*n-2;i+=2)
	{
		cin>>a[i].x>>a[i].y;
		a[i+1].x=a[i].y;
		a[i+1].y=a[i].x;
	}
	sort(a+1,a-1+2*n,cmp);
	dl[den][0]=1;
	dl[den][1]=1;
	dl[den][2]=0;
	while(dbe<den)
	{
		dbe++;
		dcs[dl[dbe][0]]=dl[dbe][1];
		if(dl[dbe][1]%2==0)
		sumou+=p[dl[dbe][0]];
		else
		sumji+=p[dl[dbe][0]];
		for(int i=fleft(0,2*n-2,dl[dbe][0]);i<=fright(1,2*n-1,dl[dbe][0]);i++)
		{
			if(a[i].y!=dl[dbe][2])
			{
				den++;
				dl[den][0]=a[i].y;
				dl[den][1]=dl[dbe][1]+1;
				dl[den][2]=dl[dbe][0];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int d1,d2;
		bool x1,x2;
		cin>>d1>>x1>>d2>>x2;
		if((dcs[d1]%2)!=(dcs[d2]%2)&&x1==x2||(dcs[d1]%2)==(dcs[d2]%2)&&x1!=x2)
		cout<<"-1";
		else
		{
			if(dcs[d1]%2==0)
			{
				if(x1)
				cout<<sumou;
				else
				cout<<sumji;
			}
			if(dcs[d1]%2!=0)
			{
				if(x1)
				cout<<sumji;
				else
				cout<<sumou;
			}
		}
		cout<<endl;
	}
	return 0;
} 
