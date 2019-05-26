#include<cstdio>
#include<iostream>
using namespace std;
int n,m,now;
int u[10200],v[10200],d[5200],b[10200],a[5200];
int h[5200],t[5200],fa[5200];
bool mark[5200];
int num[10200],sum;
int ans[5200],ansn;
void sort(int l,int r){
	if (l>=r) return;
	int p=l,q=r,mid,w;
	mid=num[(p+q)/2];
	while (p<=q){
		while (num[p]<mid) p++;
		while (mid<num[q]) q--;
		if (p<=q){
			w=num[p]; num[p]=num[q]; num[q]=w;
			p++; q--;
		}
	}
	if (p<r) sort(p,r);
	if (l<q) sort(l,q);
	return;
}
void dfs1(int x){
	if (h[x]==0){
    	h[x]=sum+1;
    	int y=d[x];
    	while (y!=-1){
	    		sum++; num[sum]=v[y];
	    		y=b[y];
	    	}
	    t[x]=sum;
	    sort(h[x],t[x]);
    }
	for (int k=h[x];k<=t[x];k++){
		if (num[k]==fa[x]) continue;
		if (fa[num[k]]==0 || num[k]>x){
			fa[num[k]]=x; 
			dfs1(num[k]);
		}
	}
	return;
}
void dfs2(int x){
	if (mark[x]) return;
	mark[x]=1; ansn++; ans[ansn]=x;
	for (int k=h[x];k<=t[x];k++) 
	    if (num[k]!=fa[x] && fa[num[k]]==x) dfs2(num[k]); 
}
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
	    d[i]=-1; mark[i]=0; h[i]=0; t[i]=0; fa[i]=0;
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		u[i+m]=v[i]; v[i+m]=u[i];
		b[i]=d[u[i]]; d[u[i]]=i;
		b[i+m]=d[u[i+m]]; d[u[i+m]]=i+m;
	}
	sum=0; ansn=0; fa[1]=1;
    dfs1(1);
    dfs2(1);
	printf("%d",ans[1]);
	for (int i=2;i<=n;i++) printf(" %d",ans[i]);
	printf("\n");
	fclose(stdin);
    fclose(stdout);
	return 0;
}
