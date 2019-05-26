#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define next nlasjdl

using namespace std;

int a[50001],b[50001],l[50001],head[4001],w[4001],next[4001],v[4001],tot=0,maxn=0,sum=0;
bool p=false,check[4001];

void add(int x,int y,int z){
	v[++tot]=y;
	w[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}

void dfs(int x){
	for(int i=head[x];i!=-1;i=next[i]){
		if(check[v[i]])continue;
		check[v[i]]=true;
		sum+=w[i];
		maxn=max(maxn,sum);
		dfs(v[i]);
		sum-=w[i];
		check[v[i]]=false;
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(check,false,sizeof(check));
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&l[i]);
		add(a[i],b[i],l[i]);
		add(b[i],a[i],l[i]);
		if(a[i]!=1)p=true;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			check[i]=true;
			dfs(i);
			check[i]=false;
		}
		printf("%d",maxn);
		return 0;
	}
	if(!p){
		sort(l+1,l+n);
		int k=m*2-n+1,minn=2147483647,_k;
		if(k>0){
			if((n-k-1)%2==0)minn=l[n-k],_k=n-k;
			else minn=l[n-k-1],_k=n-k-1;
			for(int i=1;i<=(n-1-k)/2;i++)minn=min(minn,l[i]+l[_k-i]);
		}
		else{
			for(int i=(n-1)-m*2+1;i<=(n-1)-m+1;i++){
				minn=min(minn,l[i]+l[n-i]);
			}
		}
		printf("%d",minn);
		return 0;
	}
	return 0;
}
