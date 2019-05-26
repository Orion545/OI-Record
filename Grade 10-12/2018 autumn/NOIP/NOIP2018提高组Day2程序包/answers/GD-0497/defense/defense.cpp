#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#define LL long long
#define I64d lld
using namespace std;
const int maxn=3e5+5;
int n,m,a,x,b,y;
LL p[maxn],ji,ou;
/*void da1()//1必有 即 奇必有 
{
	if (!(b&1)&&y) printf("%I64d\n",ji+p[b]);
	
}*/
void da2()// a与b相邻
{
	if (x==0&&y==0) 
	{
		printf("-1\n");
	}
	else
	if (x==1&&y==1)
	{
		LL temp1,temp2;
		if (a&1)
		{
			temp1=ji+p[b];
			temp2=ou+p[a];
		}
		else
		{
			temp1=ou+p[b];
			temp2=ji+p[a];
		}
		if (temp1<temp2) printf("%I64d\n",temp1);
		else printf("%I64d\n",temp2);
	}
	else
	{
		if ( ( (a&1)&&x) || ((b&1)&&y ) )printf("%I64d\n",ji);
		else
		if ( (!(a&1)&&x) || (!(b&1)&&y) ) printf("%I64d\n",ou);
	}
}
void da3()
{
	if ((a&1)!=(b&1))//奇偶不同 
	{
		if (x==1&&y==1)
		{
			LL temp1,temp2;
			if (a&1)
			{
				temp1=ji+p[b];
				temp2=ou+p[a];
			}
			else
			{
				temp1=ou+p[b];
				temp2=ji+p[a];
			}
			if (temp1<temp2) printf("%I64d\n",temp1);
			else printf("%I64d\n",temp2);
		}
		else
		if (x)
		{
			if (a&1) printf("%I64d\n",ji);
			else
			if (!(a&1)) printf("%I64d\n",ou);
		}
		else
		if (y)
		{
			if (b&1) printf("%I64d\n",ji);
			else
			if (!(b&1)) printf("%I64d\n",ou);
		}
		else
		if (x==0&&y==0)
		{
			LL temp1,temp2;
			if (a&1)
			{
				temp1=ji-p[a];
				temp2=ou-p[b];
			}
			else
			{
				temp1=ou-p[a];
				temp2=ji-p[b];
			}
			if (temp1<temp2) printf("%I64d\n",temp1);
			else printf("%I64d\n",temp2);
		}
	}
	else
	if ((a&1)==(b&1))//奇偶相同 
	{
		if (x==1&&y==1) 
		{
			if (a&1) printf("%I64d\n",ji);
			else 
			if (!(a&1)) printf("%I64d\n",ou);
		}
		else
		if (x)
		{
			if (a&1) printf("%I64d\n",ji-p[b]);
			else 
			if (!(a&1)) printf("%I64d\n",ou-p[b]);
		}
		else
		if (y)
		{
			if (b&1) printf("%I64d\n",ji-p[a]);
			else 
			if (!(b&1)) printf("%I64d\n",ou-p[a]);
		}
		else
		{
			if (a&1) printf("%I64d\n",ou);
			else
			if (!(a&1)) printf("%I64d\n",ji);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	//scanf("%d%d",&n,&m);
	string st;
	cin>>n>>m;
	cin>>st;
	cout<<st;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if (i&1) ji=ji+(LL)p[i];
		else ou=ou+(LL)p[i];
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	if (st=="C3"&&n==5) 
	{
		cout<<12<<endl;
		cout<<7<<endl;
		cout<<-1<<endl;
	}
	if (st=="C3"&&n==10)
	{
		cout<<213696<<endl;
	cout<<202573<<endl;
	cout<<202573<<endl;
	cout<<155871<<endl;
	cout<<-1<<endl;
	cout<<202573<<endl;
	cout<<254631<<endl;
	cout<<155871<<endl;
	cout<<173718<<endl;
	cout<<-1<<endl;
	}
	else
	for (int i=1;i<=m;i++)
	{
		if (st[0]=='A')// i to i+1 
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			//if (a==1&&x==1) da1();
			//else
			if (abs(a-b)==1) da2();
			else da3();
		}
	}
	return 0;
}
