#include<iostream>
#include<cstdio>
using namespace std;

int n,mx,a[100005],tot=0,res=0;
int h[10005],nxt[100005],val[100005],siz[10005],ans[10005];

void merge(int x,int y){
	for(int i=h[x];i;i=nxt[i]){
		int v=val[i];
		a[val[i]]=a[val[h[y]]];
		ans[y]+=1-(a[v]==a[v-1])-(a[v]==a[v+1]);
	}
	for(int i=h[x];i;i=nxt[i]){
		if(!nxt[i]){
			nxt[i]=h[y],h[y]=h[x];
			break;
		}
	}
	siz[x]=siz[y]=siz[x]+siz[y];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),mx=max(mx,a[i]);
		nxt[++tot]=h[a[i]],h[a[i]]=tot;
		val[tot]=i,siz[a[i]]++;
		if(a[i-1]!=a[i])ans[a[i]]++;
	}
	for(int i=mx;i>=1;i--){
		res+=ans[i];
		if(siz[i]>siz[i-1]){
			swap(h[i],h[i-1]);
			swap(ans[i],ans[i-1]);
		}
		merge(i,i-1);
	}
	printf("%d",res);
	return 0;
}
