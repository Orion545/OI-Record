#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct edge{
	ll left,right;
}a[100010];
ll n,m,k,l[40010],r[40010],dpl[40010],dpr[40010];
ll read(){
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x;
}
bool cmp(edge l,edge r){
	if(l.left<r.left) return 1;
	if(l.left>r.left) return 0;
	return l.right<r.right;
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	ll i,ans=0,tl,tr;
	n=read();m=read();k=read();
	for(i=1;i<=n;i++) l[i]=read(),dpl[i]=l[i];
	for(i=1;i<=m;i++) r[i]=read(),dpr[i]=r[i];
	for(i=1;i<=k;i++) a[i].left=read(),a[i].right=read();
	sort(a+1,a+k+1,cmp);
	for(i=1;i<=k;i++){
		tl=dpr[a[i].right]+l[a[i].left];
		tr=dpl[a[i].left]+r[a[i].right];
		dpl[a[i].left]=max(dpl[a[i].left],tl);
		dpr[a[i].right]=max(dpr[a[i].right],tr);
	}
	for(i=1;i<=n;i++) ans=max(ans,dpl[i]);
	for(i=1;i<=m;i++) ans=max(ans,dpr[i]);
	printf("%lld",ans);
} 
