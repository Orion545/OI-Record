#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
#define maxn 10
#define maxx 1000005
int n,m;
long long pow(long long a,long long b,long long p){
	long long ans=1;
	while(b){
		if(b&1)ans=(ans*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
long long tf[maxn];
long long dp[1<<10];
int mp[10][maxx];
long long now=0;
long long mx;
bool mark=true;
void dfs(int x,int y,int gs){
	if(!mark)return;
	if(x==n&&y==m){
		if(now>mx){
			mark=false;
		}
		else{
			mx=min(mx,now);
		}
		return;
	}
	if(y+1<=m){
		if(mp[x][y+1])
		now|=(1<<(gs-1));
		dfs(x,y+1,gs-1);
		if(mp[x][y+1])
		now^=(1<<(gs-1));
	}
	if(x+1<=n){
		if(mp[x+1][y])
		now|=(1<<(gs-1));
		dfs(x+1,y,gs-1);
		if(mp[x+1][y])
		now^=(1<<(gs-1));
	}
}
bool check(){
/*	for(int i=0;i<(1<<(n+m-2));i++){
		int temp=0;
		for(int j=0;j<n+m-2){
			if(i&(1<<j))temp++;
		}
		if(temp!=n-1)continue;
		int nowx=1,nowy=1;
		int tot=0;
		do{
		   if((1<<(nowy-1))&tf[nowx]){
		   	  dp[i]|=(1<<)
		   }	
		}while(!(nowx==n&&nowy==m))
	}*/
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(tf[i]&(1<<j)){
				mp[i][j+1]=1;
			}
		}
	}
//	puts("");
//	puts("");
	mx=1<<(20);
	now=0;
//	cout<<now<<" "<<mx<<endl;
	if(mp[1][1]==1){
		now|=(1<<(n+m-2));
	}
	mark=true;
	dfs(1,1,n+m-2);
	if(!mark)return false;
	else return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		cout<<pow(2,m,1000000007)<<endl;
		return 0;
	}
	else if(n==2){
		long long temp=pow(3,m-1,1000000007);
		temp=(temp)%1000000007;
		long long ans;
//		cout<<temp<<endl;
		ans=(temp*4)%(1000000007);
		cout<<ans<<endl;
		return 0;
	}
	else if(n==3){
/*		if(n==2){
			int ans=0;
			for(int i=0;i<(1<<m);i++){
				tf[1]=i;
				for(int j=0;j<(1<<m);j++){
					tf[2]=j;
					if(check())ans++;
				}
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=0;i<(1<<m);i++){
				tf[1]=i;
				for(int j=0;j<(1<<m);j++){
					tf[2]=j;
					for(int k=0;k<(1<<m);k++){
						tf[3]=k;
						if(check())ans++;
					}
				}
			}
			cout<<ans<<endl;			
		}*/
		long long temp1=pow(2,m,1000000007);
		long long temp2=5*m-1;
//		cout<<temp1<<" "<<temp2<<endl;
		temp2%=1000000007;
//		cout<<temp1*temp2<<endl;
	    long long ans=(temp1*temp2)%(1000000007);
		cout<<ans<<endl;
		return 0;
	}
}
