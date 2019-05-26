#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll f[10010][2][2],t[10010],len;char s[10010];
ll solve(ll m){
	ll n=m/2,i,j,k,t1,t2,num,tmp,sum,mid,re=0;
	for(i=0;i<=n;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) f[i][j][k]=0;
	f[0][0][0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				if(f[i][j][k]==0) continue;
				for(num=0;num<10;num++){
					sum=num+t[i+1]+k;
					tmp=sum%10;t2=sum/10;
					t1=(j*10+num)-(tmp+t[m-i]);
//					cout<<"try "<<num<<'\n';
					if(t1<0||t1>1) continue;
					if(i==0&&(num==0||tmp==0)) continue;
//					cout<<"***suc "<<num<<' '<<t1<<' '<<t2<<' '<<tmp<<'\n';
					add(f[i+1][t1][t2],f[i][j][k]);
				}
//				cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
			}
		}
	}
	if(m&1){
		mid=n+1;
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				if(!f[n][j][k]) continue;
				for(num=0;num<10;num++){
					sum=t[mid]+num+k;
					if(sum%10==num&&sum/10==j) add(re,f[n][j][k]);
				}
			}
		}
	}
	else{
		for(j=0;j<2;j++) add(re,f[n][j][j]);
	}
	return re;
}
int main(){
	ll i,ans=0;scanf("%s",s);len=strlen(s);
	for(i=1;i<=len;i++) t[i]=s[len-i]-'0';
	for(i=len;i<=(len*2);i++) add(ans,solve(i));
	cout<<ans<<'\n';
}
