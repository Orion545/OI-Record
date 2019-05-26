#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
#define F(i,x,y) for(int i=x;i<=y;++i)

using namespace std;


int read(){
	int ret=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while((ch>='0'&&ch<='9')) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int n,m;
const int M=1000010;

int tot=0,to[M*2],las[M*2],nxt[M*2],val[M*2];
void Link(int x,int y,int z){
	to[++tot]=y;
	nxt[tot]=las[x];
	las[x]=tot;
	val[tot]=z;
}


long long ans=0,rt;
void dfs1(int u,int x,int s){
	if(ans<s) rt=u,ans=s;
	for(int j=las[u];j;j=nxt[j]){
		int v=to[j];
		if(v==x) continue;
		dfs1(v,u,s+val[j]);
	}
}

long long Z[M],X[M],Y[M];
bool pd1(){
	F(i,1,n-1) if(X[i]!=1&&Y[i]!=1) return false;
	return  true;
}

bool pd2(){
	F(i,1,n-1) if(X[i]+1!=Y[i]) return false;
	return true;
}

bool pd3(int x){
	
	int ac=0,s=0;
	F(i,1,n-1){
		for(int j=las[i];j;j=nxt[j]){
			if(to[j]!=i+1) continue;
			ac+=val[j];
			if(ac>=x) ac=0,s++;
		}
	}
	
	return s>=m;
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	F(i,1,n-1){
		X[i]=read(),Y[i]=read(),Z[i]=read();
		Link(X[i],Y[i],Z[i]),Link(Y[i],X[i],Z[i]);
	}

	if(m==1){
		dfs1(1,1,0);
		ans=0;
		dfs1(rt,rt,0);
		printf("%lld\n",ans);
		return 0;
	}
	else if(pd1()){
		sort(Z+1,Z+n);
		
		if(n%2==0){
			ans=Z[n-1];
			F(i,1,(n-1)/2){
				ans=min(ans,Z[i]+Z[n-1-i]);
			}
		}
		else{
			ans=Z[n-1]+Z[1];
			F(i,1,(n-1)/2){
				ans=min(ans,Z[i]+Z[n-i]);
			}
		}
		
		printf("%lld\n",ans);
		return 0;
	}
	
	if(pd2()){
		int L=0,R=500000010,mid;
		while(L<=R){
			mid=(L+R)>>1;
			if(pd3(mid)){
				ans=mid;
				L=mid+1;
			}
			else R=mid-1;
		}
		
		printf("%lld\n",ans);
		return 0;
	}

	return 0;
}
