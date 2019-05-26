#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n,m,ls[200007],tot,x,y,z,w;
string s;
int f[3007],rd[200007];
bool g[3007][3007];
long long a[200007];
struct edge{
	int to,next;
}e[200007];
long long ans;

void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=ls[x];
	ls[x]=tot;
}

bool update(){
	if (f[x]!=y)	return false;
	if (f[z]!=w)	return false;
	for(int i=1;i<=n;i++){
		if (f[i]) continue;
		bool jiancha=1;
		for(int j=ls[i];j;j=e[j].next)
			if (!f[e[j].to]){
				jiancha=0;
				break;
			}	
		if (!jiancha) return false;
	}
	return true;
}

void Dfs(int dep,long long sum){
	if (sum>ans) return;
	if(dep>n){
		if(update()) ans=min(ans,sum);
		return;
	}
	f[dep]=1;
	Dfs(dep+1,sum+a[dep]);
	f[dep]=0;
	if (sum>ans) return;
	Dfs(dep+1,sum);
}

long long min(long long a,long long b){
	return a<b?a:b;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=0;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x][y]=1;
		g[y][x]=1;
		rd[x]++;
		rd[y]++;
		add(x,y);
		add(y,x);
	}
	if (s[0]!='A'||n<=30){
		for(int xunwen=1;xunwen<=m;xunwen++){
			scanf("%d%d%d%d",&x,&y,&z,&w);
			ans=10000000;
			if (g[x][z]&&(y==0&&w==0)){
				printf("-1\n");	
				continue;
			}
			Dfs(1,0);
			if (ans!=10000000) cout<<ans<<endl;
			else printf("-1\n");
		}
	}
	else{
		int qidian=0;
		for(int i=1;i<=n;i++)	if(rd[i]<2)	qidian=i;
		for(int xunwen=1;xunwen<=m;xunwen++){
			scanf("%d%d%d%d",&x,&y,&z,&w);
			int p=0,Site=qidian,pre=0;
			bool can=0,can2=0;
			int cnt=1;
			ans=a[qidian];
			long long sum=0;
			while(cnt<n){
				if (can)break;
				for(int i=ls[Site];i;i=e[i].next){
					int v=e[i].to;
					if (v==pre) continue;
					if (p==1){
						if (x==v&&y==0){
							can=1;
							break;
						}
						if (z==v&&w==0){
							can=1;
							break;
						}
						ans+=a[v];
						p=0;
						pre=Site;
						Site=v;
						cnt++;
						break;
					}
					else{
						if (x==v&&y==1){
							can=1;
							break;
						}
						if (z==v&&w==1){
							can=1;
							break;
						}
						p=1;
						pre=Site;
						Site=v;
						cnt++;
						break;
					}
				}
			}
			Site=e[ls[qidian]].to;	sum=a[Site];	cnt=2;	p=0;	pre=qidian;
			while(cnt<n){
				if (can2)break;
				for(int i=ls[Site];i;i=e[i].next){
					int v=e[i].to;
					if (v==pre) continue;
					if (p==1){
						if (x==v&&y==0){
							can2=1;
							break;
						}
						if (z==v&&w==0){
							can2=1;
							break;
						}
						sum+=a[v];
						p=0;
						pre=Site;
						Site=v;
						cnt++;
						break;
					}
					else{
						if (x==v&&y==1){
							can2=1;
							break;
						}
						if (z==v&&w==1){
							can2=1;
							break;
						}
						p=1;
						pre=Site;
						Site=v;
						cnt++;
						break;
					}
				}
			}
			if (can)	ans=-1;
			if (can2)	sum=-1;
			printf("%lld\n",min(ans,sum));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
