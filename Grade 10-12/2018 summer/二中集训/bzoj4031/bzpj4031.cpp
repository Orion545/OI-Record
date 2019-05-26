#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000000
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
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
int n,m,cnt,num[10][10],ok[10][10],ch,deg[110];
ll a[110][110];
void add(int l,int r){
	deg[l]++;
	a[l][r]=-1;
} 
void Gauss(){
	int i,j,k,num;ll tmp;
	for(i=1;i<=cnt;i++){
		num=i;
		for(j=i+1;j<=cnt;j++){
			if(abs(a[j][i])>abs(a[num][i])) num=j;
		}
		if(num!=i){
			ch^=1;
			for(j=1;j<=cnt;j++) swap(a[num][j],a[i][j]);
		}
		for(j=i+1;j<=cnt;j++){
			while(a[j][i]){
				tmp=a[j][i]/a[i][i];
				for(k=1;k<=cnt;k++){
					a[j][k]=(a[j][k]-tmp*a[i][k]%MOD+MOD)%MOD;
				}
				if(a[j][i]==0) break;
				ch^=1;
				for(k=1;k<=cnt;k++) swap(a[j][k],a[i][k]);
			}
		}
	}
}
int main(){
	n=read();m=read();int i,j,k,ti,tj;char s[10];ll ans=1;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++) if(s[j]=='.') ok[i][j+1]=1,num[i][j+1]=++cnt;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!ok[i][j]) continue;
			for(k=1;k<=4;k++){
				ti=i+dx[k];tj=j+dy[k];
				if(ok[ti][tj]) add(num[i][j],num[ti][tj]);
			}
		}
	}
	for(i=1;i<=cnt;i++) a[i][i]=deg[i];//finish constructing the Kirchhoff Matrix
	cnt--;//delete the last row and column of the Kirchhoff Matrix
	Gauss();//Using Gauss to change the matrix into a upper-left triangle matirx
	for(i=1;i<=cnt;i++) ans=(ans*a[i][i])%MOD;
	//the value of the Determinant now equals the product of elements on the diagonal line
	//other elements above of the diagnal line will be multiplied by 0-values below the diagnal line
	if(ch) ans=MOD-ans;//if odd times of exchanges were done in the Gauss process, ans multiplies -1
	ans=(MOD+ans)%MOD; 
	printf("%lld\n",ans);
}

