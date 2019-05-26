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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[500010],cnte=-1;
struct edge{
	int to,next;double w;
	edge(){}
	edge(int aa,int bb,double cc){to=aa;next=bb;w=cc;}
}a[1000010];
inline void add(int u,int v,double w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
double f1[500010],f2[500010],pos[500010];
void dfs1(int u,int f){
	int i,v;double tmp;
	f1[u]=pos[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		tmp=a[i].w*f1[v];
		f1[u]=(f1[u]+tmp-f1[u]*tmp);
	}
//	cout<<"dfs1 "<<u<<' '<<f1[u]<<'\n';
}
void dfs2(int u,int f,double w){
	int i,v;
	if(fabs(1.0-f1[u]*w)>=1e-6){
		double t1=(f2[f]-f1[u]*w)/(1.0-f1[u]*w);
		f2[u]=(f1[u]+t1*w-f1[u]*t1*w);
	}
	else f2[u]=1.0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs2(v,u,a[i].w);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,(double)t3*0.01);
	}
	for(i=1;i<=n;i++) pos[i]=(double)read()*0.01;
	dfs1(1,0);dfs2(1,0,0);
	double ans=0;
	for(i=1;i<=n;i++) ans+=f2[i];
	printf("%.6lf\n",ans);
}
