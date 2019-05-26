#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,tot,ls[200007],rd[200007];
int qidian;
long long ans,sum;
struct edge{
	long long w;
	int to,next;
}e[200007];
bool teshupanduan;
struct arr{
	long long w;
	int x,y;
}ee[200007];

void tianjia(int x,int y,long long z){
	e[++tot].to=y;
	e[tot].w=z;
	e[tot].next=ls[x];
	rd[y]++;
	ls[x]=tot;
}

long long max(long long a,long long b){
	return a>b?a:b;
}

void dfs(int x,int pre,long long s){
	ans=max(ans,s);
	for(int i=ls[x];i;i=e[i].next){
		int v=e[i].to;
		if (v!=pre) dfs(v,x,s+e[i].w);
	}
}

void caozuo(){
	for(int i=1;i<=n;i++)	dfs(i,0,0);
	cout<<ans;
	return;
}

bool CHeck(int mubiao){
	int x=qidian;
	int qian=0;
	int zonghe=1;
	long long qujianzhi=0;
	int duanshu=0;
	while(zonghe<n){
		for(int i=ls[x];i;i=e[i].next){
			int v=e[i].to;
			if (v!=qian){
				qujianzhi+=e[i].w;
				qian=x;
				x=v;
				zonghe++;
				break;
			}
		}
		if (qujianzhi>=mubiao)	duanshu++,qujianzhi=0;
	}
	if (duanshu<m)	return false;
	return true;
}

void caozuo2(){
	qidian=0;
	for(int i=1;i<=n;i++)
		if (rd[i]<2)	qidian=i;
	long long l=0,r=sum;
	while(l<r){
		long long mid=(l+r+1)/2;
		if (CHeck(mid))	l=mid; else r=mid-1;
	}
	cout<<l;
	return;
}

void duru(){
	for(int i=1;i<=n-1;i++){
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		ee[i].x=x;
		ee[i].y=y;
		ee[i].w=z;
		tianjia(x,y,z);
		tianjia(y,x,z);
		if(x!=1)	teshupanduan=1;
		sum+=z;
	}
}

bool cmp(arr x, arr y){
	return x.w>y.w;
}

long long min(long long a,long long b){
	return a<b?a:b;
}

void caozuo3(){
	sort(ee+1,ee+n,cmp);
	ans=100000000;
	for(int i=1;i<=m;i++)
		ans=min(ans,ee[i].w+ee[2*m-i+1].w);
	cout<<ans;
	return;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=0;
	ans=0;
	sum=0;
	teshupanduan=0;
	for(int i=1;i<=n;i++)	ls[i]=0,rd[i]=0;
	for(int i=1;i<=2*n;i++)	e[i].to=0,e[i].next=0,e[i].w=0;
	duru();
	if(m==1&&n<=1000){
		caozuo();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else{
		bool jiancha=0;
		for(int i=1;i<=n;i++)	if(rd[i]>2)	jiancha=1;
		if(jiancha==0){
			caozuo2();
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else if (teshupanduan==0){
			caozuo3();
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
