#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[5555],b[5555][111],s[5555],u,v,tot=0;
bool f[5555];
bool dsa(int x,bool as[5555]) {
	int i;as[x]=false;
	if(a[x]==1)return false;
	for(i=1;i<=a[x];i++) {
		if(as[b[x][i]]==true) {
			as[b[x][i]]=false;return dsa(b[x][i],as);
		}
	}
	return true;
}
void asd(int x,int q) {
	int i,j,mi=10000,o=0;bool ff=false,as[5555];
	for(i=1;i<=n;i++)as[i]=f[i];
	for(i=1;i<=a[x];i++) {
		if(f[b[x][i]]==true) {
			if(b[x][i]<mi) {
				mi=b[x][i];o=i;
				ff=true;
			}
		}
	}
	if(ff==false) {
		return;
	}bool fff=true;
	if(a[b[x][o]]>1)for(i=1;i<=a[b[x][o]];i++) {
		if(fff&&as[b[b[x][o]][i]])fff=dsa(b[b[x][o]][i],as);
		if(!fff)i=a[b[x][o]];
	}
	if(mi<=q||fff==false||a[b[x][o]]==1) {
		f[b[x][o]]=false;as[b[x][o]]=false;
	    tot++;s[tot]=b[x][o];
	    int ma=10000;
	    for(i=1;i<=a[x];i++) {
		if(f[b[x][i]]==true) {
			ma=min(ma,b[x][i]);
		}
	}
	    asd(b[x][o],ma);
	}else return;
	for(i=1;i<=a[x];i++) {
		if(f[b[x][i]]==true) {
			asd(x,10000);
		}
	}
	
}
int main() {
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	int i,j;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(f,true,sizeof(f));
	for(i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		a[u]++;a[v]++;
		b[u][a[u]]=v;b[v][a[v]]=u;
	}
	tot++;s[tot]=1;f[1]=false;
	asd(1,10000);
	for(i=1;i<n;i++) {
		cout<<s[i]<<' ';
	}
	cout<<s[n]<<endl;
}
