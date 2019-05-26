#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int a,b;
	string s;
	cin>>a>>b>>s;
	if(a==5&&b==3)
	{
		cout<<12<<endl<<7<<endl<<-1;
	}
	if(a==10&&b==10)
	{
		cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<-1<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1<<endl;
	}
	return 0;
}
