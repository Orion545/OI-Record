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
int n;double dis[110][110],x[110],y[110];
inline double sqr(double xx){return xx*xx;}
inline double getdis(int i,int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
int check(int pos){
	for(int i=1;i<pos;i++){
		if(fabs(getdis(i,pos)-dis[i][pos])>1e-4) return 0;
	}
	return 1;
}
int dfs(int u){
	if(u==n+1){
		for(int i=1;i<=n;i++) printf("%.6lf %.6lf\n",x[i],y[i]);
		return 1;
	}
	double w=acos((sqr(dis[1][2])+sqr(dis[1][u])-sqr(dis[2][u]))/(2.0*dis[1][2]*dis[1][u]));
	x[u]=x[1]+dis[1][u]*cos(w);
	y[u]=y[1]+dis[1][u]*sin(w);
	if(check(u)&&dfs(u+1)) return 1;
	x[u]=x[1]+dis[1][u]*cos(w);
	y[u]=y[1]-dis[1][u]*sin(w);
	if(check(u)&&dfs(u+1)) return 1;
	return 0;
}
int main(){
	n=read();int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lf",&dis[i][j]);
		}
	}
	x[1]=y[1]=0;
	x[2]=dis[1][2];y[2]=0;
	if(!dfs(3)) cout<<"ERROR!\n";
}
