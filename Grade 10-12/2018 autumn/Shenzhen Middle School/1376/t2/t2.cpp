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
int n,m,S,a[210],b[210],x[210],y[210];
struct node{
	int x,y;
}in[210];
inline bool cmp(node l,node r){
	if(l.x==r.x) return l.y>r.y;
	else return l.x<r.x;
}
int dp[110][110][110],lim[1000010];
int main(){
	int T=read();
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(dp,0,sizeof(dp));
		memset(lim,0,sizeof(lim));
		memset(in,0,sizeof(in));
		n=read();S=read();int i,j,k,mid=0,t1,t2;
		for(i=1;i<=n;i++){
			t1=read();t2=read();
			in[i].x=t1;in[i].y=t2;
		}
		sort(in+1,in+n+1,cmp);
		for(i=1;i<=n;i++){
			if(i!=1&&in[i].x==in[i-1].x) continue;
			mid++;
			x[mid]=in[i].x;
			y[mid]=in[i].y;
		}
		n=mid;
		for(i=1;i<=n;i++) b[i]=y[i];
		sort(b+1,b+n+1);
		m=unique(b+1,b+n+1)-b-1;
		for(i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,y[i])-b;

		j=m;b[0]=0;
		for(i=1;i<=S;i++){
			while((ll)b[j]*(ll)i>(ll)S) j--;
			lim[i]=j;
		}
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				for(k=0;k<m;k++) dp[i][j][k]=1e9;
				dp[i][j][m]=0;
			}
		}

		for(i=n;i>=1;i--){
			for(k=0;k<m;k++){
				if(k>=a[i]) dp[i][i][k]=0;
				else dp[i][i][k]=1;
			}
			for(j=i+1;j<=n;j++){
				for(k=m-1;k>=0;k--){
					dp[i][j][k]=1e9;
					for(mid=i;mid<j;mid++) 
						dp[i][j][k]=min(dp[i][j][k],dp[i][mid][k]+dp[mid+1][j][k]);

					if(x[j]-x[i]>S) continue;
					t1=lim[x[j]-x[i]];
					if(t1>k) dp[i][j][k]=min(dp[i][j][k],dp[i][j][t1]+1);
				}
			}
		}
		cout<<dp[1][n][0]<<'\n';
	}
}
