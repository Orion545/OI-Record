#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
inline ll rd(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return f*x;
} 
ll N,ans=0,last,now;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	N=rd();
	last=0;
	for(int i=1;i<=N;i++){
		now=rd();
		if(now-last>0)ans+=now-last;
		last=now;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
} 
