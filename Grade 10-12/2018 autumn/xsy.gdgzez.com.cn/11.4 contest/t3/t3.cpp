/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,a[100010][5];
namespace brute{
	bool win[100010];
	int maxn[5];
	void solve(){
		win[1]=1;
		int i,j,k,ans;
		printf("1");
		for(k=0;k<m;k++) maxn[k]=a[1][k];
		for(i=2;i<=n;i++){
			bool f=0;
			for(j=1;j<i;j++){
				if(!win[j]) continue;
//				cout<<"try "<<j<<' '<<i<<' '<<a[i][0]<<' '<<a[j][0]<<'\n';
				for(k=0;k<m;k++) if(a[i][k]>a[j][k]){f=1;break;}
				if(f) break;
			}
//			cout<<"get "<<f<<'\n';
			if(f) win[i]=1;
			f=0;
			for(k=0;k<m;k++) if(maxn[k]>a[i][k]){f=1;break;}
			if(!f) for(j=1;j<i;j++) win[j]=0;
			if(win[i]){
				for(j=1;j<i;j++){
					if(win[j]) continue;
					f=0;
					for(k=0;k<m;k++) if(a[j][k]>a[i][k]){f=1;break;}
					if(f) win[j]=1;
				}
			}
//			for(j=1;j<=i;j++) cout<<j<<' '<<win[j]<<'\n';
			for(k=0;k<m;k++) maxn[k]=max(maxn[k],a[i][k]);
			ans=0;
			for(j=1;j<=i;j++) ans+=win[j];
			printf(" %d",ans);
		}
		puts("");
	}
}
namespace kone{
	void solve(){
		for(int i=1;i<=n;i++) printf("1 ");
	}
}
int main(){
//	freopen("s.in","r",stdin);
//	freopen("s.out","w",stdout);
cout<<"begin\n";
	n=read();m=read();int i,k;
	for(i=1;i<=n;i++){
		for(k=0;k<m;k++) a[i][k]=read();
	}
	if(m==1) kone::solve();
	else brute::solve();
}
/*
5 2
1 4
2 3
3 2
4 1
5 5

*/
