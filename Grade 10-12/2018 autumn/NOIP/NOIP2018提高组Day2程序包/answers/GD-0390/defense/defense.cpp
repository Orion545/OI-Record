#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int>map[100001];
int w[100001],f[100001],depth[100001];
const long long inf=99999999999;
int x,y,t;
bool sb1,sb2;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int n,m;
long long dp[100001][2];
long long jdp[100001][2];
void dfs1(int u,int fa){
	int i,v;
	bool flag=false;
	int temp1=0,temp2=0;
	f[u]=fa;
	depth[u]=depth[fa]+1;
	for(i=0;i<map[u].size();i++){
		v=map[u][i];
		if(v!=fa){
			flag=true;
			dfs1(v,u);
			temp1+=min(dp[v][0],dp[v][1]);
			temp2+=dp[v][1];
		}
	}
	if(!flag){
		dp[u][1]=w[u];
	}
	else{
		dp[u][0]=temp2;
		dp[u][1]=w[u]+temp1;
	}
	
}

void jdfs(int x,int y){
	int u,v,i;
	int temp1,temp2;
	jdp[x][sb1]=dp[x][sb1];
	jdp[x][sb1^1]=inf;
	jdp[y][sb2]=dp[y][sb2];
	jdp[y][sb2^1]=inf;
	while(f[x]!=f[y]){
		if(depth[x]<depth[y]){
			swap(x,y);
		}
		u=f[x];
		temp1=temp2=0;
		for(i=0;i<map[u].size();i++){
			v=map[u][i];
			if(v!=f[u]){
				if(v==x||v==y){
					temp1+=min(jdp[v][0],jdp[v][1]);
					temp2+=jdp[v][1];
				}
				else{
					temp1+=min(dp[v][0],dp[v][1]);
					temp2+=dp[v][1];					
				}	
			}
		}
		if(!jdp[u][0]){
			jdp[u][0]=temp2;			
		}
		if(!jdp[u][1]){
			jdp[u][1]=w[u]+temp1;			
		}
		x=f[x];
	}
	while(x!=1){
		u=f[x];
		temp1=temp2=0;
		for(i=0;i<map[u].size();i++){
			v=map[u][i];
			if(v!=f[u]){
				if(v==x||v==y){
					temp1+=min(jdp[v][0],jdp[v][1]);
					temp2+=jdp[v][1];
				}
				else{
					temp1+=min(dp[v][0],dp[v][1]);
					temp2+=dp[v][1];					
				}	
			}
		}
		jdp[u][0]=temp2;
		jdp[u][1]=w[u]+temp1;
		x=f[x];		
	}
}

int main(){
	int i;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	t=read();
	for(i=1;i<=n;i++){
		w[i]=read();
	}
	for(i=1;i<n;i++){
		x=read();
		y=read();
		map[x].push_back(y);
		map[y].push_back(x);
	}
	dfs1(1,0);
//	cout<<"ok"<<endl;
	for(i=1;i<=m;i++){
		memset(jdp,0,sizeof(jdp));
		x=read();
		sb1=read();
		y=read();
		sb2=read();
		if((!sb1)&&(!sb2)&&(x==f[y]||y==f[x])){
			printf("-1\n");
		}
		else{
			jdfs(x,y);	
			printf("%lld\n",min(jdp[1][0],jdp[1][1]));	
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
	
	
	
}
