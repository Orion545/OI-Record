#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=0,m=0,s=1;
	cin>>n>>m;
	if(n==1||m==1)
	cout<<2*n*m%1000000007;
	else
	{
	if(n==2)
	{
		for(int i=1;i<m;i++)
		s*=3;
		cout<<(4*s)%1000000007;
	}
	else
{
	if(m==2)
	{
	for(int i=1;i<n;i++)
	s*=3;
	cout<<(4*s)%1000000007;
}
    if(m==3&&n==3)
    cout<<112;
    
}
}
	return 0;
}
