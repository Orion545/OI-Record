#include<bits/stdc++.h>
using namespace std;
const int MAXN=50000;
int n,m,Ans,tot;
int Sum[MAXN];int A[1001][1001]; 
int head[MAXN+1],Next[MAXN*2-1],Num[MAXN];
bool f[MAXN+1];
struct bian{
	int X;
	int Y;
	int L;
}B[MAXN];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
void add(int x,int y,int i){
	Next[++tot]=head[x];head[x]=tot;Num[tot]=i;
}
void work(){
	int k=Sum[1];
	for(int i=2;i<=m;i++){
		if(Sum[i]<k)k=Sum[i];
	}
	Ans=max(k,Ans);
}
void dfs(int num,int last,int sum){
	if(num>m){work();return;}
	if(sum>Ans){
		Sum[num]=sum;
		for(int i=1;i<n;i++){
			if(!f[i]){
				f[i]=1;
				dfs(num+1,i,B[i].L);
				f[i]=0;
			}
		}
	}
	for(int i=head[B[last].X];i;i=Next[i]){
		if(!f[Num[i]]){
			f[Num[i]]=1;
			dfs(num,Num[i],sum+B[Num[i]].L);
			f[Num[i]]=0;
		}
	}
	for(int i=head[B[last].Y];i;i=Next[i]){
		if(!f[Num[i]]){
			f[Num[i]]=1;
			dfs(num,Num[i],sum+B[Num[i]].L);
			f[Num[i]]=0;
		}
	}
}
int main(){
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
	n=read();m=read();
	if(n<=1000&&m==1){
		memset(A,127/3,sizeof(A));
		for(int i=1;i<n;i++){
			int x=read(),y=read(),l=read();
			A[x][y]=A[y][x]=l;Ans=max(Ans,l);
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==k||j==k)continue;
					if(A[i][j]>A[i][k]+A[k][j])A[i][j]=A[i][k]+A[k][j],Ans=max(Ans,A[i][j]);
				}
			}
		}
		cout<<Ans;exit(0);
	}
	for(int i=1;i<n;i++){
		int a=read(),b=read(),l=read();
		B[i].X=a;B[i].Y=b;B[i].L=l;
		add(a,b,i);add(b,a,i);
	}
	for(int i=1;i<n;i++){
		f[i]=1;
		dfs(1,i,B[i].L);
		f[i]=0;
	}
	cout<<Ans+1;
	return 0;
}
