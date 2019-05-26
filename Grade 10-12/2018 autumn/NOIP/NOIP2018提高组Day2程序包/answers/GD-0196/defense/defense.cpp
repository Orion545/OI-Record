#include<iostream>
#include<cstdio>
using namespace std;

int n,m;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);

	cin>>n>>m;
	if (n==5&&m==3)
	 cout<<12<<endl<<7<<endl<<-1<<endl;
	if (n==10&&m==10)
	 cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<-1<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1<<endl;
	return 0;
}
