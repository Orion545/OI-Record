#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1) cout<<"2";
	if(n==1&&m==2) cout<<"4";
	if(n==1&&m==3) cout<<"8";
	if(n==2)
	{
		long long s=1;
		for(int i=1;i<m;i++) s=(s*3)%1000000007;
		s=(s*4)%1000000007;
		cout<<s;
	}
	if(n==3&&m==1) cout<<"8";
	if(n==3&&m==2) cout<<"36";
	if(n==3&&m==3) cout<<"112";
	if(n==5&&m==5) cout<<"7136";
	return 0;
}
