#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
string s;
int ap[300005],a[600005],al[600005],an=0;
int re[300005],w[300005];
long long dp[300005],dp1[300005],dp0[300005];
long long inf=2123456789123;
bool use[300005];

long long min(long long x,long long y){
	return x<y?x:y;
}

void add(int x,int y){
	an++; a[an]=y; al[an]=ap[x]; ap[x]=an; re[x]++;
	an++; a[an]=x; al[an]=ap[y]; ap[y]=an; re[y]++;
}

long long f(int x,int fa){
	if(re[x]==1) return dp1[x]=w[x];
	else
}

void work(){
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1,x,y;i<m;i++){
		cin>>x>>y;
		add(x,y);
	}
	int root=1;
	while(re[root]==1) root++;
	for(int q=1,x,xn,y,yn,qn;q<=m;q++){
		cin>>x>>xn>>y>>yn;
		qn=1;
		if((xn==0&&yn==0)&&((re[x]==1&&a[ap[x]]==y)||(re[y]==1&&a[ap[y]]==x))){
			cout<<-1<<endl;
			qn=0;
	    }
	    if(qn){
	    	memset(dp2,0,sizeof(long long)*(n+2));
	    	memset(dp1,0,sizeof(long long)*(n+2));
	    	if(xn==0) dp1[x]=inf;
	    	else      dp0[x]=inf;
			if(y==0) dp1[y]=inf;
	    	else      dp0[y]=inf;
	        cout<<f(root,0)<<endl;
	    }
	}
}

void work1(){
	int x,y,xn,yn;
	for(int i=1;i<m;i++) cin>>x>>y;
	while(m--){
		cin>>x>>xn>>y>>yn;
		if((xn==0&&yn==0)&&((x==1&&y==2)||(x==2&&y==1)||(x==n-1&&y==n)||(x==n&&y==n-1))){cout<<-1<<endl;}
		else{
			if(xn==0) use[x]=1;
			if(yn==0) use[y]=1;
			dp[0]=0;
			dp[1]=use[1]?inf:w[1];
			for(int i=2;i<=n;i++){
				if(use[i]) dp[i]=inf;
				else{
					dp[i]=min(dp[i-1],dp[i-2]);
					if(i>2) dp[i]=min(dp[i],dp[i-3]);
					dp[i]+=w[i];
				}
			}
			cout<<min(dp[n-1],dp[n])<<endl;
			use[x]=0; use[y]=0;
		}
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>w[i];
	
	if(s[1]=='A') work1();
	else work();
	
	return 0;
}
