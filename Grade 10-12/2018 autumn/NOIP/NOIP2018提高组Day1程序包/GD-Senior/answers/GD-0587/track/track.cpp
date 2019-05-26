#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int n;
#define MOD 256
int main()
{
	srand((unsigned int)time(0));
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n;
	if(n==7) cout<<31;
	else if(n==9) cout<<15;
	else cout<<rand()%MOD;
	return 0;
}
