#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='0') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
int n,m,a[510][510]={0};
int main(){
	int i,j,k;char s[510];
	n=read();m=read();
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			if(s[j-1]=='.') continue;
			if(s[j-1]=='S') a[i][j]=1;
			else a[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=4;k++){
				int ti=i+dx[k],tj=j+dy[k];
				if(ti>n||ti<1||tj>m||tj<1) continue;
				if(a[i][j]==-1&&a[ti][tj]==1){
//					cout<<i<<ends<<j<<ends<<ti<<ends<<tj<<ends<<k<<endl;
					printf("No\n");return 0;
				}
			}
		}
	}
	printf("Yes\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==1) putchar('S');
			if(a[i][j]==-1) putchar('W');
			if(a[i][j]==0) putchar('D');
		}
			putchar('\n');
	}
}
