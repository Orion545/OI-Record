#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define id(i,j) (i-1)*n+j
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
double a[510][510],p[110],deg[110],go[110],ans[510];
int n,m,op1,op2,cnt;
int first[110],cnte;
struct edge{
	int to,next;
}e[1010];
inline void add(int u,int v){
	deg[u]++;deg[v]++;
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void Gauss(){
	int i,j,k,num;double tmp;
	for(i=1;i<=cnt;i++){
		num=i;
		for(j=i+1;j<=cnt;j++){
			if(fabs(a[num][i])<fabs(a[j][i])) num=j;
		}
		if(num!=i) for(j=1;j<=cnt+1;j++) swap(a[i][j],a[num][j]);
		for(j=i+1;j<=cnt;j++){
			if(i!=j&&a[j][i]){
				tmp=a[j][i]/a[i][i];
				for(k=1;k<=cnt+1;k++) a[j][k]-=a[i][k]*tmp;
			}
		}
	}
	for(i=cnt;i>=1;i--){
		for(j=i+1;j<=cnt;j++) a[i][cnt+1]-=a[i][j]*ans[j];
		ans[i]=a[i][cnt+1]/a[i][i];
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();op1=read();op2=read();int i,j,t1,t2,u1,u2,v1,v2,tid;cnt=n*n;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) scanf("%lf",&p[i]),go[i]=(1.0-p[i])/deg[i];
	for(u1=1;u1<=n;u1++){
		for(u2=1;u2<=n;u2++){
			tid=id(u1,u2);
			a[tid][tid]=-1;
			if(u1!=u2) a[tid][tid]+=p[u1]*p[u2];
			for(i=first[u1];~i;i=e[i].next){
				v1=e[i].to;if(v1==u2) continue;
				a[tid][id(v1,u2)]=go[v1]*p[u2];
			}
			for(i=first[u2];~i;i=e[i].next){
				v2=e[i].to;if(v2==u1) continue;
				a[tid][id(u1,v2)]=p[u1]*go[v2];
			}
			for(i=first[u1];~i;i=e[i].next){
				for(j=first[u2];~j;j=e[j].next){
					v1=e[i].to;v2=e[j].to;if(v2==v1) continue;
					a[tid][id(v1,v2)]=go[v1]*go[v2];
				}
			}
		}
	}
	a[id(op1,op2)][cnt+1]-=1;
	Gauss(); 
	for(i=1;i<=n;i++) printf("%.6lf ",ans[id(i,i)]);
}
