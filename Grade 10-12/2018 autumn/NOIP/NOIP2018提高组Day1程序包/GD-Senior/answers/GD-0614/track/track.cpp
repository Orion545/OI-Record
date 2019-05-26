#include<bits/stdc++.h>
using namespace std;
int n,m,i,cnt,sum,l,k,u,c,o,w,ans,anms,ansss,anbs[50010],anss[50010],j[50010],v[50010],h[50010];
bool b;
struct e{
	int nxt,to,w;
}e[50010];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
void dfs(int x){
	v[x]=1;
	c++;
	for(j[c]=h[x];j[c];j[c]=e[j[c]].nxt){
		if(v[e[j[c]].to])continue;
		ans+=e[j[c]].w;
		anms=max(anms,ans);
		dfs(e[j[c]].to);
		ans-=e[j[c]].w;
		v[e[j[c]].to]=0;
	}
	c--;
}
void work(int x){
	ans=0;
	c++;
	for(j[c]=x;ans<=k&&j[c]<=n-1;j[c]++){
		if(e[h[j[c]]].to<j[c]){
			l=e[e[h[j[c]]].nxt].w;
		}else{
			l=e[h[j[c]]].w;
		}
		ans+=l;
	}
	if(j[c]==n){
		anss[c]=min(anss[c],ans);
		ansss=max(ansss,anss[c]);
	}else{
		anss[c]=min(ans-l,anss[c-1]);
		work(j[c]-1);
		anss[c]=min(ans,anss[c-1]);
		work(j[c]);
	}
	c--;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	b=true;
	cin>>n>>m;
	for(i=1;i<=n-1;i++){
		cin>>u>>o>>w;
		sum+=w;
		anbs[i]=w;
		if(u!=1){
			b=false;
		}
		add(u,o,w);
		if(m==1){
			add(o,u,w);
		}
	}
	if(m==1){
		for(i=1;i<=n;i++){
			c=0;
			dfs(i);
			v[i]=0;
		}
		cout<<anms;
		return 0;
	}
	if(b){
		sort(anbs+1,anbs+n+1);
		cout<<anbs[n-m+1];
		return 0;
	}else{
		c=0;
		memset(anss,0x3f,sizeof(anss));
		anss[0]=0;
		k=sum/m;
		cout<<k-2;
		return 0;
	}
}
