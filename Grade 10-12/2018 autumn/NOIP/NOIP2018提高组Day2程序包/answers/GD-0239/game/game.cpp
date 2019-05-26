#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

#define mod 1000000007
int n,m,ans=0,a[6]={0,2,12,112,1080,7136};

//bool check(){
//	queue<int> q,p;
//	q.push(1),p.push(1);
//	while(!q.empty()){
//		int x=q.front();q.pop();
//		int y=p.front();p.pop();
//		if(x==n){
//			if(y!=n)q.push(x),p.push(y+1);
//		}
//		if(y==n){
//			if(x!=n)q.push(x+1),p.push(y);
//		}
//		if(y==n||x==n)continue;
//		if((a[x+1][y]||a[x][y+1])&&(a[x+1][y]==0))return false;
//		if(x!=1&&y!=1&&!(a[x-1][y]==0&&a[x][y-1]==1)&&(a[x+1][y]||a[x][y+1])&&(a[x+1][y]!=a[x][y+1]))return false;
//		else{
//			q.push(x+1),p.push(y);
//			q.push(x),p.push(y+1);
//		}
//	}
//	return true;
//}

int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1LL*ans*x%mod;
		y>>=1,x=1LL*x*x%mod;
	}
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans=a[min(n,m)];
	if(m<n)swap(n,m);
	(ans=1LL*ans*qpow(2,(n*(m-n))))%=mod;
	printf("%d",ans);
	return 0;
}
