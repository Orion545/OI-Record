#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int ap[20005],a[20005],al[20005],an=0;
int to[20005],tn=1,vt[20005];
int s[20005],sn=0,p,pn;
bool vis[20005],tt=0;
int v1,v2;

void add(int x,int y){
	an++; a[an]=y; al[an]=ap[x]; ap[x]=an;
	an++; a[an]=x; al[an]=ap[y]; ap[y]=an;
}

void csh(){
	vt[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=ap[i];j;j=al[j]) to[tn++]=a[j];
		vt[i]=tn;
		sort(to+vt[i-1],to+vt[i]);
		//for(int j=vt[i-1];j<vt[i];j++) cout<<to[j]<<" ";cout<<endl;
	}
}

void dfs1(int x,int fa){
	cout<<x<<" ";
	for(int j=vt[x-1];j<vt[x];j++) 
	if(to[j]!=fa) dfs1(to[j],x);
}

void findo(int x,int fa){
	if(tt) return;
	if(vis[x]){
		tt=true;
		p=sn; pn=sn;
		while(s[p]!=x) p--;
		return;
	}
	s[++sn]=x; vis[x]=true;
	for(int j=vt[x-1];j<vt[x]&&tt==0;j++) 
	if(to[j]!=fa) findo(to[j],x);
	sn--;
}

void dfs2(int x,int fa){
	cout<<x<<" ";
	for(int j=vt[x-1];j<vt[x];j++) 
	if(to[j]!=fa&&to[j]!=0) dfs2(to[j],x);
}

void work2(){
	findo(1,0);
	for(int i=p+1;i<=pn;i++){
		if(s[pn]<=s[i]){
			v1=s[i-1]; v2=s[i]; break;
		}
	}
	for(int j=vt[v1-1];j<vt[v1];j++) if(to[j]==v2) to[j]=0;
	for(int j=vt[v2-1];j<vt[v2];j++) if(to[j]==v1) to[j]=0;
	dfs2(1,0);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y);
	}
	
	csh();
	
	if(n-1==m) dfs1(1,0);
	if(n==m)   work2();
	return 0;
}
