#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int c[100000];
int p[100000];
int n,m,a,x,b,y;  char tp[2];

int solve(int u,int v){
	int mint=0x7fffffff;
	if(u==v){
		if(u==1) mint=(c[2]==0)?p[1]:0;
		else if(u==n) mint=(c[n-1]==0)?p[1]:0;
		else if(c[u+1]+c[u-1]==0) mint=p[u]; else mint=0;
	}
	if(v>u){
		for(int i=u;i<=v-1;i++){
			if(c[i-1]==0) c[i]==1;
			else if(p[i]<p[i+1]) c[i]=1; else c[i]=0;
		}
		if(c[v-1]==0) c[v]=1; else c[v]=0;
	}
	if(u>v){
		for(int i=u;i>=v+1;i--){
			if(c[i+1]==0) c[i]==1;
			else if(p[i]<p[i-1]) c[i]=1; else c[i]=0;
		}
		if(c[v+1]==0) c[v]=1; else c[v]=0;
	}
	int tt=0;
	for(int i=u;i<=v;i++) if(c[i]==1) tt+=p[i];
	return min(tt,mint);
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m); scanf("%s",&*tp); //printf("N=%d M=%d Type=%s\n",n,m,tp);

	if(tp[0]=='A'){
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b);
		for(int rq=1;rq<=m;rq++){
			scanf("%d%d%d%d",&a,&x,&b,&y); //printf("%d %d %d %d\n",a,b,x,y);
			if(a>b){swap(a,b);swap(x,y);}
			memset(c,0,sizeof(c));
			if(abs(a-b)==1 && (x+y==0)){printf("-1\n");continue;}
			c[a]=x; c[b]=y;
			if(a==1) printf("%d\n",solve(a+1,b-1)+solve(b+1,n));
			else printf("%d\n",solve(1,a-1)+solve(a+1,b-1)+solve(b+1,n));
		}
	}
	fclose(stdout);
	return 0;
}
