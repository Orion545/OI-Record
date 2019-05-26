#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
#include<cmath>
#define N 101000
#define inf 11000000000ll
using namespace std;
struct node
{
	long to,next;
	void md(long h1,long h2)
	{
		to=h1,next=h2;
	}
}edge[N];
long el=0,head[N];
bool oo[N];
long long f[N][2];
long a,b,x,y,p[N];
bool imp;
void dp(long now)
{
	oo[now]=false;
	long long ss0=0,ss1=0;
	bool sn0=false;
	for (long i=head[now];i>0;i=edge[i].next){
		long to=edge[i].to;
		if (oo[to]){
			dp(to);
			if (imp){
				oo[now]=true;
				return;
			}
			if (to==a&&x==0||to==b&&y==0)sn0=true;
			if (!sn0)ss0+=f[to][1];
			ss1+=(f[to][1]<f[to][0])?f[to][1]:f[to][0];
		}
	}
	if (sn0)ss0=inf;
	if (now==a){
		if (x==0)f[now][0]=ss0,f[now][1]=inf;
			else f[now][0]=inf,f[now][0]=ss1+p[now];
	}	else if (now==b){
		if (y==0)f[now][0]=ss0,f[now][1]=inf;
			else f[now][0]=inf,f[now][0]=ss1+p[now];
	} else {
		f[now][0]=ss1,f[now][1]=ss1+p[now];
	}
	if (f[now][0]==inf&&f[now][1]==inf)imp=true;
	oo[now]=true;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char str[10];
	long n,m,i;
	scanf("%ld%ld",&n,&m);
	scanf("%s",str);
	for (i=1;i<=n;i++)scanf("%ld",&p[i]);
	memset(head,0,sizeof(head));
	for (i=1,el=0;i<n;i++){
		long u,v;
		scanf("%ld%ld",&u,&v);
		edge[++el].md(v,head[u]),head[u]=el;
		edge[++el].md(u,head[v]),head[v]=el;
	}
	memset(oo,true,sizeof(oo));
	for (i=1;i<=m;i++){
		scanf("%ld%ld%ld%ld",&a,&x,&b,&y);
		imp=false;
		dp(1);
		if (imp)printf("-1\n");
			else printf("%lld\n",(f[1][0]<f[1][1])?f[1][0]:f[1][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
