#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int first[1010],n,m,cnte,op[300010],ed[300010];double a[1010][1010],b[1010],g[300010],deg[1010];
struct edge{
	int to,next;
}e[250010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;deg[u]++;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;deg[v]++;
}
void Gauss(){
	int i,j,k,num;double tmp;
	for(i=1;i<=n;i++){
		num=i;
		for(j=i+1;j<=n;j++) if(fabs(a[j][i])>=fabs(a[num][i])) num=j;
		for(j=1;j<=n;j++) swap(a[i][j],a[num][j]);
		swap(b[i],b[num]);
		for(j=i+1;j<=n;j++){
			if(fabs(a[j][i])<1e-6) continue;
			tmp=a[j][i]/a[i][i];
			for(k=1;k<=n;k++) a[j][k]-=a[i][k]*tmp;
			b[j]-=b[i]*tmp;
		}
	}
	for(i=n;i>=1;i--){
		b[i]/=a[i][i];
		for(j=i-1;j>=1;j--) b[j]-=a[j][i]*b[i];
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,u,v;double ans=0;
	for(i=1;i<=m;i++){
		t1=read();t2=read();assert(t1!=t2);
		add(t1,t2);op[i]=t1;ed[i]=t2;
	}
	n--;b[1]=-1.0;
	for(u=1;u<=n;u++){
		a[u][u]=-1.0;
		for(i=first[u];~i;i=e[i].next){
			v=e[i].to;if(v==n+1) continue;
			a[u][v]=1.0/deg[v];
		}
	}
	Gauss();
	for(i=1;i<=m;i++) g[i]=b[op[i]]/deg[op[i]]+b[ed[i]]/deg[ed[i]],assert(g[i]>=0);
	sort(g+1,g+m+1);
	for(i=1;i<=m;i++) ans+=g[i]*(m-i+1);
	printf("%.3lf\n",ans);
}
