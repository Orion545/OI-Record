#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define LL long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,ret=0,pre=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	fo(i,1,n)
	{
		int t=read();
		if(t>pre)ret+=t-pre;
		pre=t;
	}
	cout<<ret<<endl;
	return 0;
}
