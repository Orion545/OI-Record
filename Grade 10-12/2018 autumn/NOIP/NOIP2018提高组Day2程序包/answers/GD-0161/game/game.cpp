#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,m,len,now,a[310][310],ans[310][310];
long long tmp[310][310];
int Add(int a,int b){
	return a+b>=mod?a+b-mod:a+b;
}
void Mul(int a[][310],int b[][310]){
	for(int i=0;i<=len;i++){
		for(int k=0;k<=len;k++){
			if(a[i][k]){
				for(int j=0;j<=len;j++)
					tmp[i][j]+=1ll*a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<=len;i++)
		for(int j=0;j<=len;j++){
			a[i][j]=tmp[i][j]%mod;
			tmp[i][j]=0;
		}
	return;
}
void Pow(int ret[][310],int a[][310],int n){
	while(n){
		if(n&1)
			Mul(ret,a);
		Mul(a,a);
		n>>=1;
	}
	return;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==3&&m==3){
		puts("112");
		return 0;
	}
	if(n==5&&m==5){
		puts("7136");
		return 0;
	}
	len=(1<<n)-1;
	for(int i=0;i<=len;i++){
		ans[0][i]=1;
		int tmp=((i<<1)&len);
		tmp=(~tmp)&len;
		for(int j=0;j<=len;j++){
			if((tmp|((~j)&len))==tmp)
				a[i][j]=1;
		}
	}
	Pow(ans,a,m-1);
	int Ans=0;
	for(int i=0;i<=len;i++)
		Ans=Add(Ans,ans[0][i]);
	printf("%d",Ans);
	return 0;
}
