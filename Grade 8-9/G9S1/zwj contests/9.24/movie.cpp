#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a[10000010],lazy[10000010];
int d[30],c[30],x[30][1010],ans=50;
bool vis[30];
void clear(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	int son=num<<1;
	a[son]=a[son]|lazy[num];a[son+1]=a[son+1]|lazy[num];
	lazy[son]|=lazy[num];lazy[son+1]|=lazy[num];
	lazy[num]=0;
}
void change(int l,int r,int ql,int qr,int num,int sig){
//	cout<<"change "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<num<<ends<<sig<<endl;
	int son=num<<1,mid=(l+r)>>1;
	clear(l,r,num);
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr){
//		cout<<"	reach"<<endl;
		a[num]|=sig;lazy[num]|=sig;return;
	}
	if(mid>=ql) change(l,mid,ql,qr,son,sig);
	if(mid<qr) change(mid+1,r,ql,qr,son+1,sig);
	a[num]=a[son]|a[son+1];
}
int find(int l,int r,int q,int num){
	clear(l,r,num);
	if(l==r) return a[num];
	int son=num<<1,mid=(l+r)>>1;
	clear(l,r,num);
	if(mid>=q) return find(l,mid,q,son);
	else return find(mid+1,r,q,son+1);
}
void dfs(int t,int k){
//	cout<<"dfs "<<t<<ends<<k<<endl;
	if(t>=n){
//		cout<<"	renew "<<ans<<ends<<k<<endl;
		ans=min(ans,k);return;
	}
	int s=find(1,n,t,1),i,j;
	for(i=1;i<=m;i++){
		if((s&(1<<(i-1)))&&!vis[i]){
//			cout<<"	watch "<<t<<ends<<k<<ends<<i<<endl;
			for(j=1;j<=c[i];j++){
				if(x[i][j]>t) break;
			} 
			j--;
			vis[i]=1;
			dfs(x[i][j]+d[i],k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("movie.in","r",stdin);
	freopen("movie.out","w",stdout);
	int i,j,t1;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&d[i],&c[i]);
		for(j=1;j<=c[i];j++){
			scanf("%d",&t1);x[i][j]=t1;
			change(1,n,t1,t1+d[i],1,(1<<(i-1)));
//			cout<<endl;
		}
	}
	dfs(0,0);
	if(ans==50) printf("-1");
	else printf("%d",ans);
}
