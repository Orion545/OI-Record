#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int M=1e6+5;
const int S=(1<<8)+5;
const int P=1e9+7;

int n,m,s;
int f[M][S];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	s=(1<<n);
	memset(f,0,sizeof(f));
	for (int i=0;i<s;i++){
		f[1][i]=1;
	}
	for (int i=2;i<=m;i++){
		for (int s1=0;s1<s;s1++){
			int ss=(s1<<1)&(s-1);
			for (int s2=0;s2<s;s2++){
				if ((s2&ss)==ss) f[i][s2]=(long long)(f[i][s2]+f[i-1][s1])%P;
			}
		}
	}
	int ans=0;
	for (int i=0;i<s;i++){
		ans=(long long)(ans+f[m][i])%P;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
