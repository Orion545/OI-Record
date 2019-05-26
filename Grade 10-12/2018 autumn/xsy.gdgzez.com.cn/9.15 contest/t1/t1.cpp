#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define MOD 1000000007
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
ll qpow(ll a,ll b){
    ll re=1;
    while(b){
        if(b&1) re=re*a%MOD;
        a=a*a%MOD;b>>=1;
    }
    return re;
}
int n,link[60][60][3],m;
namespace MT{
	ll x[60][60],ch;
	ll MatrixTree(){
	    int i,j,k,num;ll tmp,inv,re=1;
	    n--;
//		for(i=1;i<=n;i++){
//		    for(j=1;j<=n;j++) cout<<x[i][j]<<' ';
//		    cout<<'\n';
//		}
	    for(i=1;i<=n;i++){
//	      	cout<<"	Do Gauss "<<i<<'\n';
	        if(!x[i][i]){
	            num=i+1;
	            while(!x[num][i]&&num<=n) num++;
	            if(num>n) continue;
	            for(j=1;j<=n;j++) swap(x[i][j],x[num][j]);
	            ch^=1;
	        }
//			cout<<"	begin\n";
	        inv=qpow(x[i][i],MOD-2);
//			cout<<"	get inv "<<inv<<'\n';
	        for(j=i+1;j<=n;j++){
	            if(!x[j][i]) continue;
	            tmp=x[j][i]*inv%MOD;
	            for(k=1;k<=n;k++) x[j][k]=(x[j][k]-x[i][k]*tmp%MOD+MOD)%MOD;
	        }
	    }
	    for(i=1;i<=n;i++) re=re*x[i][i]%MOD;
//	 	for(i=1;i<=n;i++){
//	 	 	for(j=1;j<=n;j++) cout<<x[i][j]<<' ';
//	    	cout<<'\n';
//		}
	    n++;
//		cout<<"Matrix tree "<<re<<'\n';
	    return re;
	}
	void init(int rr,int gg){
		int i,j,tmp;
		memset(x,0,sizeof(x));
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				tmp=(link[i][j][0]*rr+link[i][j][1]*gg+link[i][j][2])%MOD;
				x[i][j]=x[j][i]=(MOD-tmp)%MOD;
	 			x[i][i]+=tmp;x[j][j]+=tmp;
			}
	}
}
ll mt[60][60],T[60][60];
namespace Lag{
	void getval(int x,ll *re){
		ll d=1,i,j,inv=1;
		re[0]=1;
		for(i=1;i<=n;i++){
			if(i==x) continue;
			for(j=i-1-(i>=x);j>=0;j--){
				(re[j+1]+=re[j])%=MOD;
				(re[j]*=(MOD-i))%=MOD;
			}
			(inv*=(x-i+MOD))%=MOD;
		}
		inv=qpow(inv,MOD-2);
		for(i=0;i<n;i++) re[i]=(re[i]*inv)%MOD;
	}
}
int main(){
	n=read();m=read();
	int i,j,x,y;ll p[110],q[110];
	for(i=1;i<=m;i++){
		j=read();x=read();y=read();
		link[j][x][y-1]=link[x][j][y-1]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
//			cout<<"getMT "<<i<<' '<<j<<'\n';
			MT::init(i,j);
			mt[i][j]=MT::MatrixTree();
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			memset(p,0,sizeof(p));
			memset(q,0,sizeof(q));
			Lag::getval(i,p);
			Lag::getval(j,q);
			for(x=0;x<n;x++){
				for(y=0;y<n-x;y++){
					(T[x][y]+=mt[i][j]*p[x]%MOD*q[y]%MOD)%=MOD;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf("%lld\n",T[i][j]);
		}
	}
}
