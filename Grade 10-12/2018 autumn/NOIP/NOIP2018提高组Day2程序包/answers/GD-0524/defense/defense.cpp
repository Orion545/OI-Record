#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,b[100001][33],t[100001],ans=0,p[100001];
char a[11];
bool f[100001],ff[100001];
int main() {
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	int i,j;
	cin>>n>>m>>a;
	memset(t,0,sizeof(t));	
	for(i=1;i<=n;i++)cin>>p[i];
	for(i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		t[u]++;t[v]++;
		b[u][t[u]]=v;b[v][t[v]]=u;
	}
	while(m--) {
		int c=0,d=0;
		memset(f,false,sizeof(f));
		memset(ff,false,sizeof(ff));
		int q,w,e,r;ans=0;
		scanf("%d%d%d%d",&q,&w,&e,&r);
		if(w==0&&r==0) {
			for(i=1;i<=t[q];i++){
				if(b[q][i]==e) {
					cout<<"-1"<<endl;i=t[q];c=-1;
				}
			}
		}
		if(c!=-1) {
			if(w==1) {
				f[q]=true,ans+=p[q];ff[q]=true;
				for(i=1;i<=a[q];i++)ff[b[q][i]]=true;
			}if(r==1) {
				f[e]=true;ans+=p[e];ff[e]=true;
				for(i=1;i<=a[e];i++)ff[b[e][i]]=true;
			}
			if(w==0) {
				d=q;
				int o=0,mi=1000000;bool fg=true;
				for(i=1;i<=t[q];i++) {
					if(f[b[q][i]]==true)fg=false;else {
						if(p[b[q][i]]<mi) {mi=p[b[q][i]];o=i;}}
				}
				if(fg) {f[b[q][o]]=true;ff[q]=true;ans+=p[b[q][o]];for(i=1;i<=a[b[q][o]];i++)ff[b[q][i]]=true;}
			}
			if(r==0) {
				c=e;
				int o=0,mi=1000000;bool fg=true;
				for(i=1;i<=t[e];i++) {
					if(f[b[e][i]]==true)fg=false;else {
						if(p[b[e][i]]<mi) {mi=p[b[e][i]];o=i;}}
				}
				if(fg) {f[b[e][o]]=true;ff[e]=true;ans+=p[b[e][o]];for(i=1;i<=a[b[e][o]];i++)ff[b[e][i]]=true;}
			}
			for(i=1;i<=n;i++) {
				if(ff[i]==false) {
					int mi=1000000,o=0;
					for(j=1;j<=a[i];j++) {
						if(p[b[i][j]]<mi&&b[i][j]!=c&&b[i][j]!=d) {
							o=j;mi=p[b[i][j]];
						}
					}
					if((mi>p[i]&&i!=c&&i!=d)||o==c||o==d) {
						f[i]=true;ans+=p[i];
						for(j=1;j<=a[i];j++)ff[j]=true;
					}else {
						f[b[i][o]]=true;ans+=p[b[i][o]];
						for(j=1;j<=a[b[i][o]];j++)ff[j]=true;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}


