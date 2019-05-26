#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int a,b,c,d,n,m,x[110][110];
int vis[10];
int main(){
	a=read();b=read();c=read();d=read();int i,j;
	n=50;m=50;
	for(i=1;i<=25;i++){
		for(j=1;j<=25;j++){
			x[i][j]=1;
		}
	} 
	for(i=1;i<=25;i++){
		for(j=26;j<=50;j++){
			x[i][j]=2;
		}
	} 
	for(i=26;i<=50;i++){
		for(j=1;j<=25;j++){
			x[i][j]=3;
		}
	} 
	for(i=26;i<=50;i++){
		for(j=26;j<=50;j++){
			x[i][j]=4;
		}
	} 
	a--;b--;c--;d--;int tx,ty;
	for(i=1;i<=a;i++){
		vis[2]++;
		tx=(vis[2]-1)/12+1;ty=vis[2]%12;if(ty==0) ty=12;
		x[tx*2][25+ty*2]=1;
	} 
	for(i=1;i<=b;i++){
		vis[3]++;
		tx=(vis[3]-1)/12+1;ty=vis[3]%12;if(ty==0) ty=12;
		x[25+tx*2][ty*2]=2;
	} 
	for(i=1;i<=c;i++){
		vis[4]++;
		tx=(vis[4]-1)/12;ty=vis[4]%12;if(ty==0) ty=12;
		x[25+tx*2][25+ty*2]=3;
	} 
	for(i=1;i<=d;i++){
		vis[1]++;
		tx=(vis[1]-1)/12+1;ty=vis[1]%12;if(ty==0) ty=12;
		x[tx*2][ty*2]=4;
	} 
	printf("50 50\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(x[i][j]==1) putchar('A');
			if(x[i][j]==2) putchar('B');
			if(x[i][j]==3) putchar('C');
			if(x[i][j]==4) putchar('D');
		}
		putchar('\n');
	}
}
