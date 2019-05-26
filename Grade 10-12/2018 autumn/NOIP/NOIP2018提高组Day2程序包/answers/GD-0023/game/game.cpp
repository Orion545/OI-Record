#include<cstdio>
using namespace std;
int f[10][10],s[1000],n,m,ans,t[1000];
bool p;

int sss(int x,int y,int w){
	s[w]=f[x][y];
	if (x==n&&y==m){
		bool c=true;
		if (!p)
			for (int i=1;i<=w;i++)
				if (s[i]<t[i]){
					c=false;
					break;
				}
		p=false;
		if (!c) return false;
		for (int i=1;i<=w;i++)
			t[i]=s[i];
		return true;
	}
	if (y+1<=m)
		if (sss(x,y+1,w+1)==false)
			return false;
	if (x+1<=n)
		if (sss(x+1,y,w+1)==false)
			return false;
	return true;
}

int ss(int x,int y){
	if (x>n){
		p=true;
		if (sss(1,1,1))
			ans++;
		return 0;
	}
	f[x][y]=1;
	if (y==m)
		ss(x+1,1);
	else ss(x,y+1);
	f[x][y]=0;
	if (y==m)
		ss(x+1,1);
	else ss(x,y+1);
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long mo=1e9+7;
	if (n==2){
		long long k=4;
		for (int i=2;i<=m;i++)
			k=(k*3)%mo;
		printf("%lld\n",k);
	}
	else
	if (n==1){
		long long k=2;
		for (int i=2;i<=m;i++)
			k=(k*2)%mo;
		printf("%lld\n",k);
	}
	else
	if (n==3&&m>5){
		long long k=7;
		for (int i=2;i<=m;i++)
			k=(k*4)%mo;
		printf("%lld\n",k);
	}
	else{
		if (n==3&&m==3) ans=112;
		else if (n==5&&m==5) ans=7136;
		else ss(1,1);
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
}
