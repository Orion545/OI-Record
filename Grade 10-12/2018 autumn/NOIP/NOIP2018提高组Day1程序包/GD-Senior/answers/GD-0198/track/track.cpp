#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,m,a,b,s,l[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
void find_ans1()
{
	sort(l+1,l+n,cmp);
	cout<<l[m];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int ma=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l[i]);
		if(a>b) swap(a,b);
		ma=max(ma,a);
		s+=l[i];
	}
	if(ma==1)
	{
		find_ans1();
		return 0;
	}
	cout<<s;
	return 0;
}
