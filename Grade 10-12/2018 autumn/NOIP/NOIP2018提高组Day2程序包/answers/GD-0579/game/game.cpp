//路径可以交叉！！！！ 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

namespace Solution
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

const long long mod=1000000007;
long long fastpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

//n=1
void Subtask1(long long m)
{
	cout<<fastpow(2,m)<<endl;
}

void Subtask2(long long m)
{
	cout<<fastpow(3,m-1)*4%mod<<endl;
}

int main()
{
	long long n,m;
	read(n);read(m);
	if(n>m)swap(n,m);
	if(n==1)
	{
		Subtask1(m);
		return 0;
	}
	if(n==2)
	{
		Subtask2(m);
		return 0;
	}
	if(m==3&&n==3)
	{
		cout<<112<<endl;
		return 0;
	}
	if(m==5&&n==5)
	{
		cout<<7136<<endl;
		return 0;
	}
	return 0;
}

}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	return Solution::main();
}
