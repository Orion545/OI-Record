#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int vis[1000010],cntp,pri[1000010];
int n;
int biao[10][15]={
{0,1,1,4,5,7,7,25,25,25},
{0,1,1,4,5,7,7,25,25,25},
{0,1,1,4,5,7,7,25,25,25},
{0,1,1,4,5,7,7,19,27,29,29},
{0,1,1,7,13,2,1,1,27,3,1},
{0,1,1,1,4,13,1,3,31,31,1,1},
{0,1,1,1,4,13,1,3,31,31,1,1},
{0,1,1,1,4,13,1,3,31,31,1,1},
{0,1,1,1,4,13,1,3,31,31,1,1}};
int main(){
	n=read();int i,j,k;
	vis[1]=0;
	for(i=2;i<=n;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>n) break;
			vis[k]=1;if(i%pri[j]==0) break;
		}
	}
	printf("%d %d\n",(n<=16)?(n-1):n,cntp);
	if(n<=16){
		for(i=1;i<=cntp;i++) puts("1");
		return 0;
	}
	if(n>=26&&n<=34){
		for(i=1;i<=cntp;i++) printf("%d\n",biao[n-26][i]);
		return 0;
	}
	int p,q,st=1;
	while(pri[st]*pri[st]<n) st++;
	for(i=st;i<=cntp;i++){
		for(j=i+1;j<=cntp;j++){
			if(pri[i]+pri[j]>=n) break;
			if(pri[j]%pri[i]==1){
				p=i;q=j;goto jumpout;
			}
		}
	}
	jumpout:
	for(i=1;i<=cntp;i++){
		if(i!=p&&i!=q) puts("1");
		if(i==p) printf("%d\n",pri[p]+2);
		if(i==q) printf("%d\n",pri[q]+pri[p]+1);
	}
}
