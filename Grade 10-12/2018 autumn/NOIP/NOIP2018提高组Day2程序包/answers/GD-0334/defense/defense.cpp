#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#define ll long long int 
#define INF 0x3f3f3f3f
#define MAXN 100005
using namespace std;

int n,m;
string type;
int p[MAXN];
int nex[MAXN];
int ok[MAXN];
int f[MAXN][2];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>type;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		nex[i]=i+1;
	}
	int opu,opv;
	for(int i=1;i<=m;i++){
		memset(ok,-1,sizeof(ok));
		scanf("%d%d%d%d",&u,&opu,&v,&opv);
		if(opu==1&&opv==1&&(nex[u]==v||nex[v]==u)){
			printf("-1\n");
			continue;
		}
		int sum=0;
		if(u>v){
			swap(u,v);
			swap(opu,opv);
		}
		if(u>1&&opu==0){
			f[u-1][1]=p[i];
			f[u-1][0]=INF;
			for(int i=u-2;i>=1;i++){
				f[i][1]=min(f[i+1][1]+p[i],f[i-1][0]+p[i]);
				f[i][0]=f[i+1][1];
			}
		}
		else if(u==1&&opu==0){
			f[1][1]=INF;
			f[1][0]=0;
			//cout<<f[1][0]<<f[1][1];
		}
		else{
			//cout<<"ok";
			f[u][1]=p[i];
			f[u][0]=INF;
			for(int i=u-1;i>=1;i++){
				f[i][1]=min(f[i+1][1]+p[i],f[i+1][0]+p[i]);
				f[i][0]=f[i+1][1];
			}
		}
		//cout<<v;
		if(v<n&&opv==0){
			f[v+1][1]=p[i];
			f[v+1][0]=INF;
			for(int i=v+2;i<=n;i++){
				f[i][1]=min(f[i-1][1]+p[i],f[i-1][0]+p[i]);
				f[i][0]=f[i-1][1];
			}
		}
		else if(v==n&&opv==0){
			f[n][1]=INF;
			f[n][0]=0;
		}
		else{
			//cout<<"ok";
			f[v][1]=p[v];
			f[v][0]=INF;
			//cout<<f[2][1]<<f[2][0];
			for(int i=v+1;i<=n;i++){
				f[i][1]=min(f[i-1][1]+p[i],f[i-1][0]+p[i]);
				f[i][0]=f[i-1][1];
			}
		}
		//cout<<f[1][0]<<f[1][1]<<f[n][0]<<f[n][1];
		sum+=min(f[1][0],f[1][1])+min(f[n][0],f[n][1]);
		printf("%d\n",sum);
	}
}
