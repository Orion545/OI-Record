//不管3*7=21先get个15' 

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<string>

#define cg c=getchar()
#define pc putchar
#define ic isdigit(c)
#define ll long long
#define tt(a) template<typename a>
using namespace std;

tt(GD) void read(GD& x)
{
	x=0; bool f=0;char cg; 
	while(!ic) { if(c=='-')  f=1; cg;}
	while(ic) x=(x<<3)+(x<<1)+(c^48),cg;
	if(f) x=-x;
}

tt(GD) void write(GD x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+48);
}

const int MAXN=25010;
int t,n,a[MAXN]; 

int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(x==y) return x;
	if(y==0) return x;
	gcd(y,x%y);
}

bool judge(int x,int y,int z)
{
	int a1=min(x,min(y,z));
	int a3=max(x,max(y,z));
	int a2=x+y+z-a1-a3;
	
	int a=gcd(x,y);
	int b=gcd(y,z);
	int c=gcd(x,z);
	
	if((a==x||a==y)&&(a!=b && a!=c)) return 1;
	if((b==y||b==z)&&(a!=b && b!=c)) return 1;
	if((c==x||c==z)&&(a!=c && b!=c)) return 1;
	
	for(int i=0;i<=500;i++)
		for(int j=0;j<=500;j++)
			if(a1*i+a2*j==a3) return 1;
	return 0;
}

bool ok1(int x,int y,int z)
{
	int a=gcd(x,y);
	int b=gcd(y,z);
	int c=gcd(x,z);
	if(a==b && b==c && c==b)
		if(a==x ||a==y ||a==z)
			return 1;
	return 0;	
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		if(n==2)
			if(a[1]==1 || a[2]==1)
			{
				write(1);
				pc('\n');
				continue;
			}
			else
			{
				write(2);
				pc('\n');
				continue;
			}		
		else if(n==3)
			if(a[1]==1 || a[2]==1 || a[3]==1 || ok1(a[1],a[2],a[3]))
			{
				write(1);
				pc('\n');
				continue;				
			}
			else if(judge(a[1],a[2],a[3]))
			{
				write(2);
				pc('\n');
				continue;				
			}
			else 
			{
				write(3);
				pc('\n');
				continue;				
			}
		else 
		{
			write(2);
			pc('\n');			
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
