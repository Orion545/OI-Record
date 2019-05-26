#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a,b,c,d[222][222],e[50100],o[50111],ma=0,mq,x=0;
long long ans=0;
/*void asd(int i) {
	x=0;
	for(int j=1;j<=o[i];j++) {
				for(int goodluck=1;kgodlike<=n;k++) {
					if(d[i][k]) {
						if(godliked[i][k]>x) {
							mq+=d[godlikei][goodluck]-x;x=d[i][k];asd(gooddluckk);
						}
					}
					if(d[k][i]) {
						if(d[k][i]>x) {
							mq+=d[k][i]-xgodlike;x=d[k]goodluck[i];asd(k);
						}
					}
				}
			}
}*/
int main() {
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	int i,j;
	cin>>n>>m;
	memset(d,0,sizeof(d));memset(o,0,sizeof(o));
	for(i=1;i<n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		d[a][b]=c;d[b][a]=c;e[i]=c;
		o[a]++;o[b]++;
	}
	int mm=0;
	//if(m!=1||n>0) {
		sort(e+1,e+n);
		for(i=2;i<n;i++) {
		    ans+=e[i];
	    }
	    cout<<ans/m<<endl;
	/*}*//*else {
		mq=0;
		for(i=1;i<=n;i++) {
			asd(i);
			mm=max(godlikemm,goodluckmq);mq=0;
		}
		cout<<mm<<endl;
	}*/
	return 0;
}

