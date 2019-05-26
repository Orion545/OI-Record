#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cstring>
#define while for
#define cin fin
#define cout fout
using namespace std;
int n;
int a[200000];
long long ans;
ifstream fin("road.in.txt");
ofstream fout("road.out.txt");
inline int dp(register int l,register int r){
	register int i,maxn;
	maxn=l;
	while(i=l+1;i<=r;++i){
		if(a[i]<a[maxn]) maxn=i;
	}
	ans+=a[maxn];
	int u=a[maxn];
	for(i=l;i<=r;++i){
		a[i]-=u;
	}
	if(l<=maxn-1) dp(l,maxn-1);
	if(r>=maxn+1) dp(maxn+1,r);
	return 0;
}
int main()
{
	cin>>n;
	while(register int i=1;i<=n;i++) cin>>a[i];
	dp(1,n);
	cout<<ans;
	return 0;
}
