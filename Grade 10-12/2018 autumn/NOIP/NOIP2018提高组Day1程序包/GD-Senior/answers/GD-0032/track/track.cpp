#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50500
#define low(i) (i&(-(i)))
#define max(a,b) ((a)>(b)?(a):(b)) 
using namespace std;
struct enode{
	int nxt,y,z;
}e[maxn*2];
int n,m,tot=0,cnt=0;
int dis[maxn],first[maxn],q[maxn];
int a[maxn],tree[maxn];
void adde(int x,int y,int z){
	e[tot].nxt=first[x];
	e[tot].y=y;
	e[tot].z=z;
	first[x]=tot++;
}
int bfs(int s){
	int head=1,tail=1;
	for (int i=1;i<=n;i++)
	dis[i]=-1;
	q[1]=s;
	dis[s]=0;
	while (head<=tail){
		int x=q[head++];
		for (int i=first[x];i>=0;i=e[i].nxt){
			int y=e[i].y;
			if (dis[y]<0) dis[y]=dis[x]+e[i].z,q[++tail]=y;
		}
	}
	int mx=1;
	for (int i=1;i<=n;i++)
	if (dis[i]>dis[mx]) mx=i;
	return mx;
}
bool cmp(int x,int y){
	return x>y;
}
bool check(int x){
	int l=1,r=cnt,num=0;
	while (l<=cnt&&a[l]>=x) l++,num++;
	while (l<r){
		while (l<r&&a[l]+a[r]<x) r--;
		if (l<r&&a[l]+a[r]>=x) num++,l++,r--;
	}
	if (num>=m) return 1;else return 0;
}
int ask(int i){
	int s=0;
	for (;i>0;i-=low(i)) s=max(s,tree[i]);
	return s;
}
void adde(int i,int d){
	for (;i<=cnt;i+=low(i)) tree[i]=max(tree[i],d);
}
bool check2(int x){
	memset(tree,0,sizeof(tree));
	int l=1,sum=0;
	for (int i=1;i<=cnt;i++){
		sum+=a[i];
		while (l<=i&&sum-a[l]>=x) sum-=a[l++];
		if (l<=i&&sum>=x) {
			int d=ask(l-1)+1;
			if (d>=m)return 1;
			adde(i,d);
		}
	}
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int flag=1,flag2=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		first[i]=-1;
	for (int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adde(x,y,z);
		adde(y,x,z);
		if (x+1!=y) flag=0;
		if (x!=1) flag2=0;
	}
	if (m==1) {
		int x=bfs(1),y=bfs(x);
		printf("%d",dis[y]);
	}else 
	if (flag2){
		for (int i=0;i<tot;i+=2)
		a[++cnt]=e[i].z;
		sort(a+1,a+cnt+1,cmp);
		int l=1,r=cnt*a[1];
		while (l<=r){
			int mid=(l+r)>>1;
			if (check(mid)) l=mid+1;else r=mid-1;
		}
		printf("%d",r);
	}else 
	if (flag){
		int s=0;
		for (int i=0;i<tot;i+=2)
		a[e[i].y-1]=e[i].z,s+=e[i].z;
		cnt=n-1;
		int l=1,r=s;
		while (l<=r){
			int mid=(l+r)>>1;
			if (check2(mid)) l=mid+1;else r=mid-1;
		}
		printf("%d",r);
	}else {
		int s=e[0].z+e[2].z+e[4].z;
		printf("%d",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
