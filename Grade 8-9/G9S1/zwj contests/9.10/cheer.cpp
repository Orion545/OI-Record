#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct erickin{
	int to,next,from,w;
}a[200100];
int n,m,wei[10010],first[10010];
ll ans=0;
int f[10010];
bool cmp(erickin l,erickin r){
	return l.w<r.w;
}
int find(int k){
	return ((f[k]==k)?k:f[k]=find(f[k]));
}
void kruskal(){
	int i,times=0,fx,fy;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++){
		fx=find(a[i].from);fy=find(a[i].to);
		if(fx!=fy){
			f[fx]=fy;ans+=a[i].w;
			times++;
			if(times==n-1) break;
		}
	}
}
int main(){
	int i,t1,t2,t3;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&wei[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		a[i].to=t2;a[i].from=t1;a[i].next=first[t1];first[t1]=i;a[i].w=t3*2+wei[t1]+wei[t2];
	}
//	for(i=1;i<=m;i++) cout<<a[i].from<<ends<<a[i].to<<ends<<a[i].w<<endl;
	sort(a+1,a+m+1,cmp);
	sort(wei+1,wei+n+1);
	kruskal();
	printf("%lld",ans+wei[1]);
}
/*
5 7
10
10
20
6
30
1 2 5
2 3 5
2 4 12
3 4 17
2 5 15
3 5 6
4 5 12
*/
