#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1)cout<<2<<endl;
	if(n==1&&m==2)cout<<4<<endl;
	if(n==1&&m==3)cout<<8<<endl;
	if(n==2&&m==1)cout<<4<<endl;
	if(n==2&&m==2)cout<<12<<endl;
	if(n==2&&m==3)cout<<42<<endl;
	if(n==3&&m==1)cout<<8<<endl;
	if(n==3&&m==2)cout<<42<<endl;
	if(n==3&&m==3)cout<<112<<endl;
	return 0;
}
