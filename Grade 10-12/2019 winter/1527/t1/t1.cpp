#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,a[110][110],b[110][110],f[8000010];
inline int dfs(int s,int p){
	if(~f[s]) return f[s];
	f[s]=(p?-1e9:1e9);
	int x=n+1,y=1,i;
//	cout<<"dfs "<<s<<' '<<p<<' '<<'\n';
	for(i=0;i<n+m-1;i++){
		if((s>>i)&1) x--;
		else y++;
		if(((s>>i)&3)!=1) continue;
//		cout<<"check "<<i<<' '<<x<<' '<<y<<' '<<(s>>i)<<' '<<(s>>(i+1))<<'\n';
		if(p) f[s]=max(f[s],dfs(((s^(1<<i))|(2<<i)),p^1)+a[x][y]);
		else f[s]=min(f[s],dfs(((s^(1<<i))|(2<<i)),p^1)-b[x][y]);
	}
//	cout<<"finish "<<s<<' '<<p<<' '<<f[s]<<'\n';
	return f[s];
}
int main(){
	n=read();m=read();int i,j;
	memset(f,-1,sizeof(f));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			b[i][j]=read();
		}
	}
	f[((1<<n)-1)<<m]=0;
	printf("%d\n",dfs(((1<<n)-1),1));
}
