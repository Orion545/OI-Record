#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MM 100110
#define N 10010
#define ll long long
#define itn int
int xx;int ff;char ch;
inline int read(){
	ch=getchar();ff=1;xx=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
struct edge{
	int v,nex;
}e1[MM<<1];
int head[MM],elen=0;
inline void adde(int u,int v){
	e1[++elen].v=v;
	e1[elen].nex=head[u];
	head[u]=elen;
}
int n,m;
int tz,tz2;
int a[MM];
bool zz[MM];
int ask1,ask2,op1,op2;
ll ans;
inline void dfs(int u,ll nans){
	if((ask1==u&&op1)||(ask2==u&&op2)){
		if(u==n){
			ans=min(ans,nans+a[u]);
			return;
		}
		zz[u]=1;
		dfs(u+1,nans+a[u]);
		return;
	}
	if((ask1==u&&(!op1))||(ask2==u&&(!op2))){
		//cerr<<"C"<<u<<endl;
		if(u==n){
			ans=min(ans,nans);
			return;
		}
		zz[u]=0;
		dfs(u+1,nans);
		return;
	}
	
	if(zz[u-1]){
		if(u==n){
			ans=min(ans,nans);
			return;
		}
		zz[u]=1;
		dfs(u+1,nans+a[u]);
		zz[u]=0;
		dfs(u+1,nans);
	}else{
		nans+=a[u];
		zz[u]=1;
		if(u==n){
			ans=min(ans,nans);
		}else dfs(u+1,nans);
	}
}
ll dp[MM][2];
inline bool muon(int u){
	return (ask1==u&&op1)||(ask2==u&&op2);
}
inline bool mof(int u){
	return (ask1==u&&(!op1))||(ask2==u&&(!op2));
}
bool noans=0;
inline ll dfs2(int u,int fa){
//	cerr<<"D"<<u<<" "<<fa<<endl;
	dp[u][0]=-1;
	dp[u][1]=-1;
	ll x=0,y=2147383647777;
	bool flag=0;//must hold on
	bool flag2=0;//must turn off
	int siz=0;
	for(int ee=head[u];ee;ee=e1[ee].nex){
		int v=e1[ee].v;
		if(v==fa)continue;
		++siz;
		if(dfs2(v,u)==-1){
			return -1;
		}
		//x+=dp[u][0];
	}
	if(siz==0){
		dp[u][0]=0;
		dp[u][1]=a[u];
		if(muon(u)){
			dp[u][0]=-1;
		}
		if(mof(u)){
			dp[u][1]=-1;
		}
		if(dp[u][0]==-1&&dp[u][1]==-1){
			noans=1;
			return -1;
		}
	}
	#define ccc cerr<<endl<<"IM"<<u<<" dp="<<dp[u][0]<<" "<<dp[u][1]<<endl;
//	ccc;
	//x=0;
	if(!muon(u)&&(siz!=0)){
		//cerr<<"u="<<u<<endl;
	for(int ee=head[u];ee;ee=e1[ee].nex){
		if(dp[e1[ee].v][1]==-1)continue;
		//cerr<<"I'm"<<u<<" Choose"<<e1[ee].v<<"To Light"<<endl;
		x=dp[e1[ee].v][1];
		for(int e2=head[u];e2;e2=e1[e2].nex){
			if(e1[ee].v==e1[e2].v||e1[e2].v==fa)continue;
			int v=e1[e2].v;
			//cerr<<"V="<<v<<" x="<<x<<endl;
			if(dp[v][0]==-1){
				x+=dp[v][1];
			}else{
				x+=dp[v][0];
			}
		}
		//cerr<<"UD !  x="<<x<<" "<<endl;
		y=min(y,x);
	}
		dp[u][0]=(y==2147383647777?(-1):y);
		//cerr<<"QQ"<<dp[u][0]<<endl;
	}
	//cerr<<"ASDOJQWBNDO:QWINBDOIW"<<u<<" "<<y<<endl;
	y=2147383647777;
	if(!mof(u)&&(siz!=0)){
		x=a[u];
		//cerr<<"IM"<<u<<" I light myself"<<endl;
		for(int ee=head[u];ee;ee=e1[ee].nex){
			int v=e1[ee].v;
			if(v==fa)continue;
			if(dp[v][0]==-1){
				x+=dp[v][1];
			}else{
				x+=dp[v][0];
			}
			//cerr<<"Q"<<v<<endl;
		}
		//cerr<<"x="<<x<<endl;
		y=min(x,y);
		
		dp[u][1]=(y==2147383647777?(-1):y);
	}
	//cerr<<endl<<"IM"<<u<<" dp="<<dp[u][0]<<" "<<dp[u][1]<<endl;
	
	if(((dp[u][1]==dp[u][0])&&(dp[u][0]==-1)))return -1;
	//cerr<<"Q"<<endl;
	if(dp[u][0]==-1)return dp[u][1];
	if(dp[u][1]==-1)return dp[u][0];
	return min(dp[u][1],dp[u][0]);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,0,sizeof(head));
	n=read();m=read();
	ch=getchar();
	while(ch<'A'||ch>'C')ch=getchar();
	tz=ch-'A'+1;
	ch=getchar();
	tz2=ch-'0';
	for(int i=1;i<=n;++i)a[i]=read();
	int x,y,z,k;

	for(int i=1;i<n;++i){
		x=read();y=read();
		adde(x,y);
		adde(y,x);
	}
	if(tz==1){
		for(int i=0;i<m;++i){
			x=read();y=read();z=read();k=read();
			ask1=x;ask2=z;op1=y;op2=k;
			if(y+k==0&&((x==z+1)||(z==x+1))){
				printf("-1\n");continue;
			}
			memset(zz,0,sizeof(zz));
			ans=2147383647777;
			dfs(1,0);
			printf("%lld\n",ans);
		}
		return 0;
	}	
	for(int i=0;i<m;++i){
		x=read();y=read();z=read();k=read();
		ask1=x;ask2=z;op1=y;op2=k;
		noans=0;
		ans=dfs2(1,1);
		printf("%lld\n",noans?-1:ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
