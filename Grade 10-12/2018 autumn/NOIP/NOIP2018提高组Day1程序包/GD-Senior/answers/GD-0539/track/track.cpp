#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iostream>
#define N 51000
using namespace std;
long n,m;
struct node
{
	long to,w,next,num;
	void md(long h1,long h2,long h3,long h4)
	{
		to=h1,w=h2,next=h3,num=h4;
	}
}edge[N];
long el=0,head[N];
bool oo[N];
long Max;
long dfs(long now)
{
	long Max1=0,Max2=0,i;
	oo[now]=false;
	for (i=head[now];i!=0;i=edge[i].next){
		long to=edge[i].to,w=edge[i].w;
		if (oo[to]){
			long val=dfs(to);
			if (val+w>=Max1)Max2=Max1,Max1=val+w;
				else if (val+w>Max2)Max2=val+w;
		}
	}
	if (Max1+Max2>Max)Max=Max1+Max2;
	return Max1;
}
struct a_node
{
	long u,v,w;
	void md(long h1,long h2,long h3)
	{
		u=h1,v=h2,w=h3;
	}
}a[N],hp[N];
long hl=0;
bool operator<(a_node h1,a_node h2)
{
	return h1.w<h2.w;
}

long MMin=0;
void dfs2ad(long,long,long,long);
void dfs2(long last,long Min)
{
	if (last==0){
		if (MMin<Min)MMin=Min;
		return;
	}
	for (long i=1;i<=n;i++){//enum the start
		dfs2ad(i,0,last,Min);
	}
}
void dfs2ad(long now,long sum,long last,long Min)
{
	if (sum>MMin){
		dfs2(last-1,(Min>sum)?sum:Min);
	}
	for (long i=head[now];i!=0;i=edge[i].next){
		long to=edge[i].to,w=edge[i].w,num=edge[i].num;
		if (oo[num]){
			oo[num]=false;
			dfs2ad(to,sum+w,last,Min);
			oo[num]=true;
		}
	}
}
void fic(long now)
{
	while (now>1){
		long i=now/2;
		if (hp[now]<a[now])swap(hp[now],a[now]),now=i;
			else break;
	}
	while (now*2<=hl){
		long i=now*2;
		if (i<hl&&hp[i+1]<hp[i])i++;
		if (hp[i]<hp[now])swap(hp[now],hp[i]),now=i;
			else break;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	long i;
	scanf("%ld%ld",&n,&m);
	for (i=1;i<n;i++){
		long u,v,w;
		scanf("%ld%ld%ld",&u,&v,&w);
		edge[++el].md(v,w,head[u],i),head[u]=el;
		edge[++el].md(u,w,head[v],i),head[v]=el;
		a[i].md(u,v,w);
	}
	if (m==1){
		memset(oo,true,sizeof(oo));
		Max=0;
		dfs(1);
		printf("%ld\n",Max);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (n<=50){
		memset(oo,true,sizeof(oo));
		MMin=0;
		dfs2(m,~(1<<31));
		printf("%ld\n",MMin);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long sum=0;
	for (i=1;i<n;i++)sum+=a[i].w;
	printf("%lld\n",sum/(long long)(m));
	/*for (i=1;i<=n;i++)dsu[i]=i;
	for (i=1;i<n;i++){
		hp[++hl]=a[i];
		vec[a[i].u]
		fic(hl);
	}
	memset(val,0,sizeof(val));
	for (i=1;i<=n-m-1;i++){
		long u=hp[1].u,v=hp[1].v,w=hp[1].w;
		dsu[fd(u)]=fd(v);
		
	}
	printf("%ld\n",hp[1].w);*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
