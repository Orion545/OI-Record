#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll mul[70][210][210],now[210][210],s[210][210],base[210][210],tmp[210][210];
ll n,m,lim,tot,flag;
void multi(ll a[][210],ll b[][210],ll c[][210]){
	ll i,j,k;flag=1;
	memset(tmp,0,sizeof(tmp));
	for(i=1;i<=tot;i++){
		for(k=1;k<=tot;k++){
			if(!a[i][k]) continue;
			for(j=1;j<=tot;j++) tmp[i][j]+=a[i][k]*b[k][j];
			if(i==1&&tmp[1][tot]>=lim) flag=0; 
		}
	}
	for(i=1;i<=tot;i++) for(j=1;j<=tot;j++) c[i][j]=tmp[i][j];
/*
	for(i=1;i<=tot;i++){
		for(j=1;j<=tot;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	for(i=1;i<=tot;i++){
		for(j=1;j<=tot;j++) cout<<b[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	for(i=1;i<=tot;i++){
		for(j=1;j<=tot;j++) cout<<c[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
*/
}
int main(){
	n=read();m=read();lim=read();ll i,t1,t2,t3,ans=0;
//	cout<<"READ IN "<<n<<' '<<m<<' '<<lim<<'\n';
	tot=n*3+1;
	for(i=1;i<=n;i++){
		s[1][i]=1;
		base[i][i+n]=1;
		base[i+n][i+(n<<1)]=1;
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		base[t1+(t3-1)*n][t2]++;
		base[t1+(t3-1)*n][tot]++;
	}
	base[tot][tot]=1;
	memcpy(mul[0],base,sizeof(base));
	for(i=0;i<=63;i++){
//		cout<<"try "<<i<<'\n';
		if(i) multi(mul[i-1],mul[i-1],mul[i]);
		multi(s,mul[i],now);
		if(!flag||now[1][tot]>=lim) break;
	}
	i--;
	if(i==63&&now[1][tot]<lim){
		puts("-1");return 0;
	}
//	cout<<i<<' '<<now[1][tot]<<'\n';
	for(;i>=0;i--){
		multi(s,mul[i],now);
		if(flag&&now[1][tot]<lim){
			ans|=(1ll<<i);
			memcpy(s,now,sizeof(now));
		}
	}
	cout<<ans+1<<'\n';
}
