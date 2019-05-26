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
const int dx[9]={0,-1,-1,-1,0,0,1,1,1},dy[9]={0,-1,0,1,-1,1,-1,0,1};
int n,m;
int a[110][110];
int main(){
	n=read();m=read();
	int i,j;char s[110];int ti,tj,k,tmp;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='*') a[i][j+1]=-1;
			else if(s[j]=='.') a[i][j+1]=0;
			else a[i][j+1]=(int)(s[j]-'0');
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			tmp=0;if(a[i][j]==-1) continue;
//			cout<<i<<ends<<j<<ends<<a[i][j]<<endl;
			for(k=1;k<=8;k++){
				ti=i+dx[k];tj=j+dy[k];
//				cout<<"tij "<<ti<<ends<<tj<<ends<<a[ti][tj]<<endl;
				if(ti<1||tj<1||ti>n||tj>m||a[ti][tj]!=-1) continue;
				tmp++;
			}
			if(tmp!=a[i][j]){
				printf("NO");return 0;
			}
		}
	} 
	puts("YES");
}
