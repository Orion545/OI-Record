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
int n,m,color,a[510][510],del[510][510][10]={0},state[510][510][10]={0},ans=0;
void dfs(int x,int cur,int cnt){
//	cout<<"dfs "<<x<<' '<<cur<<' '<<cnt<<'\n';
	ans=max(cur,ans);
	int i,j,k,tmp=cur;
	for(k=1;k<=color;k++){
		if(k==x) continue;
		cur=tmp;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				state[i][j][cnt+1]=state[i][j][cnt];
				if(a[i][j]==k&&state[i][j][cnt+1]==0) 
					state[i][j][cnt+1]=1,cur++;
				if(a[i][j]!=k&&state[i][j][cnt+1]==1&&del[i][j][k]) 
					state[i][j][cnt+1]=0,cur--;
//				cout<<state[i][j][cnt+1];
			}
//			cout<<'\n';
		}
		if(cur>tmp) dfs(k,cur,cnt+1);
	}
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout); 
	n=read();m=read();color=read();int i,j,k,l,r;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	for(k=1;k<=color;k++){
		for(j=1;j<=m;j++){
			l=n+1;r=0;
			for(i=1;i<=n;i++)
				if(a[i][j]==k) l=min(l,i),r=max(r,i);
			for(i=l+1;i<=r-1;i++) del[i][j][k]=1;
		}
		for(i=1;i<=n;i++){
			l=m+1;r=0;
			for(j=1;j<=m;j++)
				if(a[i][j]==k) l=min(l,j),r=max(r,j);
			for(j=l+1;j<=r-1;j++) del[i][j][k]=1;
		}
	}
	dfs(0,0,1);
	printf("%d\n",ans);
}
