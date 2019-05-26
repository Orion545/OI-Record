#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
string s;
#define N 100001
#define M 400001
#define next nextt
long long p[N];
int to[M],next[M],dep[N],ce[N],cnt=0;
void link(int u,int v){
	to[++cnt]=v;
	next[cnt]=ce[u];
	ce[u]=cnt;
	to[++cnt]=u;
	next[cnt]=ce[v];
	ce[v]=cnt;
}
void dfs(int v,int last)
{
	int pi;
	for(pi=ce[v];pi;pi=next[pi]){
		if(to[pi]==last)continue;
		dep[to[pi]]=dep[v]+1;
		dfs(to[pi],v);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	memset(ce,0,sizeof(ce));
	int i,a,b,x,y;
	if(s[0]=='A'){
		for(i=1;i<=n;i++){
			cin>>p[i];
		}
		for(i=1;i<n;i++) cin>>a>>b;
		long long t1=0,t2=0;
		for(i=1;i<=n;i+=2) t1+=p[i];
		for(i=2;i<=n;i+=2) t2+=p[i]; 
		for(i=1;i<=m;i++){
			cin>>a>>x>>b>>y;
			if(x==1&&y==1){
				if(a%2!=b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t1<<endl;
				else cout<<t2<<endl;
			}
			else if(x==0&&y==0){
				if(a%2!=b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t2<<endl;
				else cout<<t1<<endl;
			}else if(x==1){
				if(a%2==b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t1<<endl;
				else cout<<t2<<endl;
			}else{
				if(a%2==b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t2<<endl;
				else cout<<t1<<endl;
			}
		}
	}else{
		for(i=1;i<=n;i++){
			cin>>p[i];
		}
		for(i=1;i<n;i++){
			cin>>a>>b;
			link(a,b);
		}
		long long t1=0,t2=0;
		int la,lb;
		dep[1]=1;
		dfs(1,1);
		for(i=1;i<=n;i++){
			if(dep[i]%2) t1+=p[i];
			else t2+=p[i];
		}
		for(i=1;i<=m;i++){
			cin>>a>>x>>b>>y;
			a=dep[a],b=dep[b];
			if(x==1&&y==1){
				if(a%2!=b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t1<<endl;
				else cout<<t2<<endl;
			}
			else if(x==0&&y==0){
				if(a%2!=b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t2<<endl;
				else cout<<t1<<endl;
			}else if(x==1){
				if(a%2==b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t1<<endl;
				else cout<<t2<<endl;
			}else{
				if(a%2==b%2) cout<<"-1"<<endl;
				else if(a%2) cout<<t2<<endl;
				else cout<<t1<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
