#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int r,c,n,m,d,cnt,a[410][410],pos[410];
void solve(int ll,int lr,int rl,int rr){
	int lenl=lr-ll+1,lenr=rr-rl+1,i,j;
//	cout<<"solve "<<ll<<' '<<lr<<' '<<rl<<' '<<rr<<'\n';
	if(lenl<=0&&lenr<=0) return;
	if(lenl>=d){
		for(i=rl;i<=rr;i++){
			cnt++;
			for(j=0;j<d;j++) a[ll+j][i]=cnt;
		}
		solve(ll+d,lr,rl,rr);
	}
	else if(lenr>=d){
		for(i=ll;i<=lr;i++){
			cnt++;
			for(j=0;j<d;j++) a[i][rl+j]=cnt;
		}
		solve(ll,lr,rl+d,rr);
	}
	else{
		if(lenl<lenr){
			for(i=ll;i<=lr;i++){
				cnt++;
				for(j=rl;j<=rr;j++) a[i][j]=cnt;
			}
		}
		else{
			for(i=rl;i<=rr;i++){
				cnt++;
				for(j=ll;j<=lr;j++) a[j][i]=cnt;
			}
		}
	}
}
void addon(int n,int m){
	int k=(n*(m-d)-1)/d+1,i,j;
	pos[1]=1;
	for(i=2;i<=k;i++) pos[i]=((pos[i-1]+d-1)%n+1);
	sort(pos+1,pos+k+1);
	for(i=1;i<=k;i++){
		cnt++;
		for(j=0;j<d;j++){
			a[(pos[i]+j+n-1)%n+1][i]=cnt;
		}
	}
	for(i=1;i<=n;i++){
		cnt++;
		for(j=1;j<=m;j++){
			if(!a[i][j]) a[i][j]=cnt;
		}
	}
}
int main(){
	int T=read(),i,j;
	while(T--){
		r=read();c=read();d=read();
		cnt=0;
		memset(a,0,sizeof(a));
		solve(1,r,1,c);
		if(r>=d&&c>=d&&cnt>(r*c-1)/d+1){
			n=r%d+d;
			m=c%d+d;
			cnt=0;
			memset(a,0,sizeof(a));
			solve(n+1,r,1,c);
			solve(1,n,m+1,c);
			addon(n,m);
		}
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				printf("%d ",a[i][j]);
			}
			putchar('\n');
		}
	}
}
