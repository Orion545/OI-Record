#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,p[100008],u,v,f[100008],g[100008],a,x,b,y;
string S_t;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>S_t;
	if(S_t=="A2"){
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		f[0]=0;
		f[1]=p[1];
		for(int i=2;i<=n;i++){
			f[i]=min(f[i-2]+p[i],f[i-1]+p[i]);
		}
		g[n+1]=0;
		g[n]=p[n];
		for(int i=n-1;i>=1;i--){
			g[i]=min(g[i+1]+p[i],g[i+2]+p[i]);
		}
		for(int i=1;i<=m;i++){
			cin>>a>>x>>b>>y;
			if(b<a){
				int tmp1=a;
				int tmp2=x;
				a=b;
				b=tmp1;
				x=y;
				y=tmp2;
			}
			if(x==0&&y==0){
				cout<<-1<<endl;
			}else if(x==1&&y==1){
				cout<<f[a]+g[b]<<endl;
			}else if(x==0&&y==1){
				cout<<f[a-1]+g[b]<<endl;
			}else if(x==1&&y==0){
				cout<<f[a]+g[b+1]<<endl;
			}
		}
	}
	return 0;
}
