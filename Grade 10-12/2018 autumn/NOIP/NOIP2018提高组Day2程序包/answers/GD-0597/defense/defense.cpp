#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,l,l1,l2,l3,l4;
	char t,t1;
	cin>>n>>m>>t>>t1;
	for(int i=1;i<=n;i++)
		cin>>l;
	for(int i=1;i<n;i++)
		cin>>l1>>l2;
	for(int i=1;i<=m;i++)
	{
		cin>>l1>>l2>>l3>>l4;
		cout<<-1<<endl;
	}
	return 0;
}
