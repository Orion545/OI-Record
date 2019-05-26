#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,p,k;
long long num[50100];
int fa[50100],dl[50100],h,t;
long long dp[50100];
long long l,r,mid,ans;
int u[100200],v[100200],w[100200];
int d[50100],b[100200];
bool mark[50100];
void sort(int ll,int rr){
	if (ll>=rr) return;
	int x,y,midd,q;
	x=ll; y=rr; midd=num[(x+y)/2];
	while (x<=y){
		while (num[x]>midd) x++;
		while (midd>num[y]) y--;
		if (x<=y){
			q=num[x]; num[x]=num[y]; num[y]=q;
			x++; y--;
	    }
    }
    if (x<rr) sort(x,rr);
    if (ll<y) sort(ll,y);
    return;
}
bool ask(long long need){
	int sum=0;
	for (int i=n;i>=1;i--){
		k=0;
		dp[dl[i]]=0;
		p=d[dl[i]];
		while (p!=-1){
			if (v[p]!=fa[dl[i]]){
				k++; mark[k]=0; 
				num[k]=dp[v[p]]+w[p]; 
			}
			p=b[p];
		}
		sort(1,k);
		int zl=1,zr=k;
		while (zl<=k && num[zl]>=need){
			sum++;
			if (sum>=m) return 1;
			zl++;
		}
		for (int j=k;j>zl;j--) if (!mark[j]){
			zr=j-1;
			while (mark[zr] || (zr>zl && num[zr]+num[j]<need)) zr--;
			if (num[zr]+num[j]>=need){
				sum++;
				mark[zr]=1; mark[j]=1;
				if (sum>=m) return 1;
				continue;
			}
		}
		while (zl<=k){
		    if (!mark[zl]){
			    dp[dl[i]]=num[zl]; break;
		    }
		    zl++;
	    }
	}
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	l=10000; r=0;
	for (int i=1;i<=n;i++){d[i]=-1; mark[i]=0;}
	for (int i=1;i<=n-1;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		if (w[i]<l) l=w[i]; 
		r+=w[i];
		u[i+n]=v[i]; v[i+n]=u[i]; w[i+n]=w[i];
		b[i]=d[u[i]]; d[u[i]]=i;
		b[i+n]=d[u[i+n]]; d[u[i+n]]=i+n;
	}
	r/=m;
	dl[1]=1; fa[1]=1; mark[1]=1;
	h=0; t=1;
	while (t<n){
		h++;
		p=d[dl[h]];
		while (p!=-1){
			if (!mark[v[p]]){
				t++; dl[t]=v[p]; 
				fa[v[p]]=dl[h]; mark[v[p]]=1;
			}
			p=b[p];
		}
	}
	ans=l;
	while (l<=r){
		if (ask(r)){ans=r; break;}
		mid=(l+r)/2;
		if (ask(mid)){
			ans=mid; l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	fclose(stdin);
    fclose(stdout);
	return 0;
}
