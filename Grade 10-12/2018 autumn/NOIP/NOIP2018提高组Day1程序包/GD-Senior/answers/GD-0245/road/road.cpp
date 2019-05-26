#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n,d[200000],lazy[1000000],f[1000000],i,ans,id[1000000],min1;

void maketree(int x,int l,int r){
	if (l==r){
		f[x]=d[l];
		id[x]=l;
	}
	else{
		int mid=(l+r)/2;
		maketree(x*2,l,mid);
		maketree(x*2+1,mid+1,r);
		if (f[x*2]<f[x*2+1]){
			f[x]=f[x*2];
			id[x]=id[x*2];
		}
		else{
			f[x]=f[x*2+1];
			id[x]=id[x*2+1];	
		}
	}
}

void update(int x,int l,int r){
	if (l!=r){
		lazy[x*2]+=lazy[x];
		lazy[x*2+1]+=lazy[x];
	}
	f[x]+=lazy[x];
	lazy[x]=0;
}

int getmin(int x,int l,int r,int l1,int r1){
	update(x,l,r);
	if (l==l1&&r==r1){
		min1=min(min1,f[x]);
		return id[x];
	}
	else{
		int mid=(l+r)/2;
		update(x*2,l,mid);
		update(x*2+1,mid+1,r);
		if (mid<l1)
			return getmin(x*2+1,mid+1,r,l1,r1);
		if (mid>=r1)
			return getmin(x*2,l,mid,l1,r1);
		int x1=getmin(x*2,l,mid,l1,mid),x2=getmin(x*2+1,mid+1,r,mid+1,r1);
		if (d[x1]<d[x2])
			return x1;
		return x2;
	}
}

void change(int x,int l,int r,int l1,int r1,int k){
	update(x,l,r);
	if (l1<=l&&r1>=r)
		lazy[x]-=k;
	else{
		int mid=(l+r)/2;
		if (mid<l1)
			change(x*2+1,mid+1,r,l1,r1,k);
		else{
			if (mid>=r1)
				change(x*2,l,mid,l1,r1,k);
			else{
				change(x*2,l,mid,l1,mid,k);
				change(x*2+1,mid+1,r,mid+1,r1,k);
			}	
		}
		update(x*2,l,mid);
		update(x*2+1,mid+1,r);
		if (f[x*2]<f[x*2+1]){
			f[x]=f[x*2];
			id[x]=id[x*2];
		}
		else{
			f[x]=f[x*2+1];
			id[x]=id[x*2+1];
		}
	}
}

void dfs(int l,int r){
	if (l>r)
		return;
	min1=1e9;
	int minid=getmin(1,1,n,l,r);
	ans+=min1;
	change(1,1,n,l,r,min1);
	dfs(l,minid-1);
	dfs(minid+1,r);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&d[i]);
	memset(lazy,0,sizeof(lazy));
	maketree(1,1,n);
	ans=0;
	dfs(1,n);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
