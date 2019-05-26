#include<bits/stdc++.h>
using namespace std;
const int maxn=10100,inf=999999999;
int p[maxn],head[maxn],cnt=0,f[maxn][2];
int a,x,b,y;
struct edge{
	int to,next;
}e[maxn*2];
void add_edge(int s,int t){
	e[++cnt].next=head[s];e[cnt].to=t;head[s]=cnt;
}
bool book[maxn];
void dp(int s){
	book[s]=1;
	bool flag=0;
	f[s][1]=p[s];
	for(int i=head[s];i;i=e[i].next){
		if(!book[e[i].to]){
			flag=1;
			dp(e[i].to);
			if(s!=a&&s!=b){
				f[s][1]+=min(f[e[i].to][1],f[e[i].to][0]);
				f[s][0]+=f[e[i].to][1];
			}
			else{
				int t;
				if(s==a)t=x;
				else t=y;
			if(t==1){
				f[s][1]+=min(f[e[i].to][1],f[e[i].to][0]);
				f[s][0]=inf;
			}
			else{
				f[s][1]=inf;
				f[s][0]+=f[e[i].to][1];
			}
			}	
		}
	}
	if(!flag){
		if(s!=a&&s!=b){
			f[s][1]=p[s];
			f[s][0]=0;
		}
		else{
			int t;
			if(s==a)t=x;
			else t=y;
			if(t==1){
				f[s][1]=p[s];
				f[s][0]=inf;
			}
			else{
				f[s][1]=inf;
				f[s][0]=0;
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	string type;
	cin>>n>>m>>type;
	for(int i=1;i<=n;++i)cin>>p[i];
	for(int i=1;i<=n-1;++i){
		int s,t;
		cin>>s>>t;
		add_edge(s,t);
		add_edge(t,s);
	}
	for(int i=1;i<=m;++i){
		memset(f,0,sizeof(f));
		memset(book,0,sizeof(book));
		cin>>a>>x>>b>>y;
		dp(1);
		int ans=min(f[1][0],f[1][1]);
		if(ans>=inf)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
