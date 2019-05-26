#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int le[1010][1010],ri[1010][1010],add[1010][1010],a[1010][1010];
ll rec[1010][1010],tri[1010][1010];
int n,Q,cnt=0,x[3010],y[3010],lim[3010];
void update(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			le[i][j]+=le[i-1][j];
			ri[i][j]+=ri[i-1][j-1];
			add[i][j]=add[i][j-1]+le[i][j]-ri[i][j];
			a[i][j]+=add[i][j];
			rec[i][j]=rec[i-1][j]+rec[i][j-1]-rec[i-1][j-1]+a[i][j];
			tri[i][j]=tri[i-1][j-1]+rec[i][j-1]-rec[i-1][j-1]+a[i][j];
		}
	}
	cnt=0;
	memset(le,0,sizeof(le));memset(ri,0,sizeof(ri));
}
int main(){
	n=read();Q=read();int t1,t2,t3,t4,tx,ty,tz,i;ll ans,tmp;
	while(Q--){
		t4=read();t1=read();t2=read();t3=read();
		if(t4==1){
			le[t1][t2]++;le[t1+t3][t2]--;
			ri[t1][t2+1]++;ri[t1+t3][t2+t3+1]--;
			cnt++;
			x[cnt]=t1;y[cnt]=t2;lim[cnt]=t3;
			if(cnt==2500) update();
		}
		else{
			ans=tri[t1+t3-1][t2+t3-1]-tri[t1-1][t2-1]-rec[t1+t3-1][t2-1]+rec[t1-1][t2-1];
			for(i=1;i<=cnt;i++){
				tx=min(t1+t3,x[i]+lim[i]);
				ty=max(t1-t2,x[i]-y[i]);
				tz=max(t2,y[i]);
//				cout<<tx<<' '<<ty<<' '<<tz<<'\n';
				tmp=tx-ty-tz;
				if(tmp>0) ans+=1ll*tmp*(tmp+1ll)/2ll;
			}
			printf("%lld\n",ans);
		}
	}
}
/*
3 9
2 1 1 2
1 1 1 2
2 1 1 2
1 2 1 2
2 1 1 2
2 2 2 2
1 2 2 2
2 1 1 2
2 1 1 3

*/
