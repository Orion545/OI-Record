#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
#define Min(x,y) (x<y)?x:y
#define Max(x,y) (x>y)?x:y
#define ll long long 
const int N=100005,INF=0x7fffffff;
struct arr{int m,w;}t[N*3];
int a[N],n,i,mi;
ll ans;
int read(){
	char c=getchar(); int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+(c-'0');
	return x;
}
void make(int l,int r,int wz){
	if(l==r){t[wz]=(arr){a[l],l};return;}
	int mid=(l+r)/2;
	make(l,mid,wz*2);make(mid+1,r,wz*2+1);
	if(t[wz*2].m<t[wz*2+1].m) t[wz].m=t[wz*2].m,t[wz].w=t[wz*2].w;
	else t[wz].m=t[wz*2+1].m,t[wz].w=t[wz*2+1].w;
}
void get(int l,int r,int wz,int x,int y){
	if(l==x&&r==y){if(t[wz].m<a[mi]) mi=t[wz].w;return;}
	int mid=(l+r)/2;
	if(mid<x) get(mid+1,r,wz*2+1,x,y);
	else if(y<=mid) get(l,mid,wz*2,x,y);
	else{
		get(l,mid,wz*2,x,mid);
		get(mid+1,r,wz*2+1,mid+1,y);
	}
}
void doit(int l,int r,int de){
	if(l==r)ans+=1ll*(a[l]-de);
	if(l>=r) return;
	mi=0;get(1,n,1,l,r);
	int mid=mi;
	ans+=1ll*(a[mid]-de);
	doit(l,mid-1,a[mid]);
	doit(mid+1,r,a[mid]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();
	fo(i,1,n) a[i]=read();
	make(1,n,1);
	ans=0;a[0]=INF;
	doit(1,n,0);
	printf("%lld\n",ans);
}
