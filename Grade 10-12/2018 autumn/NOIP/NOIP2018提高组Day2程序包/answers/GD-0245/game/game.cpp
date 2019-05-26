#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int n,m,i,j,num;
long long ans,mo,f[1000010];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	mo=1e9+7;
	f[1]=4;
	f[0]=0;
	for (j=2;j<=m+1;j++)
		f[j]=f[j-1]*3%mo;
	if (n==2){
		printf("%lld\n",f[m]);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if (n==3){
		printf("%lld\n",f[m+1]+f[m-2]);
		fclose(stdin);fclose(stdout);
		return 0;
	}	
	fclose(stdin);fclose(stdout);
	return 0;
}
