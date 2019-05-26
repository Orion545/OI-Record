#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#define ull unsigned long long
#define MOD 19260817
using namespace std;
int a[400010],b[400010],n;
ull ha[400010],hb[400010],p[400010];
unordered_map<int,int>mp;
bool check(int x){
	int i;mp.clear();
	cout<<"check "<<x<<'\n';
	for(i=0;i<=n-x;i++) mp[ha[i+x]-ha[i]*p[x]]=1;
	for(i=0;i<=n-x;i++) if(mp.count(hb[i+x]-hb[i]*p[x])) return 1;
	cout<<"failed\n";
	return 0;
}
int main(){
	srand(time(NULL));
	n=400000;int i;
	for(i=1;i<=n;i++) p[i]=p[i-1]*MOD;
	for(i=1;i<=n;i++) a[i]=rand()%2,ha[i]=ha[i-1]*MOD+a[i];
	for(i=1;i<=n;i++) b[i]=rand()%2,hb[i]=hb[i-1]*MOD+b[i];
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	ios::sync_with_stdio(false);
	cout<<l<<'\n';
	for(i=1;i<=n;i++) cout<<i<<' '<<a[i]<<' '<<b[i]<<'\n';
}
