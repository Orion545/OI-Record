#include<cstdio>
#include<fstream>
#include<cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)

ifstream fin("defense.in");
ofstream fout("defense.out");

const int N=2e3+10;

int f[N],g[N],a,A,b,B,inf;
int p[N],n,m;
int w[N][N],c[N];

void dp(int x,int lst){
	int res=0;
	f[x]=p[x];
	rep(i,1,c[x])
		if(w[x][i]-lst){
			dp(w[x][i],x);
			f[x]+=min(f[w[x][i]],g[w[x][i]]);
			if(f[w[x][i]]>=inf)g[x]=inf;
			else g[x]+=f[w[x][i]];
			++res;
		}
	
	if(x==a){
		if(A==0)f[x]=inf;
		else g[x]=inf;
	}
	if(x==b){
		if(B==0)f[x]=inf;
		else g[x]=inf;
	}
}

int main(){
	fin>>n>>m;
	char t=0;
	while(t!='1'&&t!='2'&&t!='3')fin>>t;
	rep(i,1,n)fin>>p[i];
	rep(i,1,n-1){
		fin>>a>>b;
		w[a][++c[a]]=b,w[b][++c[b]]=a;
	}
	
	inf=1e9;
	while(m--){
		fin>>a>>A>>b>>B;
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		dp(1,0);
		int ans=min(f[1],g[1]);
		if(ans>=inf)fout<<"-1\n";
		else fout<<ans<<"\n";
	}
	
	return 0;
}


