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
bool vis[100010];
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n=read(),m=read(),cur=0,i;
	for(i=1;i<=m;i++){
		cur=cur+n;cur%=m;
		vis[cur]=1; 
	}
	for(i=0;i<m;i++){
		if(!vis[i]){
			puts("No");return 0;
		}
	}
	puts("Yes");
}
