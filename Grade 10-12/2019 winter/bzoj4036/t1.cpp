#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define eps 1e-7
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
int m,n;double f[1100010];
int vis[30];
int main(){
	m=read();n=(1<<m);int i,j,k;
	for(i=0;i<n;i++){
		scanf("%lf",&f[i]);
		if(f[i]<=eps) continue;
		for(j=0;j<m;j++) if(i&(1<<j)) vis[j]=1;
	}
	for(i=0;i<m;i++) if(!vis[i]){puts("INF");return 0;}
	//fwt
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) if(j&(1<<i)) f[j]+=f[j^(1<<i)];
	
	for(i=0;i<n;i++){
		if(i==n-1) f[i]=0;
		f[i]=f[i]/(f[i]-1);
	}

	//ifwt
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) if(j&(1<<i)) f[j]-=f[j^(1<<i)];
	
	printf("%.10lf\n",f[n-1]+1);
}
